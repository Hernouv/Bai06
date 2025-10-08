#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;

int testcase, dupli;

int n, q;
vector<int> graph[nmax];
int ances[12][nmax], h[nmax];
int tv, m;
int p1, p2;

void dfs(int par, int u)
{
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        ances[0][v] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[i][v] = ances[i - 1][ances[i - 1][v]];
        dfs(u, v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] > h[v])
            swap(u, v);
        int diff = h[v] - h[u];
        for (int it = 0; (1 << it) <= diff; ++it)
            if ((diff >> it) & 1)
                v = ances[it][v];
    }
    if (u == v)
        return u;
    int t = __lg(h[u]);
    for (int i = t; i >= 0; --i)
    {
        if (ances[i][u] != ances[i][v])
        {
            u = ances[i][u];
            v = ances[i][v];
        }
    }
    return ances[0][u];
}

void not_main()
{
    memset(ances, 0, sizeof ances);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        graph[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            cin >> tv;
            graph[i].push_back(tv);
            graph[tv].push_back(i);
        }
    }

    dfs(0, 1);
    cin >> q;
    cout << "Case " << dupli - testcase << ":\n";
    for (int i = 1; i <= q; ++i)
    {
        cin >> p1 >> p2;
        cout << lca(p1, p2) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> testcase;
    dupli = testcase;
    while (testcase--)
        not_main();
    return 0;
}