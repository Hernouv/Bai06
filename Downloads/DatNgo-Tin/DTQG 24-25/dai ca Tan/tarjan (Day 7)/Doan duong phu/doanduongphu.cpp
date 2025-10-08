#include <bits/stdc++.h>
using namespace std;

struct UniqueEdge
{
    int u, v, m;
};

struct Frame
{
    int u;
    int parent;
    int idx;
    int parent_edge_m;
    Frame(int _u, int _parent, int _idx, int _m) : u(_u), parent(_parent), idx(_idx), parent_edge_m(_m) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (fopen("DOANDUONGPHU.INP", "r"))
    {
        freopen("DOANDUONGPHU.INP", "r", stdin);
        freopen("DOANDUONGPHU.OUT", "w", stdout);
    }

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edge_list(M);
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        edge_list[i] = {u, v};
    }

    sort(edge_list.begin(), edge_list.end());

    vector<UniqueEdge> unique_edges;
    int i = 0;
    while (i < M)
    {
        int u = edge_list[i].first;
        int v = edge_list[i].second;
        int cnt = 1;
        int j = i + 1;
        while (j < M && edge_list[j].first == u && edge_list[j].second == v)
        {
            cnt++;
            j++;
        }
        unique_edges.push_back(UniqueEdge{u, v, cnt});
        i = j;
    }

    vector<vector<pair<int, int>>> adj(N + 1, vector<pair<int, int>>());
    for (auto &e : unique_edges)
    {
        adj[e.u].emplace_back(e.v, e.m);
        adj[e.v].emplace_back(e.u, e.m);
    }

    vector<int> dfs_num(N + 1, 0);
    vector<int> low(N + 1, 0);
    int timer_val = 1;
    vector<pair<int, int>> bridge_list;
    stack<Frame> stk;

    for (int u = 1; u <= N; ++u)
    {
        if (dfs_num[u] == 0)
        {
            stk.emplace(u, -1, 0, 0);
            while (!stk.empty())
            {
                Frame &current = stk.top();
                if (dfs_num[current.u] == 0)
                {
                    dfs_num[current.u] = low[current.u] = timer_val++;
                }
                if (current.idx < adj[current.u].size())
                {
                    pair<int, int> edge = adj[current.u][current.idx];
                    stk.top().idx++;
                    int v = edge.first;
                    int m = edge.second;
                    if (v == current.parent)
                    {
                        continue;
                    }
                    if (dfs_num[v] == 0)
                    {
                        stk.emplace(v, current.u, 0, m);
                    }
                    else
                    {
                        low[current.u] = min(low[current.u], dfs_num[v]);
                    }
                }
                else
                {
                    stk.pop();
                    if (current.parent != -1)
                    {
                        low[current.parent] = min(low[current.parent], low[current.u]);
                        if (low[current.u] > dfs_num[current.parent] && current.parent_edge_m == 1)
                        {
                            bridge_list.emplace_back(min(current.u, current.parent), max(current.u, current.parent));
                        }
                    }
                }
            }
        }
    }

    sort(bridge_list.begin(), bridge_list.end());

    auto is_bridge = [&](int u, int v) -> bool
    {
        int minu = min(u, v);
        int maxv = max(u, v);
        return binary_search(bridge_list.begin(), bridge_list.end(), make_pair(minu, maxv));
    };

    vector<int> component_id(N + 1, 0);
    int component_counter = 0;
    for (int u = 1; u <= N; ++u)
    {
        if (component_id[u] == 0)
        {
            component_counter++;
            stack<int> dfs_stack;
            dfs_stack.push(u);
            component_id[u] = component_counter;
            while (!dfs_stack.empty())
            {
                int node = dfs_stack.top();
                dfs_stack.pop();
                for (auto &edge : adj[node])
                {
                    int v = edge.first;
                    if (!is_bridge(node, v) && component_id[v] == 0)
                    {
                        component_id[v] = component_counter;
                        dfs_stack.push(v);
                    }
                }
            }
        }
    }

    vector<vector<int>> tree(component_counter + 1, vector<int>());
    for (auto &bridge : bridge_list)
    {
        int u = bridge.first;
        int v = bridge.second;
        int c1 = component_id[u];
        int c2 = component_id[v];
        tree[c1].push_back(c2);
        tree[c2].push_back(c1);
    }

    vector<bool> visited_bridge_tree(component_counter + 1, false);
    long long answer = 0;
    for (int c = 1; c <= component_counter; ++c)
    {
        if (!visited_bridge_tree[c])
        {
            int leaves = 0;
            stack<int> bridge_stack;
            bridge_stack.push(c);
            visited_bridge_tree[c] = true;
            while (!bridge_stack.empty())
            {
                int node = bridge_stack.top();
                bridge_stack.pop();
                if (tree[node].size() == 1)
                {
                    leaves++;
                }
                for (auto &neighbor : tree[node])
                {
                    if (!visited_bridge_tree[neighbor])
                    {
                        visited_bridge_tree[neighbor] = true;
                        bridge_stack.push(neighbor);
                    }
                }
            }
            if (leaves > 0)
            {
                answer += (leaves + 1) / 2;
            }
        }
    }

    cout << answer;
}
