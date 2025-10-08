#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
bool visited[3001];

void dfs(int start)
{
    visited[start] = true;
    for (auto v : graph[start])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("DFSBRIDGE.INP", "r", stdin);
    freopen("DFSBRIDGE.OUT", "w", stdout);
    int n, m, start, finish;
    cin >> n >> m >> start >> finish;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = -1;
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    cout << cnt;
    return 0;
}