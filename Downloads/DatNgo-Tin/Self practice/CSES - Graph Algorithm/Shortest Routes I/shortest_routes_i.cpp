#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long long> ill;
typedef long long ll;
#define fi first
#define se second

const int nmax = 1e5 + 10;
const ll outbound = 1e18;

int n, m;
vector<ill> graph[nmax];
ll dist_source[nmax];

priority_queue<ill, vector<ill>, greater<ill>> vlist;

void dijkstra(int start)
{
    for (int i = 1; i <= n; ++i)
        dist_source[i] = outbound;
    dist_source[start] = 0;

    vlist.emplace(start, 0);
    while (!vlist.empty())
    {
        int curr_par = vlist.top().first;
        ll min_dist = vlist.top().second;
        vlist.pop();
        if (dist_source[curr_par] < min_dist)
            continue;

        for (ill v : graph[curr_par])
        {
            if (dist_source[v.fi] > dist_source[curr_par] + v.se)
            {
                dist_source[v.fi] = dist_source[curr_par] + v.se;
                vlist.emplace(v.fi, dist_source[v.fi]);
            }
        }
    }
}

void not_main()
{
    cin >> n >> m;
    int a, b;
    ll w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
    }
    dijkstra(1);

    for (int i = 1; i <= n; ++i)
        cout << dist_source[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
}