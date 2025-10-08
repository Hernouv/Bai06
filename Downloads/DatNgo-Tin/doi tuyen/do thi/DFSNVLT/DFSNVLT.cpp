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

void display()
{
    for (auto x : vertices)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("DFSNVLT.INP", "r", stdin);
    // freopen("DFSNVLT.OUT", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            vertices.clear();
            dfs(i);
            display();
        }
    }
    return 0;
}