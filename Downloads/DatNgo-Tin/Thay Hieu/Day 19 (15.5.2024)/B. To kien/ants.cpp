#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
typedef pair<int, int> pii;
#define fi first
#define se second

int n, q;
vector<pii> graph[nmax];
int ancestor[18][nmax];
long long dist_source[nmax];
int h[nmax];

void defaultSet()
{
    for (int i = 0; i < nmax; ++i)
    {
        h[i] = 0;
        dist_source[i] = 0;
        graph[i].clear();
        for (int j = 0; j < 18; ++j)
            ancestor[j][i] = -1;
    }
}

void dfs_binAncestor(int st)
{
    for (pii v : graph[st])
    {
        if (ancestor[0][v.fi] == -1)
        {
            h[v.fi] = h[st] + 1;
            dist_source[v.fi] = dist_source[st] + v.se;
            ancestor[0][v.fi] = st;
            for (int i = 1; i < 18; ++i)
                ancestor[i][v.fi] = ancestor[i - 1][ancestor[i - 1][v.fi]];
            dfs_binAncestor(v.fi);
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
    while (cin >> n)
    {
        if (!n)
            return;

        defaultSet();

        int A, L;
        for (int i = 1; i < n; ++i)
        {
            cin >> A >> L;
            graph[i].emplace_back(A, L);
            graph[A].emplace_back(i, L);
        }

        h[1] = 1;
        ancestor[0][1] = -2;
        dist_source[1] = 0;
        dfs_binAncestor(1);

        cin >> q;
        int a, b;
        for (int i = 1; i <= q; ++i)
        {
            cin >> a >> b;
            int common_par = lca(a, b);
            cout << dist_source[a] + dist_source[b] - 2 * dist_source[common_par] << ' ';
        }
        cout << '\n';
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