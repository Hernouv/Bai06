#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
int n, k;

vector<int> graph[nmax];
int val[nmax];

void dfs(int par, int u)
{
    for (int v : graph[u])
        if (v != par)
        {
            dfs(u, v);
            val[u] += val[v];
        }
}

void not_main()
{
    cin >> n >> k;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (graph[i].size() == 1)
            val[i] = 1;
    }

    dfs(-1, k);
    cout << val[k];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STEAL.INP", "r"))
    {
        freopen("STEAL.INP", "r", stdin);
        freopen("STEAL.OUT", "w", stdout);
    }
    not_main();
    return 0;
}