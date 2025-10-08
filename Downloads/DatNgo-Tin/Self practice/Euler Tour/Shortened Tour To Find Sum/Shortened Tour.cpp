#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int st[100010], en[100010];
int tour[200010];
int n, m = 0, root = 1;

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
}

void not_main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(root, 0);
    for (int i = 1; i <= m; ++i)
        cout << tour[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}