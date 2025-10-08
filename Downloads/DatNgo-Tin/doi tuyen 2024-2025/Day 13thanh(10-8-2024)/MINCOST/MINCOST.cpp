#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;
vector<ii> graph[nmax];
int h[nmax];
ll cost[nmax];
int ancestor[18][nmax];
int n, q;

void dfs(int par, int u)
{
    for (ii v : graph[u])
    {
        if (v.fi == par)
            continue;
        h[v.fi] = h[u] + 1;
        cost[v.fi] = cost[u] + v.se;
        ancestor[0][v.fi] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ancestor[i][v.fi] = ancestor[i - 1][ancestor[i - 1][v.fi]];
        dfs(u, v.fi);
    }
}

int lca(int a, int b)
{
    if (h[a] != h[b])
    {
        if (h[a] < h[b])
            swap(a, b);
        int diff = h[a] - h[b];
        for (int i = 0; (1 << i) <= diff; ++i)
            if ((diff >> i) & 1)
                a = ancestor[i][a];
    }
    if (a == b)
        return a;
    int t = __lg(h[a]);
    for (int i = t; i >= 0; --i)
        if (ancestor[i][a] != ancestor[i][b])
        {
            a = ancestor[i][a];
            b = ancestor[i][b];
        }
    return ancestor[0][a];
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
    dfs(0, 1);

    for (int i = 1; i <= q; ++i)
    {
        cin >> tu >> tv;
        cout << cost[tu] + cost[tv] - 1LL * 2 * cost[lca(tu, tv)] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MINCOST.INP", "r"))
    {
        freopen("MINCOST.INP", "r", stdin);
        freopen("MINCOST.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
