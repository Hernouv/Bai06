#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int rev;
    int cap;
};

class Dinic
{
public:
    int N;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    Dinic(int N_) : N(N_), graph(N, vector<Edge>()), level(N, -1), ptr(N, 0) {}

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

    int max_flow(int s, int t)
    {
        int flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INT32_MAX))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pianos(n);
    for (auto &p : pianos)
    {
        cin >> p.first >> p.second;
    }

    int total_nodes = n + 100 + 2;
    int source = 0;
    int sink = n + 100 + 1;
    Dinic dinic_fine(total_nodes);
    for (int i = 1; i <= n; i++)
    {
        dinic_fine.add_edge(source, i, 1);
    }
    int day_base = n + 1;
    vector<bool> is_weekday(101, false);
    for (int d = 1; d <= 100; d++)
    {
        int day_of_week = ((d - 1) % 7) + 1;
        if (day_of_week >= 1 && day_of_week <= 5)
        {
            is_weekday[d] = true;
        }
    }
    for (int d = 1; d <= 100; d++)
    {
        if (is_weekday[d])
        {
            dinic_fine.add_edge(day_base + d - 1, sink, m / 2);
        }
    }
    bool fine_possible = true;
    for (int i = 0; i < n; i++)
    {
        int li = pianos[i].first;
        int ri = pianos[i].second;
        int piano_node = i + 1;
        int start_day = max(li, 1);
        int end_day = min(ri, 100);
        bool has_day = false;
        for (int d = start_day; d <= end_day; d++)
        {
            if (is_weekday[d])
            {
                has_day = true;
                dinic_fine.add_edge(piano_node, day_base + d - 1, 1);
            }
        }
        if (!has_day)
        {
            fine_possible = false;
        }
    }
    if (fine_possible)
    {
        int flow = dinic_fine.max_flow(source, sink);
        if (flow == n)
        {
            cout << "fine\n";
            return;
        }
    }

    Dinic dinic_weekend(total_nodes);
    for (int i = 1; i <= n; i++)
        dinic_weekend.add_edge(source, i, 1);
    for (int d = 1; d <= 100; d++)
        dinic_weekend.add_edge(day_base + d - 1, sink, m / 2);

    bool weekend_possible = true;
    for (int i = 0; i < n; i++)
    {
        int li = pianos[i].first;
        int ri = pianos[i].second;
        int piano_node = i + 1;
        int start_day = max(li, 1);
        int end_day = min(ri, 100);
        bool has_day = false;
        for (int d = start_day; d <= end_day; d++)
        {
            has_day = true;
            dinic_weekend.add_edge(piano_node, day_base + d - 1, 1);
        }
        if (!has_day)
        {
            weekend_possible = false;
        }
    }
    if (weekend_possible)
    {
        int flow = dinic_weekend.max_flow(source, sink);
        if (flow == n)
        {
            cout << "weekend work\n";
            return;
        }
    }
    cout << "serious trouble\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
        not_main();
    return 0;
}
