#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(_name) _name.begin(), _name.end()

const ll INF = 1e18;

struct Edge
{
    int to;
    int rev;
    ll cap;
    ll cost;
};

class MinCostFlow
{
public:
    int n;
    vector<vector<Edge>> graph;
    MinCostFlow(int nodes) : n(nodes), graph(nodes + 1) {}

    void add_edge(int from, int to, ll cap, ll cost)
    {
        Edge a = {to, (int)graph[to].size(), cap, cost};
        Edge b = {from, (int)(graph[from].size()), 0, -cost};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    pair<ll, ll> min_cost_flow(int s, int t, ll maxf)
    {
        ll flow = 0;
        ll flow_cost = 0;
        vector<ll> potential(n + 1, 0);
        while (flow < maxf)
        {
            vector<ll> dist(n + 1, INF);
            vector<int> prevv(n + 1, -1);
            vector<int> preve(n + 1, -1);
            dist[s] = 0;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;
            pq.emplace(0, s);
            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u])
                    continue;
                for (int i = 0; i < graph[u].size(); i++)
                {
                    Edge &e = graph[u][i];
                    if (e.cap > 0 && dist[e.to] > dist[u] + e.cost + potential[u] - potential[e.to])
                    {
                        dist[e.to] = dist[u] + e.cost + potential[u] - potential[e.to];
                        prevv[e.to] = u;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }
            if (dist[t] == INF)
            {
                break;
            }
            for (int v = 1; v <= n; v++)
                potential[v] += (dist[v] < INF ? dist[v] : 0);
            ll addf = maxf - flow;
            ll path_cost = 0;
            int v = t;
            while (v != s)
            {
                int u = prevv[v];
                int idx = preve[v];
                path_cost += graph[u][idx].cost;
                v = u;
            }
            flow += 1;
            flow_cost += path_cost;
            v = t;
            while (v != s)
            {
                int u = prevv[v];
                int idx = preve[v];
                graph[u][idx].cap -= 1;
                graph[v][graph[u][idx].rev].cap += 1;
                v = u;
            }
        }
        return {flow, flow_cost};
    }
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, k, s, f;
    cin >> n >> m >> k >> s >> f;
    MinCostFlow mcf(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        mcf.add_edge(u, v, 1, c);
        mcf.add_edge(v, u, 1, c);
    }
    pair<ll, ll> res = mcf.min_cost_flow(s, f, k);
    if (res.first < k)
    {
        cout << "-1\n";
        return 0;
    }

    vector<vector<int>> flow_graph(n + 1, vector<int>());
    for (int u = 1; u <= n; u++)
    {
        for (auto &e : mcf.graph[u])
        {
            if (e.cap == 0)
            {
                if (e.cost >= 0)
                {
                    flow_graph[u].push_back(e.to);
                }
            }
        }
    }

    vector<vector<int>> paths;
    for (int i = 0; i < k; i++)
    {
        vector<int> path;
        int current = s;
        path.push_back(current);
        while (current != f)
        {
            if (flow_graph[current].empty())
            {
                break;
            }
            int next = flow_graph[current].back();
            flow_graph[current].pop_back();
            path.push_back(next);
            current = next;
        }
        paths.push_back(path);
    }

    vector<pair<int, int>> print_order;
    for (int it = 0; it < paths.size(); ++it)
    {
        print_order.push_back({it, paths[it].size()});
    }

    sort(whole(print_order), [](pair<int, int> &x, pair<int, int> &y)
         { return (x.second < y.second); });

    cout << res.second << "\n";
    for (pair<int, int> it : print_order)
    {
        cout << it.second << ' ';
        for (int it2 : paths[it.first])
            cout << it2 << ' ';
        cout << '\n';
    }
    return 0;
}
