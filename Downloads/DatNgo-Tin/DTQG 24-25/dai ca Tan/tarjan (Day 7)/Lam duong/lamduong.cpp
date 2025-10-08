#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int N, M;
vector<pair<int, int>> edges_input;
vector<pair<int, int>> unique_edges;
vector<bool> multiple_edge;

vector<vector<pair<int, bool>>> adj;

vector<bool> is_bridge;

int time_counter = 0;
vector<int> disc_time;
vector<int> low;
vector<bool> visited_tarjan;

vector<pair<int, int>> bridges_list;

vector<int> component_id;
int current_component = 0;

vector<vector<int>> bridge_tree_adj;

void tarjan(int u, int parent_u)
{
    visited_tarjan[u] = true;
    disc_time[u] = low[u] = ++time_counter;

    for (auto &[v, is_multiple] : adj[u])
    {
        if (v == parent_u)
            continue;
        if (!visited_tarjan[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc_time[u])
            {
                if (!is_multiple)
                {
                    bridges_list.emplace_back(u, v);
                }
            }
        }
        else
        {
            low[u] = min(low[u], disc_time[v]);
        }
    }
}

int32_t main()
{
    fast_io();
    if (fopen("BAI4.INP", "r"))
    {
        freopen("BAI4.INP", "r", stdin);
        freopen("BAI4.OUT", "w", stdout);
    }
    cin >> N >> M;
    edges_input.reserve(M);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        edges_input.emplace_back(u, v);
    }
    sort(edges_input.begin(), edges_input.end());
    unique_edges.reserve(M);
    multiple_edge.reserve(M);
    int i = 0;
    while (i < M)
    {
        int u = edges_input[i].first;
        int v = edges_input[i].second;
        int cnt = 1;
        int j = i + 1;
        while (j < M && edges_input[j].first == u && edges_input[j].second == v)
        {
            cnt++;
            j++;
        }
        unique_edges.emplace_back(u, v);
        multiple_edge.push_back(cnt > 1);
        i = j;
    }
    int K = unique_edges.size();
    adj.assign(N + 1, vector<pair<int, bool>>());
    for (int idx = 0; idx < K; idx++)
    {
        int u = unique_edges[idx].first;
        int v = unique_edges[idx].second;
        bool is_mult = multiple_edge[idx];
        adj[u].emplace_back(v, is_mult);
        adj[v].emplace_back(u, is_mult);
    }
    disc_time.assign(N + 1, 0);
    low.assign(N + 1, 0);
    visited_tarjan.assign(N + 1, false);
    for (int u = 1; u <= N; u++)
    {
        if (!visited_tarjan[u])
        {
            tarjan(u, -1);
        }
    }
    component_id.assign(N + 1, -1);
    current_component = 0;
    sort(bridges_list.begin(), bridges_list.end());
    vector<vector<int>> adj_no_bridges(N + 1, vector<int>());
    auto is_bridge_edge = [&](int u, int v) -> bool
    {
        return binary_search(bridges_list.begin(), bridges_list.end(), make_pair(u, v)) ||
               binary_search(bridges_list.begin(), bridges_list.end(), make_pair(v, u));
    };
    for (int u = 1; u <= N; u++)
    {
        for (auto &[v, is_mult] : adj[u])
        {
            if (!is_bridge_edge(u, v))
            {
                adj_no_bridges[u].push_back(v);
            }
        }
    }
    for (int u = 1; u <= N; u++)
    {
        if (component_id[u] == -1)
        {
            stack<int> s;
            s.push(u);
            component_id[u] = current_component;
            while (!s.empty())
            {
                int node = s.top();
                s.pop();
                for (auto &v : adj_no_bridges[node])
                {
                    if (component_id[v] == -1)
                    {
                        component_id[v] = current_component;
                        s.push(v);
                    }
                }
            }
            current_component++;
        }
    }
    int num_components = current_component;
    bridge_tree_adj.assign(num_components, vector<int>());
    for (auto &[u, v] : bridges_list)
    {
        int cu = component_id[u];
        int cv = component_id[v];
        bridge_tree_adj[cu].push_back(cv);
        bridge_tree_adj[cv].push_back(cu);
    }
    if (num_components == 1)
    {
        cout << 0;
        return 0;
    }
    auto bfs = [&](int start) -> pair<int, int>
    {
        vector<int> dist(num_components, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : bridge_tree_adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int farthest = start;
        int max_dist = 0;
        for (int i = 0; i < num_components; i++)
        {
            if (dist[i] > max_dist)
            {
                max_dist = dist[i];
                farthest = i;
            }
        }
        return {farthest, max_dist};
    };
    pair<int, int> first_bfs = bfs(0);
    pair<int, int> second_bfs = bfs(first_bfs.first);
    int diameter = second_bfs.second;
    int total_bridges = num_components - 1;
    int minimal_bridges = total_bridges - diameter;
    cout << total_bridges - minimal_bridges;
}
