#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

int n;
vector<int> graph[nmax];
int parent[nmax];
queue<int> scanlist;
int diam_point1, diam_point2;
int h1[nmax], h2[nmax];

void bfs(int u)
{
    scanlist.push(u);
    while (!scanlist.empty())
    {
        int currV = scanlist.front();
        diam_point1 = currV;
        scanlist.pop();
        for (int v : graph[currV])
        {
            if (v != parent[currV])
            {
                parent[v] = currV;
                scanlist.push(v);
            }
        }
    }

    fill(parent + 1, parent + n + 1, 0);
    scanlist.push(diam_point1);
    while (!scanlist.empty())
    {
        int currV = scanlist.front();
        diam_point2 = currV;
        scanlist.pop();
        for (int v : graph[currV])
        {
            if (v != parent[currV])
            {
                parent[v] = currV;
                scanlist.push(v);
            }
        }
    }
}

void dfs_h1(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
            h1[v] = h1[u] + 1;
            dfs_h1(v, u);
        }
    }
}

void dfs_h2(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
            h2[v] = h2[u] + 1;
            dfs_h2(v, u);
        }
    }
}

void not_main()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    dfs_h1(diam_point1, 0);
    dfs_h2(diam_point2, 0);

    for (int i = 1; i <= n; ++i)
        cout << max(h1[i], h2[i]) << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}