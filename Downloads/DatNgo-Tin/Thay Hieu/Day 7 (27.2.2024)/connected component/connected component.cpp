#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
int n, m;
vector<int> graph[nmax];
bool visited[nmax];
int cnt = 0;

void dfs(int in)
{
    visited[in] = true;
    for (int v : graph[in])
    {
        if (!visited[v])
            dfs(v);
    }
}

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++cnt;
            dfs(i);
        }
    }
    cout << cnt;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}