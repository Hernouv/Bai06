#include <bits/stdc++.h>
using namespace std;

vector<int> graph[3001];
set<int> v[2];
int id = 0;
bool visited[3001];

void dfs(int i)
{
    visited[i] = true;
    v[id].insert(i);
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
    freopen("DFSMVLT.INP", "r", stdin);
    freopen("DFSMVLT.OUT", "w", stdout);
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
            dfs(i);
            if (v[0].size() > v[1].size())
            {
                v[1].clear();
                id = 1;
            }
            else if (v[1].size() > v[0].size())
            {
                v[0].clear();
                id = 0;
            }
        }
    }
    int id = 0;
    if (v[0].size() < v[1].size())
        id = 1;
    cout << v[id].size() << '\n';
    for (auto x : v[id])
        cout << x << ' ';
    return 0;
}