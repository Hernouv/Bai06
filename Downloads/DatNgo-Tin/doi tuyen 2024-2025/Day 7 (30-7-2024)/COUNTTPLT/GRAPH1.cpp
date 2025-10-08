#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;

int n, m;
vector<int> g[nmax];
bool visited[nmax];
vector<int> con_compo[nmax];
int id = 0;

void dfs(int u)
{
    visited[u] = true;
    con_compo[id].push_back(u);
    for (int v : g[u])
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
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++id;
            dfs(i);
            sort(con_compo[id].begin(), con_compo[id].end());
        }
    }

    cout << id << '\n';
    for (int i = 1; i <= id; ++i)
    {
        for (int v : con_compo[i])
            cout << v << ' ';
        cout << '\n';
    }
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