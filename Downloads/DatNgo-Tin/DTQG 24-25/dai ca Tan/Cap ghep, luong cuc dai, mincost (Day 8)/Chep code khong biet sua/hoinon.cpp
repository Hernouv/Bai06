#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

const int MAX_V = 501;

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int bfs(int source, int sink, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty())
    {
        int cur = q.front().first;
        int cur_flow = q.front().second;
        q.pop();

        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
            {
                parent[next] = cur;
                int new_flow = min(cur_flow, capacity[cur][next] - flow[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int edmondsKarp(int source, int sink, int n)
{
    int max_flow = 0;
    vector<int> parent(n);

    int new_flow;
    while ((new_flow = bfs(source, sink, parent)))
    {
        max_flow += new_flow;
        int cur = sink;

        while (cur != source)
        {
            int prev = parent[cur];
            flow[prev][cur] += new_flow;
            flow[cur][prev] -= new_flow;
            cur = prev;
        }
    }

    return max_flow;
}

struct node
{
    int s, t, c;
    bool operator<(const node &other) const
    {
        if (s == other.s)
            return t < other.t;
        return (s < other.s);
    }
};
vector<node> maxflow_edges;

void printMaxFlowEdges(int n)
{
    for (int u = 0; u < n; ++u)
    {
        for (int v : adj[u])
        {
            if (flow[u][v] > 0)
            {
                maxflow_edges.push_back({u, v, flow[u][v]});
            }
        }
    }

    sort(whole(maxflow_edges));
    cout << maxflow_edges.size() << '\n';
    for (node e : maxflow_edges)
        cout << e.s << ' ' << e.t << ' ' << e.c << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m, source, sink;
    cin >> n >> m >> source >> sink;

    for (int i = 0; i < m; ++i)
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_flow = edmondsKarp(source, sink, n);
    cout << n << ' ' << max_flow << ' ';

    printMaxFlowEdges(n);

    return 0;
}
