#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, 0);

    long long total_cost = 0;
    for (int start = 1; start <= n; start++)
    {
        if (color[start] != 0 or adj[start].empty() and color[start] == 0)
        {
            if (color[start] == 0 and adj[start].empty())
            {
                color[start] = 1;
            }
            continue;
        }
        if (color[start] != 0)
            continue;

        queue<int> q;
        color[start] = 1;
        q.push(start);

        vector<int> component_nodes;
        bool is_bipartite = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            component_nodes.push_back(u);
            for (int w : adj[u])
            {
                if (color[w] == 0)
                {
                    color[w] = -color[u];
                    q.push(w);
                }
                else if (color[w] == color[u])
                {
                    is_bipartite = false;
                    break;
                }
            }
            if (!is_bipartite)
                break;
        }

        if (!is_bipartite)
        {
            cout << -1 << "\n";
            return 0;
        }

        vector<int> setA, setB;
        for (auto node : component_nodes)
        {
            if (color[node] == 1)
                setA.push_back(node);
            else
                setB.push_back(node);
        }

        auto checkPattern = [&](int aColor, int bColor) -> long long
        {
            long long cost = 0;
            for (auto v : setA)
            {
                if (c[v] != aColor)
                {
                    if (d[v] == 0)
                        return (long long)-1;
                    cost++;
                }
            }
            for (auto v : setB)
            {
                if (c[v] != bColor)
                {
                    if (d[v] == 0)
                        return (long long)-1;
                    cost++;
                }
            }
            return cost;
        };

        long long costA = checkPattern(1, 2);
        long long costB = checkPattern(2, 1);

        if (costA == -1 and costB == -1)
        {
            cout << -1 << "\n";
            return 0;
        }

        long long comp_cost;
        if (costA == -1)
            comp_cost = costB;
        else if (costB == -1)
            comp_cost = costA;
        else
            comp_cost = min(costA, costB);

        total_cost += comp_cost;
    }

    cout << total_cost << "\n";
    return 0;
}
