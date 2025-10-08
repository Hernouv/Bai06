#include <bits/stdc++.h>
using namespace std;

#define ill pair<int, long long>
int n, m, s, k;
vector<int> dest;
vector<ill> graph[200010];
int parent[200010];
long long dist_source[200010];
priority_queue<ill, vector<ill>, greater<ill>> scanlist;

void dijkstra(int start)
{
    for (int i = 1; i <= n; ++i)
        dist_source[i] = 1e18;
    dist_source[start] = 0;
    scanlist.emplace(start, 0);
    while (!scanlist.empty())
    {
        int par = scanlist.top().first;
        int min_dist = scanlist.top().second;
        scanlist.pop();
        if (dist_source[par] < min_dist)
            continue;
        for (auto v : graph[par])
        {
            int curr_id = v.first;
            int immd_dist = v.second;
            if (dist_source[curr_id] > dist_source[par] + immd_dist)
            {
                dist_source[curr_id] = dist_source[par] + immd_dist;
                scanlist.emplace(curr_id, dist_source[curr_id]);
                parent[curr_id] = par;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    cin >> s;
    dijkstra(s);

    cin >> k;
    int d;
    for (int i = 1; i <= k; ++i)
    {
        cin >> d;
        dest.push_back(d);
    }
    for (int i = 1; i <= n; ++i)
        cout << dist_source[i] << ' ';
    cout << '\n';
    stack<int> path;
    for (int x : dest)
    {
        cout << s << "->" << x << ": ";
        if (dist_source[x] == (long long)1e18)
        {
            cout << -1 << '\n';
            continue;
        }
        while (x != s)
        {
            path.push(x);
            x = parent[x];
        }
        path.push(s);
        while (!path.empty())
        {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << '\n';
    }
    return 0;
}
