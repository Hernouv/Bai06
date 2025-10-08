#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()
typedef long long ll;

struct Edge
{
    int to;
    ll cap;
    int rev;
};

class MaxFlow
{
public:
    int N;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    MaxFlow(int N_) : N(N_), graph(N, vector<Edge>()), level(N, -1), ptr(N, 0) {}

    void add_edge(int from, int to, ll cap)
    {
        Edge a = {to, cap, (int)graph[to].size()};
        Edge b = {from, 0, (int)(graph[from].size())};
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
            for (Edge e : graph[v])
            {
                if (e.cap > 0 and level[e.to] == -1)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, int t, ll pushed)
    {
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < graph[v].size(); ++cid)
        {
            Edge &e = graph[v][cid];
            if (e.cap > 0 and level[e.to] == level[v] + 1)
            {
                ll tr = dfs(e.to, t, min(pushed, e.cap));
                if (tr > 0)
                {
                    e.cap -= tr;
                    graph[e.to][e.rev].cap += tr;
                    return tr;
                }
            }
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

    vector<bool> min_cut(int s)
    {
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v])
            {
                if (e.cap > 0 && !visited[e.to])
                {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return visited;
    }
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    MaxFlow mf(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        mf.add_edge(u, v, w);
    }
    mf.max_flow(s, t);
    vector<bool> reachable = mf.min_cut(s);
    vector<int> U;
    for (int i = 0; i < n; ++i)
        if (reachable[i])
            U.push_back(i);
    sort(whole(U));
    cout << U.size() << "\n";
    for (int x : U)
        cout << x << "\n";
    return 0;
}
