#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class HopcroftKarp
{
public:
    int n, m;
    vector<vector<int>> adj;
    vector<int> pair_u, pair_v, dist;

    HopcroftKarp(int size_u, int size_v)
    {
        n = size_u;
        m = size_v;
        adj.assign(n + 1, vector<int>());
        pair_u.assign(n + 1, 0);
        pair_v.assign(m + 1, 0);
        dist.assign(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool bfs()
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
                dist[u] = INT32_MAX;
            }
        }
        dist[0] = INT32_MAX;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u != 0)
            {
                for (auto &v : adj[u])
                {
                    if (dist[pair_v[v]] == INT32_MAX)
                    {
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);
                    }
                }
            }
        }
        return dist[0] != INT32_MAX;
    }

    bool dfs(int u)
    {
        if (u != 0)
        {
            for (auto &v : adj[u])
            {
                if (dist[pair_v[v]] == dist[u] + 1)
                {
                    if (dfs(pair_v[v]))
                    {
                        pair_u[u] = v;
                        pair_v[v] = u;
                        return true;
                    }
                }
            }
            dist[u] = INT32_MAX;
            return false;
        }
        return true;
    }

    int max_matching()
    {
        int matching = 0;
        while (bfs())
        {
            for (int u = 1; u <= n; u++)
            {
                if (pair_u[u] == 0)
                {
                    if (dfs(u))
                    {
                        matching++;
                    }
                }
            }
        }
        return matching;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<ll>> C(n + 1, vector<ll>(n + 1, 0));
    ll minC = LLONG_MAX, maxC = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> C[i][j];
            minC = min(minC, C[i][j]);
            maxC = max(maxC, C[i][j]);
        }
    }

    ll left = minC, right = maxC, answer = maxC;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        HopcroftKarp hk(n, n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (C[i][j] <= mid)
                {
                    hk.addEdge(i, j);
                }
            }
        }
        if (hk.max_matching() == n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << answer;
}
