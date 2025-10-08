#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("DWLABYR.INP", "r"))
    {
        freopen("DWLABYR.INP", "r", stdin);
        freopen("DWLABYR.OUT", "w", stdout);
    }

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (w < adj[u][v])
        {
            adj[u][v] = w;
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    vector<bool> unlocked(n, false);
    vector<int> unlocked_vertices;

    while (q--)
    {
        char type;
        cin >> type;
        if (type == 'X')
        {
            int u;
            cin >> u;
            u--;
            if (!unlocked[u])
            {
                unlocked[u] = true;
                unlocked_vertices.push_back(u);

                dist[u][u] = 0;

                for (int v = 0; v < n; v++)
                {
                    if (unlocked[v] && adj[u][v] < INF)
                    {
                        dist[u][v] = min(dist[u][v], adj[u][v]);
                    }
                    if (unlocked[v] && adj[v][u] < INF)
                    {
                        dist[v][u] = min(dist[v][u], adj[v][u]);
                    }
                }
                for (auto &k : unlocked_vertices)
                {
                    for (auto &i : unlocked_vertices)
                    {
                        if (dist[i][k] == INF)
                            continue;
                        for (auto &j : unlocked_vertices)
                        {
                            if (dist[k][j] == INF)
                                continue;
                            if (dist[i][k] + dist[k][j] < dist[i][j])
                            {
                                dist[i][j] = dist[i][k] + dist[k][j];
                            }
                        }
                    }
                }
            }
        }
        else if (type == 'Y')
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (unlocked[u] && unlocked[v] && dist[u][v] < INF)
            {
                cout << dist[u][v] << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}
