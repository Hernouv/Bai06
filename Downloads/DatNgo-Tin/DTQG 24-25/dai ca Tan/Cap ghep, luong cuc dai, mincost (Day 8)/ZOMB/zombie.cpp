#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int rev;
    int cap;
};

class MaxFlow
{
public:
    int N;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    MaxFlow(int N_) : N(N_), graph(N, vector<Edge>()), level(N, -1), ptr(N, 0) {}

    void add_edge(int from, int to, int cap)
    {
        Edge a = {to, (int)graph[to].size(), cap};
        Edge b = {from, (int)(graph[from].size()), 0};
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
                if (e.cap > 0 && level[e.to] == -1)
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

    int dfs(int v, int t, int pushed)
    {
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < graph[v].size(); cid++)
        {
            Edge &e = graph[v][cid];
            if (e.cap > 0 && level[e.to] == level[v] + 1)
            {
                int tr = dfs(e.to, t, min(pushed, e.cap));
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

    int max_flow(int s, int t, int flow_limit)
    {
        int flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (true)
            {
                int pushed = dfs(s, t, flow_limit - flow);
                if (pushed <= 0)
                    break;
                flow += pushed;
                if (flow == flow_limit)
                    return flow;
            }
        }
        return flow;
    }
};

void not_main()
{
    int n;
    cin >> n;
    int start, g, s;
    cin >> start >> g >> s;
    int m;
    cin >> m;
    vector<int> medical(m);
    for (auto &x : medical)
        cin >> x;
    int r;
    cin >> r;
    struct Road
    {
        int a, b, p, t;
    };
    vector<Road> roads(r);
    for (int i = 0; i < r; i++)
        cin >> roads[i].a >> roads[i].b >> roads[i].p >> roads[i].t;
    int total_nodes = n * (s + 1) + 1;
    int super_sink = n * (s + 1);
    MaxFlow mf(super_sink + 1);
    for (int u = 1; u <= n; u++)
    {
        for (int t_time = 0; t_time < s; t_time++)
        {
            int from = (u - 1) * (s + 1) + t_time;
            int to = (u - 1) * (s + 1) + (t_time + 1);
            mf.add_edge(from, to, g);
        }
    }
    for (auto &road : roads)
    {
        int a = road.a;
        int b = road.b;
        int p = road.p;
        int t_traversal = road.t;
        if (t_traversal > s)
            continue;
        for (int t_start = 0; t_start + t_traversal <= s; t_start++)
        {
            int from = (a - 1) * (s + 1) + t_start;
            int to = (b - 1) * (s + 1) + (t_start + t_traversal);
            mf.add_edge(from, to, road.p);
        }
    }
    for (auto &x : medical)
    {
        for (int t_time = 0; t_time <= s; t_time++)
        {
            int from = (x - 1) * (s + 1) + t_time;
            mf.add_edge(from, super_sink, g);
        }
    }
    int source = (start - 1) * (s + 1) + 0;
    int flow = mf.max_flow(source, super_sink, g);
    cout << min(g, flow) << "\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        not_main();
    return 0;
}
