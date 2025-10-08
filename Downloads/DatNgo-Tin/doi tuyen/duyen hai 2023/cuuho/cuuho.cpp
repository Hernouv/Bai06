#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n, m, a, b;
vector<ii> graph[100010];
long long dist_source[100010];
// bool visited[100010];
priority_queue<ii, vector<ii>, greater<ii>> vertices_list;

void dijkstra(int start)
{
    dist_source[start] = 0;
    vertices_list.emplace(start, 0);
    while (!vertices_list.empty())
    {
        int parent_id = vertices_list.top().first;
        long long min_dist = vertices_list.top().second;
        vertices_list.pop();
        if (min_dist < dist_source[parent_id])
            continue;
        for (auto v : graph[parent_id])
        {
            int curr_indx = v.first;
            long long immd_dist = v.second;
            if (dist_source[curr_indx] > dist_source[parent_id] + immd_dist)
            {
                dist_source[curr_indx] = dist_source[parent_id] + immd_dist;
                vertices_list.emplace(curr_indx, dist_source[curr_indx]);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("cuuho.inp", "r", stdin);
    // freopen("cuuho.out", "w", stdout);
    cin >> n >> m >> a >> b;
    int s, f, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> f >> c;
        graph[s].emplace_back(f, c);
        graph[f].emplace_back(s, c);
    }
    for (int i = 1; i <= n; ++i)
        dist_source[i] = 1e18;
    dijkstra(1);
    for (int i = 2; i <= n; ++i)
    {
        if (dist_source[i] != 1e18)
            cout << dist_source[i] << ' ';
        else
            cout << -1;
    }
    return 0;
}