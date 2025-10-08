#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int nmax = 1e5 + 10;
int tour[2 * nmax], st[nmax], en[nmax];
vector<int> graph[nmax];
int n, m = 0;

void add(int u)
{
    tour[++m] = u;
    en[u] = m;
}

void dfs(int u, int par)
{
    add(u);
    st[u] = m;
    for (int v : graph[u])
    {
        if (v != par)
            dfs(v, u);
    }
    if (u != 1)
        add(par);
}

void not_main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i)
        cout << tour[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}