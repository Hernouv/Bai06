#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e2 + 10;
const int vmax = 1e4 + 10;

char maze[nmax][nmax];
int id[nmax][nmax];
int m, n, st;
vector<int> graph[vmax];
bool visited[vmax];
int parent[vmax];
stack<int> path;

void dfs(int in)
{
    visited[in] = true;
    for (int v : graph[in])
    {
        if (!visited[v])
        {
            parent[v] = in;
            dfs(v);
        }
    }
}

void retrace(int inp)
{
    cout << "YES" << '\n';
    while (inp != -1)
    {
        path.push(inp);
        inp = parent[inp];
    }
    while (!path.empty())
    {
        int pos_in_row = path.top() % n;
        cout << (path.top() / n + bool(pos_in_row)) << ' ' << (pos_in_row ? pos_in_row : n) << '\n';
        path.pop();
    }
}

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '.')
                id[i][j] = n * (i - 1) + j;
        }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (maze[i][j] == 'E')
            {
                id[i][j] = n * (i - 1) + j;
                st = n * (i - 1) + j;
                break;
                break;
            }
        }

    // for (int i = 1; i <= m; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //         cout << id[i][j] << '\t';
    //     cout << '\n';
    // }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (id[i][j])
            {
                if (id[i - 1][j])
                    graph[id[i - 1][j]].push_back(id[i][j]);
                if (id[i + 1][j])
                    graph[id[i + 1][j]].push_back(id[i][j]);
                if (id[i][j - 1])
                    graph[id[i][j - 1]].push_back(id[i][j]);
                if (id[i][j + 1])
                    graph[id[i][j + 1]].push_back(id[i][j]);
            }
    parent[st] = -1;
    dfs(st);
    for (int i = 1; i <= m; ++i)
    {
        if (parent[id[i][1]])
        {
            retrace(id[i][1]);
            return;
        }
        if (parent[id[i][n]])
        {
            retrace(id[i][n]);
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (parent[id[1][i]])
        {
            retrace(id[1][i]);
            return;
        }
        if (parent[id[m][i]])
        {
            retrace(id[m][i]);
            return;
        }
    }
    cout << "NO";
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