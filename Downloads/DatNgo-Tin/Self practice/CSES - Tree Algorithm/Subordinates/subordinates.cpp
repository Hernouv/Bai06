#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
int subordinates[nmax];
bool visited[nmax];
int n;

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        dfs(v);
        subordinates[u] += (subordinates[v] + 1);
    }
}

void not_main()
{
    cin >> n;
    int t;
    for (int i = 2; i <= n; ++i)
    {
        cin >> t;
        graph[t].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i);
    for (int i = 1; i <= n; ++i)
        cout << subordinates[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}