/**
 *  Created at 14:48, Wednesday October 25, 2023
 *  By ms24 <3
 */
#include <bits/stdc++.h>
using namespace std;

#define task "DWARFS"
#define ll long long
// #define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;
const int lgN = 19;

int n, U, V, res = 0;
int dp[N], f[N], h[N], par[lgN + 1][N];
vector<int> adj[N];

void dfs_lca(int u)
{
    f[u] = 1;
    for (int v : adj[u])
    {
        if (v != par[0][u])
        {
            par[0][v] = u;
            h[v] = h[u] + 1;
            For(i, 1, lgN)
                par[i][v] = par[i - 1][par[i - 1][v]];
            dfs_lca(v);
            maximize(f[u], f[v] + 1);
        }
    }
}

int lca(int u, int v)
{
    if (h[v] > h[u])
        swap(u, v);
    int delta = h[u] - h[v];
    Fod(i, lgN, 0) if ((delta >> i) & 1) u = par[i][u];
    if (u == v)
        return u;
    Fod(i, lgN, 0) if (par[i][u] != par[i][v])
    {
        u = par[i][u];
        v = par[i][v];
    }
    return par[0][u];
}

int dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void dfs(int u, int p = -1)
{
    int mx = 0, st = -1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (h[V] - h[v] != dist(v, V))
        {
            maximize(mx, f[v]);
            continue;
        }
        st = v;
        dfs(v, u);
    }
    dp[u] = mx + dist(u, V) + 1;
    if (st != -1)
    {
        maximize(dp[u], dp[st]);
        maximize(res, min(h[u] + mx, dp[st]));
    }
}

void ttk32()
{
    cin >> n;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    cin >> U >> V;
    h[U] = 1;
    dfs_lca(U);
    dfs(U);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
    return 0;
}