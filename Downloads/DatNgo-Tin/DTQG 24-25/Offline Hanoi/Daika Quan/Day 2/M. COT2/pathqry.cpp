#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define fo(i, n) for (i = 0; i < n; i++)

const int N = 100011, M = 100011;

int BLOCK;

struct node
{
    int l, r, i, sp, ans;
} Q[M];

int lvl[N], p[N][16], st[N], en[N], id[2 * N], occ[N], ans, w[N];
map<int, int> HASH;
int cnt[N];
vi g[N];
int ti;

bool f(node a, node b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l < b.l;
    return a.r < b.r;
}

bool gg(node a, node b)
{
    return a.i < b.i;
}

void dfs(int u, int p)
{

    st[u] = ++ti;
    id[ti] = u;
    int v;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        lvl[v] = lvl[u] + 1;
        ::p[v][0] = u;
        dfs(v, u);
    }
    en[u] = ++ti;
    id[ti] = u;
}

int lca(int u, int v)
{
    int lg, i;
    for (lg = 0; (1 << lg) <= lvl[u]; lg++)
        ;
    lg--;
    for (i = lg; i >= 0; i--)
        if (lvl[u] - (1 << i) >= lvl[v])
            u = p[u][i];
    if (u == v)
        return u;
    for (i = lg; i >= 0; i--)
    {
        if (p[u][i] != -1 && p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    }
    return p[u][0];
}

void add(int node)
{
    occ[node]++;
    cnt[w[node]]++;
    if (occ[node] == 2)
    {
        cnt[w[node]] -= 2;
        if (cnt[w[node]] == 0)
            ans--;
    }
    else if (cnt[w[node]] == 1)

        ans++;
}
void del(int node)
{
    int wt = w[node];
    occ[node]--;

    if (occ[node] == 1)
    {
        cnt[wt]++;
        if (cnt[wt] == 1)
            ans++;
        return;
    }
    cnt[wt]--;
    if (cnt[wt] == 0)
        ans--;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, i, j, u, v;
    ans = ti = 0;
    cin >> n >> m;
    BLOCK = sqrt(n);
    int no = 0;
    HASH.clear();
    fo(i, n)
    {
        cin >> w[i + 1];
        if (HASH.find(w[i + 1]) == HASH.end())
            HASH[w[i + 1]] = ++no;
        w[i + 1] = HASH[w[i + 1]];
    }
    fo(i, n - 1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    lvl[1] = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(occ, 0, sizeof(occ));
    memset(p, -1, sizeof(p));
    dfs(1, 0);
    for (i = 1; i < 16; i++)
        for (j = 1; j <= n; j++)
            if (p[j][i - 1] != -1)
                p[j][i] = p[p[j][i - 1]][i - 1];
    fo(i, m)
    {
        Q[i].i = i;
        Q[i].sp = -1;
        cin >> u >> v;
        if (lvl[u] < lvl[v])
            swap(u, v);
        int w = lca(u, v);
        if (w == v)
        {
            Q[i].l = st[v];
            Q[i].r = st[u] + 1;
        }
        else
        {
            if (st[v] > en[u])
            {
                Q[i].l = en[u];
                Q[i].r = st[v] + 1;
            }
            else
            {
                Q[i].l = en[v];
                Q[i].r = st[u] + 1;
            }
            Q[i].sp = w;
        }
    }
    sort(Q, Q + m, f);
    int currL = 0, currR = 0, L, R;
    fo(i, m)
    {
        L = Q[i].l, R = Q[i].r;
        while (currL < L)
        {

            del(id[currL]);
            currL++;
        }
        while (currL > L)
        {
            add(id[currL - 1]);
            currL--;
        }
        while (currR < R)
        {
            add(id[currR]);
            currR++;
        }
        while (currR > R)
        {
            del(id[currR - 1]);
            currR--;
        }
        Q[i].ans = ans;
        if (Q[i].sp != -1)
        {
            if (cnt[w[Q[i].sp]] == 0)
                Q[i].ans = ans + 1;
        }
    }
    sort(Q, Q + m, gg);
    fo(i, m)
            cout
        << Q[i].ans << endl;

    return 0;
}