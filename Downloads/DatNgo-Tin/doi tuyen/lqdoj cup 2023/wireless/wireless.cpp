#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
vector<ii> graph[500010];
long long dist_source[500010];
vector<int> working[100010];
bool visited[500010];
int n, q;

void reset()
{
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
}

void dfs(int s)
{
    visited[s] = true;
    for (auto v : graph[s])
    {
        if (!visited[v.first])
        {
            dist_source[v.first] = dist_source[s] + v.second;
            dfs(v.first);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("wireless.inp", "r", stdin);
    freopen("wireless.out", "w", stdout);
    cin >> n >> q;
    int u, v, val;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v >> val;
        graph[u].emplace_back(v, val);
        graph[v].emplace_back(u, val);
    }
    int no_, ws;
    for (int i = 1; i <= q; ++i)
    {
        cin >> no_;
        for (int j = 1; j <= no_; ++j)
        {
            cin >> ws;
            working[i].push_back(ws);
        }
        long long res = 1e18;
        for (int j = 1; j <= n; ++j)
        {
            reset();
            dist_source[j] = 0;
            dfs(j);
            long long sum = 0;
            for (int x : working[i])
                sum += dist_source[x];
            res = min(res, sum);
        }
        cout << res << '\n';
    }
    return 0;
}