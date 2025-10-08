#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> graph[100010];
int tin[100010], low[100010];

bool visited[100010];

vector<pair<int, int>> bridges;

int timer = 0;
void dfs(int u, int p = -1)
{
    timer++;
    tin[u] = low[u] = timer;
    visited[u] = 1;

    for (int v : graph[u])
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

vector<int> tree[100010];
void find_bridge()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    for (auto &[u, v] : bridges)
    {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

int sz[100010];
void dfs_count(int u, int p = -1)
{
    sz[u] = 1;
    visited[u] = 1;

    for (int v : tree[u])
        if (v != p)
        {
            dfs_count(v, u);
            sz[u] += sz[v];
        }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    find_bridge();
    memset(visited, 0, sizeof visited);

    auto nC2 = [](int x)
    { return x * (x - 1) / 2; };

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs_count(i);
            int k = sz[i];

            ans += nC2(k) - (k - 1);
        }
    }

    cout << ans;
    return 0;
}