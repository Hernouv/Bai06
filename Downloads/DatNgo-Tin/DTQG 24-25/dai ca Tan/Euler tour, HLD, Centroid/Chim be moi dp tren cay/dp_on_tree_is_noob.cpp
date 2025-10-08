#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
vector<int> graph[nmax];
long long h[nmax];
long long subtree_sz[nmax];
long long sumDist[nmax];
int n;

void dfs(int u, int par)
{
    subtree_sz[u] = 1;
    for (int v : graph[u])
    {
        if (v != par)
        {
            h[v] = h[u] + 1;
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

void dfs_sum(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
            sumDist[v] = sumDist[u] + n - 2 * subtree_sz[v];
            dfs_sum(v, u);
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
    dfs(1, 0);
    for (int i = 2; i <= n; ++i)
        sumDist[1] += h[i];
    dfs_sum(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << sumDist[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
