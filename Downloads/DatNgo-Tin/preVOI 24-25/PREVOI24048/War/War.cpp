#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second
#define whole(__) __.begin(), __.end()

const int nmax = 2e3 + 5;

int T, n, m;
vector<ill> adj[nmax];
struct Edge
{
    int u, v, w;
    bool operator!=(const Edge &other) const
    {
        return (u != other.u or v != other.v);
    }
};
vector<Edge> edgelist, edgelist2;

inline bool cond(Edge &a, Edge &b)
{
    if (a.u == b.v)
        return a.v < b.v;
    return (a.u < b.u);
}

vector<vector<ll>> res;
void not_main()
{
    cin >> T >> n >> m;
    res.resize(n + 3, vector<ll>(n + 3, (ll)2e18));
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        edgelist.push_back({u, v, w});
    }

    sort(whole(edgelist), cond);
    for (Edge e : edgelist)
    {
        if (edgelist2.empty())
        {
            edgelist2.push_back(e);
            continue;
        }
        Edge t_e = edgelist2.back();
        if (e != t_e)
        {
            edgelist2.push_back(e);
            continue;
        }
        edgelist2.back().w += e.w;
    }

    for (Edge e : edgelist2)
    {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }

    for (int msk = 1; msk < (1 << n); ++msk)
    {
        vector<int> bit1, bit0;
        for (int it = 0; it < n; ++it)
        {
            if ((msk >> it) & 1)
                bit1.push_back(it + 1);
            else
                bit0.push_back(it + 1);
        }

        ll tcost = 0;
        for (int b : bit0)
        {
            for (ill v : adj[b])
                if ((msk >> v.fi) & 1)
                    tcost += v.se;
        }

        for (int b0 : bit0)
            for (int b1 : bit1)
            {
                res[b0][b1] = min(res[b0][b1], tcost);
                res[b1][b0] = min(res[b1][b0], tcost);
            }
    }

    if (T == 1)
    {
        ll ans = 2e18;
        for (int i = 1; i < n; ++i)
            for (int j = 2; j <= n; ++j)
                ans = min(ans, res[i][j]);
        cout << ans;
    }
    else if (T == 2)
    {
        ll ans = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 2; j <= n; ++j)
                ans += res[i][j] * 2;
        cout << ans;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}