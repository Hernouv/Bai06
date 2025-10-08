#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n, m, k;
vector<ii> graph[2020];
int dist_source[2020];
int parent[2020], tele_cost[2020];
int s, finish;
priority_queue<ii, vector<ii>, greater<ii>> vertices_list;

void dijkstra(int start)
{
    dist_source[start] = 0;
    vertices_list.push({start, 0});
    while (!vertices_list.empty())
    {
        int index = vertices_list.top().first;
        int min_dist = vertices_list.top().second;
        vertices_list.pop();
        if (dist_source[index] < min_dist)
            continue;
        for (auto v : graph[index])
        {
            int curr_indx = v.first;
            int immd_dist = v.second;
            if (dist_source[curr_indx] > dist_source[index] + immd_dist)
            {
                dist_source[curr_indx] = dist_source[index] + immd_dist;
                parent[curr_indx] = index;
                vertices_list.push({curr_indx, dist_source[curr_indx]});
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("BKLR.INP", "r", stdin);
    freopen("BKLR.OUT", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        dist_source[i] = 1e9;
    int u, v, direct_cost;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> direct_cost;
        graph[u].push_back({v, direct_cost});
        graph[v].push_back({u, direct_cost});
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> tele_cost[i];
    }
    cin >> s >> finish;
    dijkstra(s);
    cout << dist_source[finish];
    return 0;
}