#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 2e5 + 10;

int n, q;
vector<ill> g[nmax];
struct edge
{
    int u, v;
    ll w;
};
vector<edge> edges;
int subtree_sz[nmax];
int parent[nmax];
ll dist[nmax];
int h[nmax];

void dfs(int par, int u)
{
    for (ill v : g[u])
    {
        if (v.fi == par)
            continue;
        parent[v.fi] = u;
        h[v.fi] = h[u] + 1;
        dist[v.fi] = dist[u] + v.se;
        dfs(u, v.fi);
        subtree_sz[u] += subtree_sz[v.fi];
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
    for (ill v : g[u])
    {
        if (v.fi == par)
            continue;
        if (!next or subtree_sz[v.fi] > subtree_sz[next])
            next = v.fi;
    }
    if (next)
        hld(u, next);
    for (ill v : g[u])
    {
        if (v.fi != par and v.fi != next)
        {
            ++curchain;
            hld(u, v.fi);
        }
    }
}

ll segtree[4 * nmax], lazy[4 * nmax];
void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        segtree[id] = dist[arrhld[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

void lazy_upd(int id, int l, int r)
{
    if (!lazy[id])
        return;
    segtree[id] += lazy[id];
    if (l != r)
    {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int L, int R, ll val, int id = 1, int l = 1, int r = n)
{
    lazy_upd(id, l, r);
    if (r < L or l > R)
        return;
    if (L <= l and r <= R)
    {
        lazy[id] += val;
        lazy_upd(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(L, R, val, id * 2, l, mid);
    update(L, R, val, id * 2 + 1, mid + 1, r);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

ll getVal(int pos, int id = 1, int l = 1, int r = n)
{
    lazy_upd(id, l, r);
    if (r < pos or l > pos)
        return 0;
    if (l == r)
        return segtree[id];
    int mid = (l + r) / 2;
    return 1LL * getVal(pos, id * 2, l, mid) + getVal(pos, id * 2 + 1, mid + 1, r);
}

int lca(int u, int v)
{
    while (chainid[u] != chainid[v])
    {
        if (chainid[u] > chainid[v])
            u = parent[chainhead[chainid[u]]];
        else
            v = parent[chainhead[chainid[v]]];
    }
    if (h[u] < h[v])
        return u;
    return v;
}

void not_main()
{
    cin >> n >> q;

    int tu, tv;
    ll tw;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv >> tw;
        edges.push_back({tu, tv, tw});
        g[tu].push_back({tv, tw});
        g[tv].push_back({tu, tw});
    }

    for (int i = 1; i <= n; ++i)
        subtree_sz[i] = 1;
    dfs(0, 1);
    hld(0, 1);
    construct();

    int rqtype, u, v;
    ll x;
    for (int i = 1; i <= q; ++i)
    {
        cin >> rqtype;
        if (rqtype == 1)
        {
            cin >> u >> x;
            int pt;
            if (h[edges[u - 1].u] > h[edges[u - 1].v])
                pt = edges[u - 1].u;
            else
                pt = edges[u - 1].v;
            update(poshld[pt], poshld[pt] + subtree_sz[pt] - 1, x - edges[u - 1].w);
            edges[u - 1].w = x;
        }
        else
        {
            cin >> u >> v;
            int commonp = lca(u, v);
            ll du = getVal(poshld[u]);
            ll dv = getVal(poshld[v]);
            ll dp = getVal(poshld[commonp]);
            cout << du + dv - 2 * dp << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}