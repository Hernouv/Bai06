#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
char grid[nmax][nmax];
int id[nmax][nmax], ia;
int n, m;
int cnt;

vector<int> graph[nmax * nmax];
bool visited[nmax * nmax];

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
                id[i][j] = ++ia;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (grid[i][j] == '.')
            {
                if (grid[i][j + 1] == '.')
                    graph[id[i][j]].push_back(id[i][j + 1]);
                if (grid[i + 1][j] == '.')
                    graph[id[i][j]].push_back(id[i + 1][j]);
                if (grid[i][j - 1] == '.')
                    graph[id[i][j]].push_back(id[i][j - 1]);
                if (grid[i - 1][j] == '.')
                    graph[id[i][j]].push_back(id[i - 1][j]);
            }

    for (int i = 1; i <= ia; ++i)
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
    not_main();
    return 0;
}