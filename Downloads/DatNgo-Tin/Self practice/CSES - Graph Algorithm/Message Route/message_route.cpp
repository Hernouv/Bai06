#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m;
vector<int> graph[nmax];
int parent[nmax];
int h[nmax];

queue<int> scanlist;

void bfs(int u)
{
    h[u] = 0;
    parent[u] = -1;

    scanlist.push(u);
    while (!scanlist.empty())
    {
        int currV = scanlist.front();
        scanlist.pop();
        for (int v : graph[currV])
        {
            if (!parent[v])
            {
                parent[v] = currV;
                h[v] = h[currV] + 1;
                scanlist.push(v);
            }
        }
    }
}

stack<int> route;

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    if (!h[n])
    {
        cout << "IMPOSSIBLE";
        return;
    }

    int backtrack = n;

    while (backtrack != -1)
    {
        route.push(backtrack);
        backtrack = parent[backtrack];
    }

    cout << route.size() << '\n';
    while (!route.empty())
    {
        cout << route.top() << ' ';
        route.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}