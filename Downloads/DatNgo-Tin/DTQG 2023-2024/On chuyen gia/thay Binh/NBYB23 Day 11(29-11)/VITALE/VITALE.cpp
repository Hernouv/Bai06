#include <bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int, int>;

#define all(v) v.begin(), v.end()
#define create_unique(vec) \
    sort(all(vec));        \
    vec.resize(unique(all(vec)) - vec.begin());

struct Brigdes
{
    int n;
    int timer;
    vector<vector<int>> g;
    vector<int> tin, low;
    vector<bool> visited;

    vector<ii> bridges;

    Brigdes(int n, const vector<vector<int>> &g) : n(n), g(g), timer(0), tin(n + 1), low(n + 1), visited(n + 1, 0) {}

    void dfs(int u, int p = -1)
    {
        timer++;
        tin[u] = low[u] = timer;
        visited[u] = 1;

        for (int v : g[u])
        {
            if (v == p)
                continue;

            if (visited[v])
            {
                low[u] = min(low[u], tin[v]);
            }
            else
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (tin[u] < low[v])
                {
                    bridges.push_back({u, v});
                }
            }
        }
    }

    vector<ii> find_bridge()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        for (auto &[u, v] : bridges)
            if (u > v)
                swap(u, v);
        return bridges;
    }
};

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge &x, const Edge &y)
    {
        return x.w < y.w;
    }
};

struct DSU
{
    vector<int> root, sz;
    int connected;

    DSU(int _n) : root(_n + 1), sz(_n + 1)
    {
        connected = _n;
        for (int i = 1; i <= _n; i++)
        {
            sz[i] = 1;
            root[i] = i;
        }
    }

    int get_root(int u)
    {
        if (u == root[u])
            return u;
        return root[u] = get_root(root[u]);
    }

    bool unite(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u == v)
            return false;

        if (sz[u] < sz[v])
            swap(u, v);
        connected--;
        sz[u] += sz[v];
        root[v] = u;
        return true;
    }

    bool same_component(int u, int v)
    {
        return get_root(u) == get_root(v);
    }

    int get_size(int u)
    {
        return sz[get_root(u)];
    }
};

void not_main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> E_tmp;
    vector<int> compress_tmp;

    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v)
            swap(u, v);

        E_tmp.push_back({u, v, w});
        compress_tmp.push_back(w);
    }

    create_unique(compress_tmp);
    vector<vector<ii>> E(compress_tmp.size() + 1);

    for (auto &[u, v, w] : E_tmp)
    {
        w = lower_bound(all(compress_tmp), w) - compress_tmp.begin() + 1;
        E[w].push_back({u, v});
    }

    vector<ii> ans;

    DSU dsu(n);
    for (int i = 1; i <= compress_tmp.size(); ++i)
    {
        vector<vector<int>> g;
        map<ii, ii> mp;

        vector<int> points;
        for (auto &[u, v] : E[i])
        {
            int root_u = dsu.get_root(u);
            int root_v = dsu.get_root(v);

            points.push_back(root_u);
            points.push_back(root_v);
        }

        create_unique(points);
        g.resize(points.size() + 1);

        for (auto &[u, v] : E[i])
        {
            int root_u = dsu.get_root(u), root_v = dsu.get_root(v);
            root_u = lower_bound(all(points), root_u) - points.begin() + 1;
            root_v = lower_bound(all(points), root_v) - points.begin() + 1;

            g[root_u].push_back(root_v);
            g[root_v].push_back(root_u);

            if (root_u > root_v)
                swap(root_u, root_v);
            mp[{root_u, root_v}] = {u, v};
        }

        Brigdes bri(points.size(), g);
        auto res = bri.find_bridge();

        auto check = [&](ii &e)
        {
            const auto &[u, v] = e;
            return count(all(g[u]), v) <= 1;
        };

        for (auto &e : res)
            if (check(e))
                ans.push_back(mp[e]);

        for (auto &[u, v] : E[i])
            dsu.unite(u, v);
    }

    create_unique(ans);

    cout << ans.size() << endl;
    for (auto &[u, v] : ans)
        cout << u << " " << v << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}