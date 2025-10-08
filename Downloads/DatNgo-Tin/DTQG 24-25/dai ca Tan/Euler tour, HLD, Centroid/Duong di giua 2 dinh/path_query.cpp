#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5 + 5;

struct segTree
{
    int n;
    vector<ll> tree;

    segTree(int size)
    {
        n = size;
        tree.assign(4 * n, 0LL);
    }

    void update(int idx, ll val, int node = 1, int l = 1, int r = -1)
    {
        if (r == -1)
            r = n;
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int L, int R, int node = 1, int l = 1, int r = -1)
    {
        if (r == -1)
            r = n;
        if (R < l || L > r)
            return 0;
        if (L <= l && r <= R)
            return tree[node];
        int mid = (l + r) / 2;
        return query(L, R, 2 * node, l, mid) + query(L, R, 2 * node + 1, mid + 1, r);
    }
};

int parent_node[MAX], depth_node[MAX], heavy[MAX], head[MAX], pos[MAX];
int cur_pos = 1;
ll edge_weight[MAX];
int n;
vector<pair<int, pair<int, ll>>> adj[MAX]; // node -> (neighbor, edge index, weight)
int edge_to_child[MAX];

int dfs(int v, int p)
{
    parent_node[v] = p;
    depth_node[v] = depth_node[p] + 1;
    int size = 1;
    int max_size = 0;
    heavy[v] = -1;
    for (auto &[u, edge_info] : adj[v])
    {
        int edge_idx = edge_info.first;
        ll w = edge_info.second;
        if (u != p)
        {
            edge_to_child[edge_idx] = u;
            edge_weight[u] = w;
            int sz = dfs(u, v);
            size += sz;
            if (sz > max_size)
            {
                max_size = sz;
                heavy[v] = u;
            }
        }
    }
    return size;
}

void decompose(int v, int h, segTree &st)
{
    head[v] = h;
    pos[v] = cur_pos++;
    if (heavy[v] != -1)
    {
        decompose(heavy[v], h, st);
        for (auto &[u, edge_info] : adj[v])
        {
            if (u != parent_node[v] && u != heavy[v])
            {
                decompose(u, u, st);
            }
        }
    }
}

ll query_path(int a, int b, segTree &st)
{
    ll res = 0;
    while (head[a] != head[b])
    {
        if (depth_node[head[a]] > depth_node[head[b]])
        {
            swap(a, b);
        }
        res += st.query(pos[head[b]], pos[b]);
        b = parent_node[head[b]];
    }
    if (depth_node[a] > depth_node[b])
    {
        swap(a, b);
    }
    res += st.query(pos[a] + 1, pos[b]);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, make_pair(i, w));
        adj[v].emplace_back(u, make_pair(i, w));
    }

    dfs(1, 0);
    segTree st(n);
    decompose(1, 1, st);

    for (int i = 1; i <= n - 1; ++i)
    {
        int child = edge_to_child[i];
        st.update(pos[child], edge_weight[child]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            ll y;
            cin >> x >> y;
            int child = edge_to_child[x];
            st.update(pos[child], y);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b, st) << "\n";
        }
    }
}
