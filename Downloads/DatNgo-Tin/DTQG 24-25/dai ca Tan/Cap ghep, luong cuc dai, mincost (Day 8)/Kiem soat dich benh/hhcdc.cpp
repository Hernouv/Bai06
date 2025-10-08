#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int to;
    ll capacity;
    int rev;
    int idx;
};

class Dinic
{
public:
    int n;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    Dinic(int nodes) : n(nodes), graph(nodes + 1), level(nodes + 1, -1), ptr(nodes + 1, 0) {}

    void add_edge(int from, int to, ll capacity, int idx)
    {
        Edge a = {to, capacity, (int)graph[to].size(), idx};
        Edge b = {from, 0, (int)(graph[from].size()), -1};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v])
            {
                if (e.capacity > 0 and level[e.to] == -1)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                    if (e.to == t)
                        break;
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, int t, ll pushed)
    {
        if (v == t)
            return pushed;
        while (ptr[v] < graph[v].size())
        {
            Edge &e = graph[v][ptr[v]];
            if (e.capacity > 0 and level[e.to] == level[v] + 1)
            {
                ll tr = dfs(e.to, t, min(pushed, e.capacity));
                if (tr > 0)
                {
                    graph[v][ptr[v]].capacity -= tr;
                    graph[e.to][e.rev].capacity += tr;
                    return tr;
                }
            }
            ptr[v]++;
        }
        return 0;
    }

    ll max_flow(int s, int t)
    {
        ll flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, t, LLONG_MAX))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

struct OriginalEdge
{
    int u;
    int v;
    ll w;
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("HHCDC.INP", "r"))
    {
        freopen("HHCDC.INP", "r", stdin);
        freopen("HHCDC.INP", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    vector<OriginalEdge> original_edges(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> original_edges[i].u >> original_edges[i].v >> original_edges[i].w;
    }
    Dinic dinic(n);
    for (int i = 1; i <= m; ++i)
    {
        int u = original_edges[i].u;
        int v = original_edges[i].v;
        ll w = original_edges[i].w;
        dinic.add_edge(u, v, w, i);
        dinic.add_edge(v, u, w, i);
    }
    ll flow = dinic.max_flow(1, n);
    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(1);
    reachable[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &e : dinic.graph[u])
        {
            if (e.capacity > 0 and !reachable[e.to])
            {
                reachable[e.to] = true;
                q.push(e.to);
            }
        }
    }
    ll total = 0;
    vector<int> cut_edges;
    for (int i = 1; i <= m; ++i)
    {
        int u = original_edges[i].u;
        int v = original_edges[i].v;
        ll w = original_edges[i].w;
        if ((reachable[u] and !reachable[v]) or (reachable[v] and !reachable[u]))
        {
            total += w;
            cut_edges.push_back(i);
        }
    }
    sort(cut_edges.begin(), cut_edges.end());
    cout << total << "\n";
    for (int i = 0; i < cut_edges.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << cut_edges[i];
    }
    return 0;
}
