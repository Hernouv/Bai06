#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
bool visited[3001];
int par[3001];

void dfs(int start)
{
    visited[start] = true;
    for (auto v : graph[start])
    {
        if (!visited[v])
        {
            par[v] = start;
            dfs(v);
        }
    }
}

void trace(int finish)
{
    cout << finish << ' ';
    int p = par[finish];
    while (p)
    {
        cout << p << ' ';
        p = par[p];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("DFSSTVLT.INP", "r", stdin);
    freopen("DFSSTVLT.OUT", "w", stdout);
    int n, m, start, finish;
    cin >> n >> m >> start >> finish;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    par[start] = 0;
    dfs(start);
    if (!visited[finish])
        cout << -1;
    else
        trace(finish);
    return 0;
}