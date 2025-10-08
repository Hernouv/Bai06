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
                    graph[v][cid].cap -= tr;
                    graph[e.to][e.rev].cap += tr;
                    return tr;
                }
            }
        }
        return 0;
    }

    int max_flow_func(int s, int t)
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

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    struct Soldier
    {
        string name;
        vector<int> available_days;
    };
    vector<Soldier> soldiers(n);
    vector<vector<int>> available_soldiers(m + 1, vector<int>());

    for (int i = 0; i < n; i++)
    {
        string s;
        int k;
        cin >> s >> k;
        soldiers[i].name = s;
        soldiers[i].available_days.resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> soldiers[i].available_days[j];
            int day = soldiers[i].available_days[j];
            available_soldiers[day].push_back(i);
        }
    }
    int low = 0, high = m;
    int final_x = m;
    vector<pair<int, int>> assignments(m + 1, {-1, -1});
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int total_nodes = 2 + m + n;
        int source = 0;
        int sink = total_nodes - 1;
        Dinic dinic(total_nodes);
        for (int day = 1; day <= m; day++)
        {
            dinic.add_edge(source, day, 2);
        }
        for (int day = 1; day <= m; day++)
        {
            for (auto &soldier_idx : available_soldiers[day])
            {
                int soldier_node = m + 1 + soldier_idx;
                dinic.add_edge(day, soldier_node, 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int soldier_node = m + 1 + i;
            dinic.add_edge(soldier_node, sink, mid);
        }
        int flow = dinic.max_flow_func(source, sink);
        if (flow == 2 * m)
        {
            final_x = mid;
            high = mid - 1;
            assignments.assign(m + 1, {-1, -1});
            for (int day = 1; day <= m; day++)
            {
                int count = 0;
                for (auto &e : dinic.graph[day])
                {
                    if (e.to >= m + 1 && e.to < sink && e.cap == 0)
                    {
                        int soldier_idx = e.to - (m + 1);
                        if (count == 0)
                        {
                            assignments[day].first = soldier_idx;
                            count++;
                        }
                        else
                        {
                            assignments[day].second = soldier_idx;
                            break;
                        }
                    }
                }
            }
        }
        else
        {

            low = mid + 1;
        }
    }
    int total_nodes = 2 + m + n;
    int source = 0;
    int sink = total_nodes - 1;
    Dinic dinic(final_x <= m ? total_nodes : 0);
    dinic = Dinic(total_nodes);
    for (int day = 1; day <= m; day++)
    {
        dinic.add_edge(source, day, 2);
    }
    for (int day = 1; day <= m; day++)
    {
        for (auto &soldier_idx : available_soldiers[day])
        {
            int soldier_node = m + 1 + soldier_idx;
            dinic.add_edge(day, soldier_node, 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int soldier_node = m + 1 + i;
        dinic.add_edge(soldier_node, sink, final_x);
    }
    int flow = dinic.max_flow_func(source, sink);
    assignments.assign(m + 1, {-1, -1});
    for (int day = 1; day <= m; day++)
    {
        int count = 0;
        for (auto &e : dinic.graph[day])
        {
            if (e.to >= m + 1 && e.to < sink && e.cap == 0)
            {
                int soldier_idx = e.to - (m + 1);
                if (count == 0)
                {
                    assignments[day].first = soldier_idx;
                    count++;
                }
                else
                {
                    assignments[day].second = soldier_idx;
                    break;
                }
            }
        }
    }
    cout << final_x << "\n";
    for (int day = 1; day <= m; day++)
    {
        cout << "Day " << day << ": ";
        if (assignments[day].first != -1)
        {
            cout << soldiers[assignments[day].first].name << " ";
        }
        if (assignments[day].second != -1)
        {
            cout << soldiers[assignments[day].second].name << " ";
        }
        cout << "\n";
    }
}
