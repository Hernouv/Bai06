#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;

int n, m;
vector<int> g[nmax];
bool visited[nmax];
bool cycle = false;

void dfs(int par, int u)
{
    visited[u] = true;
    for (int v : g[u])
    {
        if (v != par)
        {
            if (!visited[v])
                dfs(u, v);
            else
            {
                cycle = true;
                return;
            }
        }
    }
}

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(0, i);
            if (cycle)
            {
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GRAPH.INP", "r"))
    {
        freopen("GRAPH.INP", "r", stdin);
        freopen("GRAPH.OUT", "w", stdout);
    }
    not_main();
    return 0;
}