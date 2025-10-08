#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
vector<pair<int, int>> graph[MAXN];
long long distance_from_one[MAXN];
long long distance_from_u[MAXN];

void dfs(int node, int parent, vector<long long> &distance)
{
    for (auto &edge : graph[node])
    {
        int neighbor = edge.first;
        int weight = edge.second;
        if (neighbor != parent)
        {
            distance[neighbor] = distance[node] + weight;
            dfs(neighbor, node, distance);
        }
    }
}

long long max_value(int n)
{
    // Initialize maximum value
    long long max_val = 0;

    // Calculate distances from node 1
    dfs(1, -1, distance_from_one);

    // Now calculate the maximum value for each pair (u, v)
    for (int u = 1; u <= n; u++)
    {
        // Reset distances for the current u
        fill(begin(distance_from_u), end(distance_from_u), 0);
        dfs(u, -1, distance_from_u);

        for (int v = 1; v <= n; v++)
        {
            if (u != v)
            {
                long long value_uv = distance_from_u[v];

                // Find the closest node not in the path from u to v
                long long min_distance_to_S = numeric_limits<long long>::max();
                for (int w = 1; w <= n; w++)
                {
                    if (w != u && w != v)
                    {
                        min_distance_to_S = min(min_distance_to_S, distance_from_u[w]);
                    }
                }

                if (min_distance_to_S == numeric_limits<long long>::max())
                {
                    min_distance_to_S = 0; // No valid y found
                }

                max_val = max(max_val, value_uv * min_distance_to_S);
            }
        }
    }

    return max_val;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    cout << max_value(n) << endl;

    return 0;
}
