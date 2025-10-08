#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m, s, t;
bool visited[nmax];
int parent[nmax];

vector<int> graph[nmax];
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

void not_main()
{
    cin >> n >> m >> s >> t;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(s);
    if (!parent[t])
        cout << -1;
    else
    {
        while (t)
        {
            path.push(t);
            t = parent[t];
        }
        cout << path.size() << '\n';
        while (!path.empty())
        {
            cout << path.top() << ' ';
            path.pop();
        }
    }
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