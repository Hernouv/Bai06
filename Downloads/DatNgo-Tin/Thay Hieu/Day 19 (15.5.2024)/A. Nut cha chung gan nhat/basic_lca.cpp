#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, k, m;
vector<int> graph[nmax];
int ancestor[18][nmax];
int h[nmax];

void dfs_binAncestor(int st)
{
    for (int v : graph[st])
    {
        if (!ancestor[0][v])
        {
            h[v] = h[st] + 1;
            ancestor[0][v] = st;
            for (int i = 1; i < 18; ++i)
                ancestor[i][v] = ancestor[i - 1][ancestor[i - 1][v]];
            dfs_binAncestor(v);
        }
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] < h[v])
            swap(u, v);

        int d = h[u] - h[v];
        for (int i = 0; (1 << i) <= d; ++i)
            if ((d >> i) & 1)
                u = ancestor[i][u];
    }

    if (u == v)
        return u;

    int t = __lg(h[u]);
    for (int i = t; i >= 0; --i)
        if (ancestor[i][u] != ancestor[i][v])
        {
            u = ancestor[i][u];
            v = ancestor[i][v];
        }

    return ancestor[0][u];
}

void not_main()
{
    cin >> n >> k >> m;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    h[k] = 1;
    ancestor[0][k] = -1;
    dfs_binAncestor(k);

    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("lca.inp", "r"))
    {
        freopen("lca.inp", "r", stdin);
        freopen("lca.out", "w", stdout);
    }
    not_main();
    return 0;
}