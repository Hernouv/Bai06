#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
const long long outbound = 1e18;
vector<ii> coinVal;
vector<ii> graph[5050];
long long dsource[5050][2];
priority_queue<ii, vector<ii>, greater<ii>> vertices_list;
int m, n, k;
int a, b;

void dijkstra(int start)
{
    vertices_list.empty();
    int it;
    if (start == a)
        it = 0;
    else if (start == b)
        it = 1;

    dsource[start][it] = 0;
    vertices_list.emplace(start, 0);
    while (!vertices_list.empty())
    {
        int index = vertices_list.top().first;
        int min_dist = vertices_list.top().second;
        vertices_list.pop();
        if (dsource[index][it] < min_dist)
            continue;
        for (auto x : graph[index])
        {
            int curr_indx = x.first;
            int immd_dist = x.second;
            if (dsource[curr_indx][it] > dsource[index][it] + immd_dist)
            {
                dsource[curr_indx][it] = dsource[index][it] + immd_dist;
                vertices_list.emplace(curr_indx, dsource[curr_indx][it]);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // ofreopen("MONEY.INP", "r", stdin);
    // freopen("MONEY.OUT", "w", stdout);

    for (int i = 0; i < 5050; ++i)
        dsource[i][0] = dsource[i][1] = outbound;

    cin >> n >> m >> k;
    cin >> a >> b;

    int v, w;
    for (int i = 1; i <= k; ++i)
    {
        cin >> v >> w;
        coinVal.emplace_back(v, w);
    }

    int s, f, val;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> f >> val;
        graph[s].emplace_back(f, val);
        graph[f].emplace_back(s, val);
    }

    dijkstra(a);
    dijkstra(b);

    long long res = outbound;
    for (auto x : coinVal)
        res = min(res, dsource[x.first][0] + dsource[x.first][1] + x.second);
    cout << res;
    return 0;
}