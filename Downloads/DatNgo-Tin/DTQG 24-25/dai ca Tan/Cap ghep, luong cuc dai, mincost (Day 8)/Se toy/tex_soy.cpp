#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int rev;
    int cap;
};

const int MAX_NODES = 300 + 2;
vector<Edge> adj[303];

void add_edge(int from, int to, int cap)
{
    Edge a = {to, (int)adj[to].size(), cap};
    Edge b = {from, (int)(adj[from].size()), 0};
    adj[from].push_back(a);
    adj[to].push_back(b);
}

int32_t main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> liked_toys(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int ki;
        cin >> ki;
        liked_toys[i].resize(ki);
        for (int j = 0; j < ki; j++)
            cin >> liked_toys[i][j];
    }
    vector<int> toy_type(m + 1, 0);
    vector<int> type_limit(p + 1, 0);
    for (int type = 1; type <= p; type++)
    {
        int li;
        cin >> li;
        vector<int> toys(li);
        for (int j = 0; j < li; j++)
            cin >> toys[j];
        int ri;
        cin >> ri;
        type_limit[type] = ri;
        for (auto toy : toys)
        {
            toy_type[toy] = type;
        }
    }
    int num_type0_toys = 0;
    for (int t = 1; t <= m; t++)
        if (toy_type[t] == 0)
            num_type0_toys++;
    int S = 0;
    int T = 1;
    int child_start = 2;
    int toy_start = child_start + n;
    int type_start = toy_start + m;
    int type0_node = type_start + p;
    for (int i = 0; i < n; i++)
    {
        int child_node = child_start + i;
        add_edge(S, child_node, 1);
        for (auto toy : liked_toys[i])
        {
            if (toy < 1 or toy > m)
                continue;
            int toy_node = toy_start + (toy - 1);
            add_edge(child_node, toy_node, 1);
        }
    }
    for (int t = 1; t <= m; t++)
    {
        int toy_node = toy_start + (t - 1);
        if (toy_type[t] == 0)
        {
            add_edge(toy_node, type0_node, 1);
        }
        else
        {
            int typek = toy_type[t];
            int type_node = type_start + (typek - 1);
            add_edge(toy_node, type_node, 1);
        }
    }
    for (int type = 1; type <= p; type++)
    {
        int type_node = type_start + (type - 1);
        add_edge(type_node, T, type_limit[type]);
    }
    add_edge(type0_node, T, num_type0_toys);
    int total_flow = 0;
    while (1)
    {
        vector<int> parent(303, -1);
        vector<int> parent_edge(303, -1);
        queue<int> q;
        q.push(S);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++)
            {
                Edge &e = adj[u][i];
                if (e.cap > 0 and parent[e.to] == -1 and e.to != S)
                {
                    parent[e.to] = u;
                    parent_edge[e.to] = i;
                    q.push(e.to);
                    if (e.to == T)
                        break;
                }
            }
            if (parent[T] != -1)
                break;
        }
        if (parent[T] == -1)
            break;
        int flow = INT32_MAX;
        int v = T;
        while (v != S)
        {
            int u = parent[v];
            int idx = parent_edge[v];
            flow = min(flow, adj[u][idx].cap);
            v = u;
        }
        v = T;
        while (v != S)
        {
            int u = parent[v];
            int idx = parent_edge[v];
            adj[u][idx].cap -= flow;
            adj[v][adj[u][idx].rev].cap += flow;
            v = u;
        }
        total_flow += flow;
    }
    cout << total_flow;
}
