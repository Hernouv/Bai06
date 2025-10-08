#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

int n, q;
int val[nmax];
vector<int> graph[nmax];
int parent[nmax];
int h[nmax];
int subtree_sz[nmax];

void dfs(int u, int par)
{
    subtree_sz[u] = 1;
    for (int v : graph[u])
    {
        if (v != par)
        {
            parent[v] = u;
            h[v] = h[u] + 1;
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

int ChainHead[nmax], ChainID[nmax], ArrHLD[nmax], PosInArrHLD[nmax];
int CurrChain = 1, CurrPos = 1;

void hld(int u, int par)
{
    if (!ChainHead[CurrChain])
        ChainHead[CurrChain] = u;
    ChainID[u] = CurrChain;
    ArrHLD[CurrPos] = u;
    PosInArrHLD[u] = CurrPos;
    ++CurrPos;

    int next = 0;
    for (int v : graph[u])
        if (v != par)
            if (!next or subtree_sz[v] > subtree_sz[next])
                next = v;
    if (next)
        hld(next, u);
    for (int v : graph[u])
        if (v != par and v != next)
        {
            ++CurrChain;
            hld(v, u);
        }
}

int lca(int a, int b)
{
    while (ChainID[a] != ChainID[b])
    {
        if (ChainID[a] > ChainID[b])
            a = parent[ChainHead[ChainID[a]]];
        else
            b = parent[ChainHead[ChainID[b]]];
    }
    if (h[a] < h[b])
        return a;
    else
        return b;
}

int segTree[nmax * 4];

void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        segTree[id] = val[ArrHLD[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

void update(int pos, int va, int id = 1, int l = 1, int r = n)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id] = va;
        return;
    }
    int mid = (l + r) / 2;
    update(pos, va, id * 2, l, mid);
    update(pos, va, id * 2 + 1, mid + 1, r);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

int getMax(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (l > R or r < L)
        return -1;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return max(getMax(L, R, id * 2, l, mid), getMax(L, R, id * 2 + 1, mid + 1, r));
}

int getMaxOnPath(int u, int root)
{
    int ret = -1;
    while (u != root)
    {
        if (ChainHead[ChainID[u]] == u)
        {
            maximize(ret, val[u]);
            u = parent[u];
        }
        else if (h[ChainHead[ChainID[u]]] > h[root])
        {
            maximize(ret, getMax(PosInArrHLD[ChainHead[ChainID[u]]], PosInArrHLD[u]));
            u = parent[ChainHead[ChainID[u]]];
        }
        else
        {
            maximize(ret, getMax(PosInArrHLD[root], PosInArrHLD[u]));
            break;
        }
    }
    return ret;
}

void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    hld(1, 0);
    construct();

    int query_type, qp, qv, qx, qy;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> qp >> qv;
            update(PosInArrHLD[qp], qv);
            val[qp] = qv;
        }
        else
        {
            cin >> qx >> qy;
            int common_par = lca(qx, qy);
            cout << max({getMaxOnPath(qx, common_par), getMaxOnPath(qy, common_par), val[common_par]}) << ' ';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}