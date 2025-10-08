#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 2e5 + 10;

int n, q;
ll val[nmax];
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

ll segTree[nmax * 4];

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
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
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
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

ll getSum(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (l > R or r < L)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(L, R, id * 2, l, mid) + getSum(L, R, id * 2 + 1, mid + 1, r);
}

ll getSumOnPath(int u, int root)
{
    ll ret = 0;
    while (u != root)
    {
        if (ChainHead[ChainID[u]] == u)
        {
            ret += val[u];
            u = parent[u];
        }
        else if (h[ChainHead[ChainID[u]]] > h[root])
        {
            ret += getSum(PosInArrHLD[ChainHead[ChainID[u]]], PosInArrHLD[u]);
            u = parent[ChainHead[ChainID[u]]];
        }
        else
        {
            ret += getSum(PosInArrHLD[root], PosInArrHLD[u]);
            break;
        }
    }
    if (u == root)
        ret += val[root];
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

    int query_type, qp, qv;
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
            cin >> qp;
            cout << getSumOnPath(qp, 1) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}