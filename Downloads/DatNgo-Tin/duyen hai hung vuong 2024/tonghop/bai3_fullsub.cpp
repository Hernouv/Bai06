#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;
int s, d;
int val[nmax];
int parent[nmax];
vector<int> graph[nmax];

struct node
{
    int type;
    int vertex;
    int value;
};
vector<node> queries;

void dfs(int st)
{
    for (int v : graph[st])
    {
        val[v] += val[st];
        dfs(v);
    }
}

void proc_type1(int pre, int st, int t_val)
{
    for (int v : graph[st])
        if (v != pre)
            val[v] -= t_val;
    if (st != 1)
        proc_type1(st, parent[st], t_val);
}

int subtree_sz[nmax], h[nmax];
void dfs_hld(int st)
{
    subtree_sz[st] = 1;
    for (int v : graph[st])
    {
        h[v] = h[st] + 1;
        dfs_hld(v);
        subtree_sz[st] += subtree_sz[v];
    }
}

int ChainHead[nmax], ChainID[nmax], ArrHLD[nmax], PosInArrHLD[nmax];
int CurChain = 1, CurPos = 0;

void hld(int st)
{
    if (!ChainHead[CurChain])
        ChainHead[CurChain] = st;
    ChainID[st] = CurChain;
    ArrHLD[++CurPos] = st;
    PosInArrHLD[st] = CurPos;

    int next = 0;
    for (int v : graph[st])
        if (!next or subtree_sz[v] > subtree_sz[next])
            next = v;
    if (next)
        hld(next);
    for (int v : graph[st])
        if (v != next)
        {
            ++CurChain;
            hld(v);
        }
}

int segTree[4 * nmax], lazyTree[4 * nmax];

void construct(int id = 1, int l = 1, int r = s)
{
    if (l == r)
    {
        segTree[id] = val[ArrHLD[l]];
        return;
    }

    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
}

void lazy(int id)
{
    int incr = lazyTree[id];
    lazyTree[id] = 0;
    lazyTree[id * 2] += incr;
    lazyTree[id * 2 + 1] += incr;
}

void update(int L, int R, int t_val, int id = 1, int l = 1, int r = s)
{
    if (l > R or r < L)
        return;
    if (L <= l and r <= R)
    {
        lazyTree[id] += t_val;
        return;
    }

    lazy(id);
    int mid = (l + r) / 2;
    update(L, R, t_val, id * 2, l, mid);
    update(L, R, t_val, id * 2 + 1, mid + 1, r);
}

void update_hld(int st, int t_val)
{
    while (st)
    {
        if (ChainHead[ChainID[st]] == st)
        {
            update(PosInArrHLD[st], PosInArrHLD[st], t_val);
            st = parent[st];
        }
        else if (h[ChainHead[ChainID[st]]] > h[1])
        {
            update(PosInArrHLD[ChainHead[ChainID[st]]], PosInArrHLD[st], t_val);
            st = parent[ChainHead[ChainID[st]]];
        }
        else if (h[ChainHead[ChainID[st]]] == h[1])
        {
            update(PosInArrHLD[1], PosInArrHLD[st], t_val);
            st = 0;
        }
    }
}

void update_all(int id = 1, int l = 1, int r = s)
{
    if (l == r)
    {
        val[ArrHLD[l]] += lazyTree[id];
        return;
    }
    lazy(id);
    int mid = (l + r) / 2;
    update_all(id * 2, l, mid);
    update_all(id * 2 + 1, mid + 1, r);
}

void not_main()
{
    cin >> s >> d;
    int p;
    for (int i = 2; i <= s; ++i)
    {
        cin >> p;
        parent[i] = p;
        graph[p].push_back(i);
    }

    int q_type, t_u, k;
    for (int i = 1; i <= d; ++i)
    {
        cin >> q_type >> t_u >> k;
        if (q_type == 2)
            val[t_u] += k;
        else if (q_type == 1)
        {
            queries.push_back({q_type, t_u, k});
        }
    }

    dfs(1);

    dfs_hld(1);
    hld(1);
    construct();
    for (node x : queries)
        update_hld(x.vertex, x.value);
    update_all();

    for (int i = 1; i <= s; ++i)
        cout << val[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GROWING.INP", "r"))
    {
        freopen("GROWING.INP", "r", stdin);
        freopen("GROWING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
