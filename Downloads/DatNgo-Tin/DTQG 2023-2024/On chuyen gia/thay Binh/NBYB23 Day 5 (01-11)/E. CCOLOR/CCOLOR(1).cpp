/**
 *  Created at 07:19, Wednesday November 01, 2023
 *  By ms24 <3
 */
#include <bits/stdc++.h>
using namespace std;

#define task "CCOLOR"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define dist_lca

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;

int n, q;
int tSize;
int a[N];
int parent[N], sz[N];
multiset<int> best[N];
vector<int> adj[N];

#ifdef dist_lca
const int lgN = 18;
int h[N], par[lgN + 1][N];
void dfsLca(int u)
{
    for (int v : adj[u])
    {
        if (v != par[0][u])
        {
            par[0][v] = u;
            h[v] = h[u] + 1;
            For(i, 1, lgN)
                par[i][v] = par[i - 1][par[i - 1][v]];
            dfsLca(v);
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
#endif

void dfsSize(int u, int p)
{
    ++tSize;
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !parent[v])
        {
            dfsSize(v, u);
            sz[u] += sz[v];
        }
}

int getCentroid(int u, int p)
{
    for (int v : adj[u])
        if (v != p && !parent[v] && sz[v] * 2 > tSize)
            return getCentroid(v, u);
    return u;
}

void decompose(int u, int p)
{
    tSize = 0;
    dfsSize(u, 0);
    int centroid = getCentroid(u, 0);
    if (p == 0)
        parent[centroid] = centroid;
    else
        parent[centroid] = p;
    for (int v : adj[centroid])
        if (!parent[v])
            decompose(v, centroid);
}

void update(int v)
{
    int u = v;
    a[u] = 1 - a[u];
    int w = a[u];
    while (1)
    {
        if (w)
            best[u].insert(dist(u, v));
        else
            best[u].erase(best[u].find(dist(u, v)));
        if (u == parent[u])
            break;
        u = parent[u];
    }
}

int get(int v)
{
    int res = n + 1;
    int u = v;
    while (1)
    {
        minimize(res, dist(u, v) + *best[u].begin());
        if (u == parent[u])
            break;
        u = parent[u];
    }
    return res;
}

void ttk32()
{
    cin >> n;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsLca(1);
    decompose(1, 0);

    For(i, 1, n) best[i].insert(n + 1);
    cin >> q;
    while (q--)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
            update(x);
        else
        {
            int ans = get(x);
            if (ans > n)
                ans = -1;
            cout << ans << '\n';
        }
    }
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