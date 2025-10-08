#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;

struct node
{
    int bac;
    int trongso;
    int id;
};

struct customSort
{
    bool operator()(node &a, node &b)
    {
        if (a.bac != b.bac)
            return a.bac > b.bac;
        return (a.trongso > b.trongso);
    }
};

int n, m, k, weight[nmax];
bool eliminated[nmax];
int graph_sz[nmax];
int saved_cost = 0, total_cost, dist_source[nmax];
vector<int> traffic_center;
vector<int> graph[nmax];
priority_queue<node, vector<node>, customSort> vlist;

void dfs_free(int par, int vx)
{
    for (int v : graph[vx])
    {
        if (v != par)
        {
            dist_source[v] = dist_source[vx] + 1;
            if (!eliminated[v])
                saved_cost += (dist_source[v] * weight[v]);
            total_cost += dist_source[v];
            dfs_free(vx, v);
        }
    }
}

void not_main()
{
    cin >> n >> m >> k;
    int tu, tv;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
        ++graph_sz[tu];
        ++graph_sz[tv];
    }

    for (int i = 1; i <= n; ++i)
    {
        weight[i] = 1;
        vlist.push({graph_sz[i], 1, i});
    }

    for (int i = 1; i <= m - k; ++i)
    {
        int conn_vno = vlist.top().bac;
        int w = vlist.top().trongso;
        int v_id = vlist.top().id;
        vlist.pop();

        if (eliminated[v_id])
            continue;

        eliminated[v_id] = true;

        for (int v : graph[v_id])
        {
            if (!eliminated[v])
            {
                --graph_sz[v];
                weight[v] += weight[v_id];
                vlist.push({graph_sz[v], weight[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!eliminated[i])
            traffic_center.push_back(i);

    dist_source[traffic_center[0]] = 0;
    dfs_free(0, traffic_center[0]);
    cout << total_cost - saved_cost;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRAFFIC.INP", "r"))
    {
        freopen("TRAFFIC.INP", "r", stdin);
        freopen("TRAFFIC.OUT", "w", stdout);
    }
    not_main();
    return 0;
}