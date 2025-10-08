#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> sz;
    UnionFind(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_set(int x)
    {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y, int &global_max_size)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx == fy)
            return;
        // Union by size
        if (sz[fx] < sz[fy])
        {
            parent[fx] = fy;
            sz[fy] += sz[fx];
            if (sz[fy] > global_max_size)
            {
                global_max_size = sz[fy];
            }
        }
        else
        {
            parent[fy] = fx;
            sz[fx] += sz[fy];
            if (sz[fx] > global_max_size)
            {
                global_max_size = sz[fx];
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> unique_p;
    for (int i = 1; i <= n; i++)
        unique_p.push_back(p[i]);
    sort(unique_p.begin(), unique_p.end(), greater<int>());
    unique_p.erase(unique(unique_p.begin(), unique_p.end()), unique_p.end());
    int num_p = unique_p.size();
    vector<vector<int>> groups(num_p, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        int idx = lower_bound(unique_p.begin(), unique_p.end(), p[i], greater<int>()) - unique_p.begin();
        groups[idx].push_back(i);
    }
    UnionFind uf(n);
    vector<bool> active(n + 1, false);
    int global_max_size = 0;
    vector<long long> max_size_p(num_p, 0);
    for (int i = 0; i < num_p; i++)
    {
        for (auto node : groups[i])
        {
            active[node] = true;
            for (auto neighbor : adj[node])
            {
                if (active[neighbor])
                {
                    uf.union_set(node, neighbor, global_max_size);
                }
            }
            int root = uf.find_set(node);
            if (uf.sz[root] > global_max_size)
            {
                global_max_size = uf.sz[root];
            }
        }
        max_size_p[i] = global_max_size;
    }
    vector<long long> res(n + 1, -1);
    int next_k = 1;
    for (int i = 0; i < num_p; i++)
    {
        if (next_k > n)
            break;
        int size = max_size_p[i];
        if (next_k > size)
            continue;
        int end_k = min(size, n);
        for (int k = next_k; k <= end_k; k++)
        {
            res[k] = unique_p[i];
        }
        next_k = end_k + 1;
    }

    for (int k = 1; k <= n; k++)
        cout << res[k] << (k < n ? " " : "\n");
}
