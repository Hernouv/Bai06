#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

int n, q;
vector<int> ed[nmax];
vector<int> tr[nmax];
vector<int> ch[nmax];
bool stt[nmax];
int vid[nmax], vps[nmax], top[nmax];
int sub[nmax], light[nmax], csz[nmax];

void update(int id, int i, int f, int t, int p, bool v)
{
    if (f == t)
    {
        tr[id][i] = v * p;
    }
    else
    {
        int m = (f + t) >> 1;
        int l = i << 1;
        int r = i << 1 | 1;
        if (p < m + 1)
            update(id, l, f, m, p, v);
        else
            update(id, r, m + 1, t, p, v);
        if (tr[id][l] > 0)
            tr[id][i] = tr[id][l];
        else
            tr[id][i] = tr[id][r];
    }
}

int query(int id, int i, int f, int t, int p)
{
    if (t <= p)
    {
        return tr[id][i];
    }
    else
    {
        int m = (f + t) >> 1;
        int l = i << 1;
        int r = i << 1 | 1;
        if (p < m + 1)
            return query(id, l, f, m, p);
        int v = query(id, l, f, m, p);
        if (v > 0)
            return v;
        return query(id, r, m + 1, t, p);
    }
}

int dfs(int u, int p)
{
    sub[u] = 1;
    int best = 0;
    for (int i = 0; i < int(ed[u].size()); ++i)
    {
        int v = ed[u][i];
        if (v == p)
            continue;
        int sz = dfs(v, u);
        sub[u] += sz;
        if (sz > best)
        {
            best = sz;
            light[u] = v;
        }
    }
    return sub[u];
}

void dfs(int u, int p, int t, int ci, int cp, int &cn)
{
    ++csz[ci];
    top[u] = t;
    vid[u] = ci;
    vps[u] = cp;
    ch[ci].push_back(u);
    for (int i = 0; i < int(ed[u].size()); ++i)
    {
        int v = ed[u][i];
        if (v == p)
            continue;
        if (v == light[u])
        {
            dfs(v, u, t, ci, cp + 1, cn);
        }
        else
        {
            ++cn;
            ch[cn].push_back(0);
            dfs(v, u, u, cn, 1, cn);
        }
    }
}

int cid[30];
int cps[30];

int Query(int u)
{
    int sz = 0;
    for (int i = u; i; i = top[i])
    {
        ++sz;
        cid[sz] = vid[i];
        cps[sz] = vps[i];
    }
    for (int i = sz; i; --i)
    {
        int id = cid[i];
        int ps = cps[i];
        int v = query(id, 1, 1, csz[id], ps);
        if (v)
            return ch[id][v];
    }
    return -1;
}

void not_main()
{
    cin >> n >> q;
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    dfs(1, 0);

    int cn = 1;
    ch[1].push_back(0);
    dfs(1, 0, 0, 1, 1, cn);
    for (int i = 1; i <= cn; ++i)
        tr[i].resize(csz[i] * 4 + 1);

    for (int k, u; q--;)
    {
        cin >> k >> u;
        if (k == 0)
        {
            stt[u] ^= 1;
            update(vid[u], 1, 1, csz[vid[u]], vps[u], stt[u]);
        }
        else
            cout << Query(u) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}