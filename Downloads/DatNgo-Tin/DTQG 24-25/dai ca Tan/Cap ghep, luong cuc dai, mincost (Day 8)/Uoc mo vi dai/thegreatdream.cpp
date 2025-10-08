#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

struct Edge
{
    int to;
    int rev;
    int original_capacity;
    int capacity;
};

class MaxFlow
{
public:
    int n;
    vector<vector<Edge>> adj;
    MaxFlow(int nodes) : n(nodes), adj(nodes + 1) {}

    void add_edge(int from, int to, int cap)
    {
        Edge a = {to, (int)adj[to].size(), cap, cap};
        adj[from].push_back(a);
        Edge b = {from, (int)(adj[from].size() - 1), 0, 0};
        adj[to].push_back(b);
    }

    void add_undirected_edge(int u, int v, int cap)
    {
        Edge a = {v, (int)adj[v].size(), cap, cap};
        adj[u].push_back(a);
        Edge b = {u, (int)(adj[u].size() - 1), 0, 0};
        adj[v].push_back(b);
        Edge c = {u, (int)adj[u].size(), cap, cap};
        adj[v].push_back(c);
        Edge d = {v, (int)(adj[v].size() - 1), 0, 0};
        adj[u].push_back(d);
    }

    void reset_capacities()
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto &e : adj[u])
            {
                e.capacity = e.original_capacity;
            }
        }
    }

    void set_original_capacities()
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto &e : adj[u])
            {
                e.original_capacity = e.capacity;
            }
        }
    }

    bool bfs(int s, int t, vector<int> &level)
    {
        fill(whole(level), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : adj[u])
            {
                if (e.capacity > 0 and level[e.to] == -1)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                    if (e.to == t)
                        return true;
                }
            }
        }
        return false;
    }

    int dfs(int u, int t, int flow, vector<int> &level, vector<int> &ptr)
    {
        if (u == t)
            return flow;
        for (int &i = ptr[u]; i < adj[u].size(); i++)
        {
            Edge &e = adj[u][i];
            if (e.capacity > 0 and level[e.to] == level[u] + 1)
            {
                int pushed = dfs(e.to, t, min(flow, e.capacity), level, ptr);
                if (pushed > 0)
                {
                    e.capacity -= pushed;
                    adj[e.to][e.rev].capacity += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow_algo(int s, int t)
    {
        int flow = 0;
        vector<int> level(n + 1, -1);
        while (bfs(s, t, level))
        {
            vector<int> ptr(n + 1, 0);
            while (int pushed = dfs(s, t, INT32_MAX, level, ptr))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

struct EdgeInput
{
    int u, v, c;
};

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<EdgeInput> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
    }
    vector<int> order(m);
    for (int i = 0; i < m; i++)
        order[i] = i;
    sort(whole(order), [&](const int a, const int b) -> bool
         {
        if(edges[a].c != edges[b].c) return edges[a].c < edges[b].c;
        return a < b; });
    int max_c = 0;
    for (int i = 0; i < m; i++)
        max_c = max(max_c, edges[i].c);
    vector<vector<int>> queries(max_c + 2, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int c = edges[i].c;
        queries[c].push_back(i);
    }
    vector<int> Hi(m, 0);
    MaxFlow mf(n);
    for (int c = 1; c <= max_c; c++)
    {
        for (auto &i : queries[c])
        {
            int u = edges[i].u;
            int v = edges[i].v;
            mf.reset_capacities();
            int flow = mf.max_flow_algo(u, v);
            Hi[i] = flow;
        }
        for (int i = 0; i < m; i++)
        {
            if (edges[i].c == c)
            {
                int u = edges[i].u;
                int v = edges[i].v;
                mf.add_edge(u, v, 1);
                mf.add_edge(v, u, 1);
            }
        }
    }
    long long total_Hi = 0;
    for (int i = 0; i < m; i++)
        total_Hi += Hi[i];
    cout << total_Hi;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CUNGKHAY.INP", "r"))
    {
        freopen("CUNGKHAY.INP", "r", stdin);
        freopen("CUNGKHAY.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
