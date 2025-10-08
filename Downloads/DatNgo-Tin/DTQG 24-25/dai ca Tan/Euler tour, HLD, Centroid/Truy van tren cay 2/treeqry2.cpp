#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int a, b, c;
};

struct SegmentTreeNode
{
    int max_val;
    int min_val;
    bool flip;
    SegmentTreeNode() : max_val(INT32_MIN), min_val(INT32_MAX), flip(false) {}
};

class HLD_SegmentTree
{
public:
    int N;
    vector<vector<pair<int, int>>> adj;
    vector<int> parent_node, depth_node, size_node;
    vector<int> heavy_child, head_node, pos_in_seg;
    vector<SegmentTreeNode> segtree;
    vector<int> arr;
    int current_pos;

    // Constructor
    HLD_SegmentTree(int size)
    {
        N = size;
        adj.resize(N + 1, vector<pair<int, int>>());
        parent_node.resize(N + 1, -1);
        depth_node.resize(N + 1, 0);
        size_node.resize(N + 1, 1);
        heavy_child.resize(N + 1, -1);
        head_node.resize(N + 1, 0);
        pos_in_seg.resize(N + 1, 0);
        arr.resize(N + 1, 0);
        current_pos = 1;
        segtree.resize(4 * (N + 1));
    }

    void add_edge(int a, int b, int edge_id)
    {
        adj[a].emplace_back(b, edge_id);
        adj[b].emplace_back(a, edge_id);
    }

    int dfs(int v, int p)
    {
        parent_node[v] = p;
        size_node[v] = 1;
        int max_size = 0;
        heavy_child[v] = -1;
        for (auto &[to, eid] : adj[v])
        {
            if (to != p)
            {
                depth_node[to] = depth_node[v] + 1;
                int sz = dfs(to, v);
                size_node[v] += sz;
                if (sz > max_size)
                {
                    max_size = sz;
                    heavy_child[v] = to;
                }
            }
        }
        return size_node[v];
    }

    void decompose(int v, int h)
    {
        head_node[v] = h;
        pos_in_seg[v] = current_pos;
        current_pos++;
        if (heavy_child[v] != -1)
        {
            decompose(heavy_child[v], h);
            for (auto &[to, eid] : adj[v])
            {
                if (to != parent_node[v] && to != heavy_child[v])
                {
                    decompose(to, to);
                }
            }
        }
    }

    void build_segment_tree(int node, int l, int r)
    {
        if (l == r)
        {
            segtree[node].max_val = arr[l];
            segtree[node].min_val = arr[l];
            segtree[node].flip = false;
            return;
        }
        int mid = (l + r) / 2;
        build_segment_tree(2 * node, l, mid);
        build_segment_tree(2 * node + 1, mid + 1, r);
        segtree[node].max_val = max(segtree[2 * node].max_val, segtree[2 * node + 1].max_val);
        segtree[node].min_val = min(segtree[2 * node].min_val, segtree[2 * node + 1].min_val);
        segtree[node].flip = false;
    }

    void push_down(int node, int l, int r)
    {
        if (segtree[node].flip)
        {
            int mid = (l + r) / 2;
            flip_segment(2 * node, l, mid);
            flip_segment(2 * node + 1, mid + 1, r);
            segtree[node].flip = false;
        }
    }

    void flip_segment(int node, int l, int r)
    {
        segtree[node].flip ^= 1;
        swap(segtree[node].max_val, segtree[node].min_val);
        segtree[node].max_val = -segtree[node].max_val;
        segtree[node].min_val = -segtree[node].min_val;
    }

    void update_range(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr)
        {
            flip_segment(node, l, r);
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        update_range(2 * node, l, mid, ql, qr);
        update_range(2 * node + 1, mid + 1, r, ql, qr);
        segtree[node].max_val = max(segtree[2 * node].max_val, segtree[2 * node + 1].max_val);
        segtree[node].min_val = min(segtree[2 * node].min_val, segtree[2 * node + 1].min_val);
    }

    void update_point(int node, int l, int r, int idx, int value)
    {
        if (l == r)
        {
            segtree[node].max_val = value;
            segtree[node].min_val = value;
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (idx <= mid)
            update_point(2 * node, l, mid, idx, value);
        else
            update_point(2 * node + 1, mid + 1, r, idx, value);
        segtree[node].max_val = max(segtree[2 * node].max_val, segtree[2 * node + 1].max_val);
        segtree[node].min_val = min(segtree[2 * node].min_val, segtree[2 * node + 1].min_val);
    }

    int query_max(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return INT32_MIN;
        if (ql <= l && r <= qr)
        {
            return segtree[node].max_val;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        return max(query_max(2 * node, l, mid, ql, qr), query_max(2 * node + 1, mid + 1, r, ql, qr));
    }

    int query_path(int a, int b)
    {
        int res = INT32_MIN;
        while (head_node[a] != head_node[b])
        {
            if (depth_node[head_node[a]] > depth_node[head_node[b]])
            {
                swap(a, b);
            }
            res = max(res, query_max(1, 1, N, pos_in_seg[head_node[b]], pos_in_seg[b]));
            b = parent_node[head_node[b]];
        }
        if (a == b)
        {
            return res;
        }
        if (depth_node[a] > depth_node[b])
        {
            swap(a, b);
        }
        res = max(res, query_max(1, 1, N, pos_in_seg[a] + 1, pos_in_seg[b]));
        return res;
    }

    void negate_path(int a, int b)
    {
        while (head_node[a] != head_node[b])
        {
            if (depth_node[head_node[a]] > depth_node[head_node[b]])
            {
                swap(a, b);
            }
            update_range(1, 1, N, pos_in_seg[head_node[b]], pos_in_seg[b]);
            b = parent_node[head_node[b]];
        }
        if (a == b)
        {
            return;
        }
        if (depth_node[a] > depth_node[b])
        {
            swap(a, b);
        }
        update_range(1, 1, N, pos_in_seg[a] + 1, pos_in_seg[b]);
    }

    void initialize(vector<Edge> &edges)
    {
        dfs(1, -1);
        decompose(1, 1);
        for (auto &edge : edges)
        {
            int a = edge.a;
            int b = edge.b;
            int c = edge.c;
            if (parent_node[a] == b)
            {
                arr[pos_in_seg[a]] = edge.c;
            }
            else
            {
                arr[pos_in_seg[b]] = edge.c;
            }
        }
        build_segment_tree(1, 1, N);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin, s);
        int N;
        cin >> N;
        vector<Edge> edges(N - 1);
        for (int i = 0; i < N - 1; i++)
            cin >> edges[i].a >> edges[i].b >> edges[i].c;
        HLD_SegmentTree hld(N);
        for (int i = 0; i < N - 1; i++)
            hld.add_edge(edges[i].a, edges[i].b, i + 1);
        hld.initialize(edges);

        while (true)
        {
            string cmd;
            cin >> cmd;
            if (cmd == "DONE")
                break;
            if (cmd == "QUERY")
            {
                int a, b;
                cin >> a >> b;
                if (a == b)
                {
                    cout << "0\n";
                    continue;
                }
                int res = hld.query_path(a, b);
                cout << res << "\n";
            }
            else if (cmd == "CHANGE")
            {
                int i, v;
                cin >> i >> v;
                int a = edges[i - 1].a;
                int b = edges[i - 1].b;
                int child;
                if (hld.parent_node[a] == b)
                {
                    child = a;
                }
                else
                {
                    child = b;
                }
                hld.update_point(1, 1, hld.N, hld.pos_in_seg[child], v);
            }
            else if (cmd == "NEGATE")
            {
                int a, b;
                cin >> a >> b;
                if (a != b)
                {
                    hld.negate_path(a, b);
                }
            }
        }
    }
}
