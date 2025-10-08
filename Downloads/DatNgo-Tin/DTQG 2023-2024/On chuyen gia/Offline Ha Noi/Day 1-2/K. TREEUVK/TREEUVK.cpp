#include <bits/stdc++.h>

#define ii pair<int, int>
using namespace std;
struct CUSTOM_TYPE
{
    int v, val;
    CUSTOM_TYPE(int _v, int _val)
    {
        v = _v, val = _val;
    }
};

int n, q, d[100010], h[100010], f[100010][30], maxLog2;
pair<ii, int> queries[100010];
ii parent[100010];
vector<CUSTOM_TYPE> graph[100010];
void dfs(int s, int par)
{
    f[s][0] = par;
    h[s] = h[par] + 1;
    for (int i = 1; i <= maxLog2; i++)
    {
        f[s][i] = f[f[s][i - 1]][i - 1];
    }
    for (CUSTOM_TYPE x : graph[s])
    {
        int v = x.v, value = x.val;
        if (v == par)
            continue;
        d[v] = d[s] + value;
        parent[v] = {s, value};
        dfs(v, s);
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    for (int i = maxLog2; i >= 0; --i)
    {
        if (h[f[u][i]] >= h[v])
            u = f[u][i];
    }
    if (u == v)
        return u;
    for (int i = maxLog2; i >= 0; --i)
    {
        if (f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    maxLog2 = log2(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v, value;
        cin >> u >> v >> value;
        graph[u].push_back(CUSTOM_TYPE(v, value));
        graph[v].push_back(CUSTOM_TYPE(u, value));
    }
    dfs(1, 0);
    for (int i = 1; i <= q; ++i)
    {
        int u, v, k;
        cin >> u >> v >> k;
        int par = lca(u, v);
        int res = 0;
        while (u != par)
        {
            if (parent[u].second <= k)
                res ^= parent[u].second;
            u = parent[u].first;
        }
        while (v != par)
        {
            if (parent[v].second <= k)
                res ^= parent[v].second;
            v = parent[v].first;
        }
        cout << res << endl;
    }
    return 0;
}
