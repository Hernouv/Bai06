#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

bool bfs(int n, int m, vector<vector<int>> &adj, vector<int> &pair_u, vector<int> &pair_v, vector<int> &dist)
{
    queue<int> q;
    for (int u = 1; u <= n; u++)
    {
        if (pair_u[u] == 0)
        {
            dist[u] = 0;
            q.push(u);
        }
        else
        {
            dist[u] = INF;
        }
    }
    dist[0] = INF;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u != 0)
        {
            for (auto &v : adj[u])
            {
                if (dist[pair_v[v]] == INF)
                {
                    dist[pair_v[v]] = dist[u] + 1;
                    q.push(pair_v[v]);
                }
            }
        }
    }
    return dist[0] != INF;
}

bool dfs(int u, int n, int m, vector<vector<int>> &adj, vector<int> &pair_u, vector<int> &pair_v, vector<int> &dist)
{
    if (u != 0)
    {
        for (auto &v : adj[u])
        {
            if (dist[pair_v[v]] == dist[u] + 1)
            {
                if (dfs(pair_v[v], n, m, adj, pair_u, pair_v, dist))
                {
                    pair_u[u] = v;
                    pair_v[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp(int n, int m, vector<vector<int>> &adj)
{
    vector<int> pair_u(n + 1, 0);
    vector<int> pair_v(m + 1, 0);
    vector<int> dist(n + 1, 0);
    int result = 0;

    while (bfs(n, m, adj, pair_u, pair_v, dist))
    {
        for (int u = 1; u <= n; u++)
        {
            if (pair_u[u] == 0)
            {
                if (dfs(u, n, m, adj, pair_u, pair_v, dist))
                {
                    result++;
                }
            }
        }
    }
    return result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                adj[i + 1].push_back(j + 1);
            }
        }
    }

    int max_matching = hopcroft_karp(n, m, adj);
    cout << max_matching;
}
