#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
int n, q, val[nmax];
int parent[nmax];
int h[nmax];
int subtree_sz[nmax];
vector<int> graph[nmax];

int chain_head[nmax], chain_id[nmax], arr_hld[nmax], pos[nmax];
int curr_chain, curr_pos;

int segTree[nmax * 4];

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

void hld(int u, int par)
{
    if (!chain_head[curr_chain])
        chain_head[curr_chain] = u;

    chain_id[u] = curr_chain;
    pos[u] = curr_pos;
    arr_hld[curr_pos++] = u;

    int next = 0;
    for (int v : graph[u])
    {
        if (v != par)
            if (!next or subtree_sz[v] > subtree_sz[next])
                next = v;
    }

    if (next)
        hld(next, u);

    for (int v : graph[u])
    {
        if (v != par and v != next)
        {
            ++curr_chain;
            hld(v, u);
        }
    }
}

int lca(int a, int b)
{
    if (chain_id[a] != chain_id[b])
    {
        if (chain_id[a] > chain_id[b])
            a = parent[chain_head[chain_id[a]]];
        else
            b = parent[chain_head[chain_id[b]]];
    }
    if (h[a] < h[b])
        return a;
    return b;
}

void construct(int id, int l, int r)
{
    if (l == r)
    {
        segTree[id] = val[arr_hld[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] ^ segTree[id * 2 + 1];
}

void update(int id, int l, int r, int p, int val)
{
    if (r < p or l > p)
        return;
    if (l == r)
    {
        segTree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, val);
    update(id * 2 + 1, mid + 1, r, p, val);
    segTree[id] = segTree[id * 2] ^ segTree[id * 2 + 1];
}

int cal(int id, int l, int r, int L, int R)
{
    if (r < L or l > R)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return cal(id * 2, l, mid, L, R) ^ cal(id * 2 + 1, mid + 1, r, L, R);
}

int xorsum(int L, int R)
{
    int ret = 0;
    int common_par = lca(L, R);

    while (chain_id[L] != chain_id[common_par])
    {
        ret ^= cal(1, 1, n, pos[chain_head[chain_id[L]]], pos[L]);
        L = parent[chain_head[chain_id[L]]];
    }
    while (chain_id[R] != chain_id[common_par])
    {
        ret ^= cal(1, 1, n, pos[chain_head[chain_id[R]]], pos[R]);
        R = parent[chain_head[chain_id[R]]];
    }

    if (h[L] < h[R])
        ret ^= cal(1, 1, n, pos[L], pos[R]);
    else
        ret ^= cal(1, 1, n, pos[R], pos[L]);

    return ret;
}

void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    curr_pos = curr_chain = 1;
    h[1] = 1;
    dfs(1, 0);
    hld(1, 0);
    construct(1, 1, n);

    int query_type, p, val, L, R;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> p >> val;
            update(1, 1, n, pos[p], val);
        }
        else
        {
            cin >> L >> R;
            cout << xorsum(L, R) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("cowland.inp", "r"))
    {
        freopen("cowland.inp", "r", stdin);
        freopen("cowland.out", "w", stdout);
    }
    not_main();
    return 0;
}