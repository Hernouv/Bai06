#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

const int nmax = 1e5 + 5;
const int MAXL = 55;
const int MAXM = 1e5 + 5;
const long long INF = 1e18;

struct Edge
{
    int to;
    int w;
    int id;
};

struct Movement
{
    long long start_time;
    long long end_time;
};

int N, L, M;
vector<Edge> adj[nmax];
long long dist[MAXL][nmax];

int city_status[nmax];
long long earliest_arrival[nmax];
vector<int> nations_at_city[nmax];

map<int, vector<pair<int, Movement>>> edge_movements;

bool in_battle[MAXL][MAXL];

struct State
{
    long long time;
    int city;
    int nation;
    bool operator>(const State &other) const
    {
        return time > other.time;
    }
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CHIENTRANH.INP", "r"))
    {
        freopen("CHIENTRANH.INP", "r", stdin);
        freopen("CHIENTRANH.OUT", "w", stdout);
    }
    cin >> N >> L >> M;
    vector<int> start_cities(L);
    for (int i = 0; i < L; ++i)
    {
        cin >> start_cities[i];
    }
    int edge_id = 0;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, edge_id});
        adj[v].push_back({u, w, edge_id});
        edge_id++;
    }
    memset(city_status, -1, sizeof(city_status));
    fill(earliest_arrival, earliest_arrival + N, INF);

    priority_queue<State, vector<State>, greater<State>> pq;
    for (int i = 0; i < L; ++i)
    {
        dist[i][start_cities[i]] = 0;
        pq.push({0, start_cities[i], i});
    }
    while (!pq.empty())
    {
        State s = pq.top();
        pq.pop();
        long long t = s.time;
        int u = s.city;
        int i = s.nation;
        if (t > dist[i][u])
            continue;
        if (t > earliest_arrival[u])
            continue;
        if (t == earliest_arrival[u])
        {
            if (city_status[u] == -2)
            {
                continue;
            }
            else if (city_status[u] == i)
            {
            }
            else
            {

                nations_at_city[u].push_back(i);
                for (int other_nation : nations_at_city[u])
                {
                    if (other_nation != i)
                    {
                        int a = min(i, other_nation);
                        int b = max(i, other_nation);
                        in_battle[a][b] = true;
                    }
                }
                city_status[u] = -2;
                continue;
            }
        }
        else if (t < earliest_arrival[u])
        {
            earliest_arrival[u] = t;
            nations_at_city[u].clear();
            nations_at_city[u].push_back(i);
            city_status[u] = i;
        }
        if (city_status[u] != i)
        {
            for (Edge &edge : adj[u])
            {
                int v = edge.to;
                int w = edge.w;
                long long t_v = t + w;
                int e_id = edge.id;
                Movement m = {t, t_v};
                edge_movements[e_id].push_back({i, m});
            }
            continue;
        }
        // Proceed to expand
        for (Edge &edge : adj[u])
        {
            int v = edge.to;
            int w = edge.w;
            long long t_v = t + w;
            int e_id = edge.id;
            Movement m = {t, t_v};
            edge_movements[e_id].push_back({i, m});
            if (dist[i][v] != 0 && dist[i][v] <= t_v)
                continue;
            dist[i][v] = t_v;
            pq.push({t_v, v, i});
        }
    }
    for (int u = 0; u < N; ++u)
    {
        if (city_status[u] == -2)
        {
            vector<int> &nations = nations_at_city[u];
            for (size_t p = 0; p < nations.size(); ++p)
            {
                for (size_t q = p + 1; q < nations.size(); ++q)
                {
                    int a = min(nations[p], nations[q]);
                    int b = max(nations[p], nations[q]);
                    in_battle[a][b] = true;
                }
            }
        }
    }
    for (auto &e : edge_movements)
    {
        vector<pair<int, Movement>> &movs = e.second;
        sort(whole(movs), [](const pair<int, Movement> &a, const pair<int, Movement> &b)
             { return a.second.start_time < b.second.start_time; });
        for (size_t p = 0; p < movs.size(); ++p)
        {
            for (size_t q = p + 1; q < movs.size(); ++q)
            {
                int nation_p = movs[p].first;
                int nation_q = movs[q].first;
                if (nation_p == nation_q)
                    continue;
                Movement &m_p = movs[p].second;
                Movement &m_q = movs[q].second;
                if (m_q.start_time >= m_p.end_time)
                    break;
                if (m_p.start_time >= m_q.end_time)
                    continue;
                int a = min(nation_p, nation_q);
                int b = max(nation_p, nation_q);
                in_battle[a][b] = true;
            }
        }
    }
    vector<pair<int, int>> battles;
    for (int i = 0; i < L; ++i)
    {
        for (int j = i + 1; j < L; ++j)
        {
            if (in_battle[i][j])
            {
                battles.push_back({i, j});
            }
        }
    }
    sort(whole(battles));
    for (auto &p : battles)
    {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
