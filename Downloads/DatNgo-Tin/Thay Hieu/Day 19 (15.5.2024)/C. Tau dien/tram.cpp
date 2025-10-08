#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m, res = 0;
vector<int> graph[nmax];
int ancestor[18][nmax];
int h[nmax];
int val[nmax];

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

void dfs_proc(int st)
{
    for (int v : graph[st])
    {
        if (v != ancestor[0][st])
        {
            dfs_proc(v);
            val[st] += val[v];
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

    h[1] = 1;
    ancestor[0][1] = -1;
    dfs_binAncestor(1);

    cin >> m;
    int s, e;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> e;
        int common_par = lca(s, e);
        val[s] += 1, val[e] += 1;
        val[common_par] -= 2;
    }
    dfs_proc(1);

    // for (int i = 2; i <= n; ++i)
    //     cout << val[i] << ' ';

    for (int i = 2; i <= n; ++i)
        if (val[i] <= 0)
            ++res;
    cout << res;
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