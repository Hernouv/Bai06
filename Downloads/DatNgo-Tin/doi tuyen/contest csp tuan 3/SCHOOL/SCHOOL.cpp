#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100001];
int dist[100001];
vector<int> best;
int n, m, k, x, temp_best;
void dfs(int idx)
{
    for (auto v : graph[idx])
    {
        if (dist[idx] + v.second <= x)
        {
            temp_best = max(temp_best, v.first);
            dist[v.first] = dist[idx] + v.second;
            dfs(v.first);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("SCHOOL.INP", "r", stdin);
    freopen("SCHOOL.OUT", "w", stdout);

    cin >> n >> m >> k >> x;
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    int test_point;
    for (int i = 1; i <= k; ++i)
    {
        cin >> test_point;
        temp_best = test_point;
        dist[test_point] = 0;
        dfs(test_point);
        best.push_back(temp_best);
    }
    int res = 100001;
    for (auto j : best)
        res = min(res, j);
    cout << res;
    return 0;
}