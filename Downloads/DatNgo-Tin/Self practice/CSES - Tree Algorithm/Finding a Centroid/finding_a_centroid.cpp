#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
int n;
vector<int> graph[nmax];
int subtree_sz[nmax];

void dfs(int u, int par)
{
    subtree_sz[u] = 1;
    for (int v : graph[u])
    {
        if (v != par)
        {
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

int getCentroid(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par and subtree_sz[v] * 2 > n)
            return getCentroid(v, u);
    }
    return u;
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
    dfs(1, 0);
    cout << getCentroid(1, 0);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}