#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
vector<ii> graph[110];
int dist_source[110];
priority_queue<ii, vector<ii>, greater<ii>> vertices_list;
int n, m, v, u;

void dijkstra(int start)
{
    dist_source[start] = 0;
    vertices_list.emplace(start, 0);
    while (!vertices_list.empty())
    {
        int index = vertices_list.top().first;
        int min_dist = vertices_list.top().second;
        vertices_list.pop();
        if (dist_source[index] < min_dist)
            continue;
        for (auto x : graph[index])
        {
            int curr_indx = x.first;
            int immd_dist = x.second;
            if (dist_source[curr_indx] > dist_source[index] + immd_dist)
            {
                dist_source[curr_indx] = dist_source[index] + immd_dist;
                vertices_list.emplace(curr_indx, dist_source[curr_indx]);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);
    cin >> n >> m >> v >> u;
    for (int i = 1; i <= n; ++i)
        dist_source[i] = 0x3f;
    int s, f, val;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> f >> val;
        graph[s].emplace_back(f, val);
        graph[f].emplace_back(s, val);
    }
    dijkstra(1);
    cout << dist_source[n];
    return 0;
}