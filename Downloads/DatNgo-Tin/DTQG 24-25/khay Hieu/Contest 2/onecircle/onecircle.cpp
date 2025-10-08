#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n, m;
vector<int> adj[MAXN + 1];

int timer;
int tin[MAXN + 1], low[MAXN + 1];
bool visited[MAXN + 1];
vector<pair<int, int>> edges;
bool isBridgeEdge[MAXN + 1];

int parentEdge[MAXN + 1];

struct Edge
{
    int to;
    int id;
};
vector<Edge> g[MAXN + 1];

void dfs_find_bridges(int u, int p = -1)
{
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    for (auto &ed : g[u])
    {
        int v = ed.to;
        int id = ed.id;
        if (id == p)
            continue;
        if (visited[v])
        {
            low[u] = min(low[u], tin[v]);
        }
        else
        {
            dfs_find_bridges(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
            {
                isBridgeEdge[id] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    edges.reserve(m);
    vector<pair<int, int>> inputEdges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        inputEdges[i] = {u, v};
    }

    for (int i = 0; i < m; i++)
    {
        int u = inputEdges[i].first;
        int v = inputEdges[i].second;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    timer = 0;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs_find_bridges(i);
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        if (isBridgeEdge[i])
        {
            int u = inputEdges[i].first;
            int v = inputEdges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    long long result = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int c = 0;
            stack<int> st;
            st.push(i);
            visited[i] = true;
            while (!st.empty())
            {
                int u = st.top();
                st.pop();
                c++;
                for (auto &nx : adj[u])
                {
                    if (!visited[nx])
                    {
                        visited[nx] = true;
                        st.push(nx);
                    }
                }
            }
            if (c > 2)
            {
                long long comp_pairs = (long long)(c - 1) * (c - 2) / 2;
                result += comp_pairs;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
