#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
set<int> vertices;
bool visited[3001];

void dfs(int i)
{
    visited[i] = true;
    vertices.insert(i);
    for (auto x : graph[i])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("DFSLVLT.INP", "r", stdin);
    // freopen("DFSLVLT.OUT", "w", stdout);
    int m, n, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    dfs(p);
    for (auto x : vertices)
        if (x != p)
            cout << x << ' ';
    return 0;
}