#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge
{
    int to;
    int rev;
    int capacity;
    ll cost;
};

class MinCostMaxFlow
{
public:
    int N;
    vector<vector<Edge>> graph;
    MinCostMaxFlow(int N_) : N(N_), graph(N, vector<Edge>()) {}

    void add_edge(int from, int to, int capacity, ll cost)
    {
        Edge a = {to, (int)graph[to].size(), capacity, cost};
        Edge b = {from, (int)(graph[from].size()), 0, -cost};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    pair<ll, ll> flow(int s, int t, ll maxf)
    {
        ll flow = 0;
        ll flow_cost = 0;
        vector<ll> potential(N, 0);
        while (flow < maxf)
        {
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;
            vector<ll> dist(N, INF);
            vector<int> prevv(N, -1);
            vector<int> preve(N, -1);
            dist[s] = 0;
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
                    if (e.capacity > 0 && dist[e.to] > dist[u] + e.cost + potential[u] - potential[e.to])
                    {
                        dist[e.to] = dist[u] + e.cost + potential[u] - potential[e.to];
                        prevv[e.to] = u;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }
            if (dist[t] == INF)
                break;
            for (int v = 0; v < N; v++)
                potential[v] += (dist[v] < INF ? dist[v] : 0);
            ll addf = maxf - flow;
            int v = t;
            while (v != s)
            {
                int u = prevv[v];
                int idx = preve[v];
                addf = min(addf, (ll)graph[u][idx].capacity);
                v = u;
            }
            flow += addf;
            flow_cost += addf * potential[t];
            v = t;
            while (v != s)
            {
                int u = prevv[v];
                int idx = preve[v];
                graph[u][idx].capacity -= addf;
                graph[v][graph[u][idx].rev].capacity += addf;
                v = u;
            }
        }
        return {flow, flow_cost};
    }
};

void not_main()
{
    int N;
    cin >> N;
    vector<int> C(N);
    for (int &x : C)
        cin >> x;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    int M = S[0].size();
    int total_nodes = M + N * M + 2;
    int source = 0;
    int sink = M + N * M + 1;

    MinCostMaxFlow mcmf(total_nodes);
    for (int j = 0; j < M; j++)
        mcmf.add_edge(source, 1 + j, 1, 0);

    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (S[i][j] == 'Y')
            {
                for (int x = 1; x <= M; x++)
                {
                    int slot = 1 + M + i * M + (x - 1);
                    ll cost = (ll)C[i] * (2LL * x - 1LL);
                    mcmf.add_edge(1 + j, 1 + M + i * M + (x - 1), 1, cost);
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int x = 1; x <= M; x++)
        {
            int slot = 1 + M + i * M + (x - 1);
            mcmf.add_edge(slot, sink, 1, 0);
        }
    }
    pair<ll, ll> res = mcmf.flow(source, sink, M);

    if (res.first == M)
        cout << res.second;
    else
        cout << "-1";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
