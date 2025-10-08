#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

int n, m;
char grid[nmax][nmax];
int id[nmax][nmax];
int start, finish;
bool visited[nmax * nmax];
int parent[nmax * nmax];
vector<int> graph[nmax * nmax];
queue<int> scanlist;

void bfs(int u)
{
    visited[u] = true;
    scanlist.push(u);
    while (!scanlist.empty())
    {
        int currV = scanlist.front();
        scanlist.pop();
        for (int v : graph[currV])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = currV;
                scanlist.push(v);
            }
        }
    }
}

void not_main()
{
    cin >> n >> m;
    for (int i = 0; i <= m + 1; ++i)
        grid[0][i] = grid[n + 1][i] = '#';
    for (int i = 0; i <= n + 1; ++i)
        grid[i][0] = grid[i][m + 1] = '#';

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] != '#')
            {
                id[i][j] = (i - 1) * m + j;
                if (grid[i][j] == 'A')
                    start = id[i][j];
                else if (grid[i][j] == 'B')
                    finish = id[i][j];
            }
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (grid[i][j] != '#')
            {
                if (grid[i + 1][j] != '#')
                    graph[id[i][j]].push_back(id[i + 1][j]);
                if (grid[i][j + 1] != '#')
                    graph[id[i][j]].push_back(id[i][j + 1]);
                if (grid[i - 1][j] != '#')
                    graph[id[i][j]].push_back(id[i - 1][j]);
                if (grid[i][j - 1] != '#')
                    graph[id[i][j]].push_back(id[i][j - 1]);
            }

    bfs(start);

    if (!visited[finish])
    {
        cout << "NO";
        return;
    }

    stack<char> path;
    int backtrack = finish;
    while (backtrack != start)
    {
        if (parent[backtrack] == backtrack - 1)
            path.push('R');
        else if (parent[backtrack] == backtrack + 1)
            path.push('L');
        else if (parent[backtrack] == backtrack - m)
            path.push('D');
        else if (parent[backtrack] == backtrack + m)
            path.push('U');
        backtrack = parent[backtrack];
    }

    cout << "YES\n"
         << path.size() << '\n';
    while (!path.empty())
    {
        cout << path.top();
        path.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}