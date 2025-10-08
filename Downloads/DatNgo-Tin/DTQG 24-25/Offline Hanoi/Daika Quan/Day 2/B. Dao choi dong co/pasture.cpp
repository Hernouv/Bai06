#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e3 + 10;

int n, q;
vector<ii> graph[nmax];
int ances[12][nmax], h[nmax], d[nmax];

void dfs(int par, int u)
{
    for (ii v : graph[u])
    {
        if (v.fi == par)
            continue;
        h[v.fi] = h[u] + 1;
        d[v.fi] = d[u] + v.se;
        ances[0][v.fi] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[i][v.fi] = ances[i - 1][ances[i - 1][v.fi]];
        dfs(u, v.fi);
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
    cin >> n >> q;
    int tu, tv, tw;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].push_back({tv, tw});
        graph[tv].push_back({tu, tw});
    }
    h[1] = 1;
    dfs(0, 1);
    int p1, p2;
    for (int i = 1; i <= q; ++i)
    {
        cin >> p1 >> p2;
        int common_par = lca(p1, p2);
        cout << d[p1] + d[p2] - 2 * d[common_par] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}