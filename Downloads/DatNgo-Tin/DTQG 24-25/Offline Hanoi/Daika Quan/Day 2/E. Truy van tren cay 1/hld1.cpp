#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 2e5 + 10;

int n, q;
int a[nmax];
vector<int> g[nmax];
int subtree_sz[nmax];
int parent[nmax];

void dfs(int par, int u)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        parent[v] = u;
        dfs(u, v);
        subtree_sz[u] += subtree_sz[v];
    }
}

int chainhead[nmax], chainid[nmax], poshld[nmax];
ll arrhld[nmax];
int curchain = 1, curpos = 1;

void hld(int par, int u)
{
    chainid[u] = curchain;
    if (!chainhead[curchain])
        chainhead[curchain] = u;
    arrhld[curpos] = u;
    poshld[u] = curpos;
    ++curpos;

    int next = 0;
    for (int v : g[u])
    {
        if (v == par)
            continue;
        if (!next or subtree_sz[v] > subtree_sz[next])
            next = v;
    }
    if (next)
        hld(u, next);
    for (int v : g[u])
    {
        if (v != par and v != next)
        {
            ++curchain;
            hld(u, v);
        }
    }
}

ll segtree[4 * nmax];
void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        segtree[id] = a[arrhld[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

void update(int pos, ll val, int id = 1, int l = 1, int r = n)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segtree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(pos, val, id * 2, l, mid);
    update(pos, val, id * 2 + 1, mid + 1, r);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

ll getVal(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (r < L or l > R)
        return 0;
    if (L <= l and r <= R)
        return segtree[id];
    int mid = (l + r) / 2;
    return 1LL * getVal(L, R, id * 2, l, mid) + getVal(L, R, id * 2 + 1, mid + 1, r);
}

void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        g[tu].push_back(tv);
        g[tv].push_back(tu);
    }

    for (int i = 1; i <= n; ++i)
        subtree_sz[i] = 1;
    dfs(0, 1);
    hld(0, 1);
    construct();

    int rqtype, u;
    ll x;
    for (int i = 1; i <= q; ++i)
    {
        cin >> rqtype;
        if (rqtype == 1)
        {
            cin >> u >> x;
            update(poshld[u], x);
        }
        else
        {
            cin >> u;
            cout << getVal(poshld[u], poshld[u] + subtree_sz[u] - 1) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}