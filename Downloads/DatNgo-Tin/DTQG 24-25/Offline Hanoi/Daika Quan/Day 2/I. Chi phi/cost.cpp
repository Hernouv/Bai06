#include <bits/stdc++.h>
using namespace std;

#define MASK(k) (1LL << (k))
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second

const int nmax = 1e6 + 10;

int n, q, m, w[nmax], st[nmax], ed[nmax], euler[nmax], d[nmax];
int cur, depth[nmax], Time, start[nmax];
ii rmq[nmax][25];
vi g[nmax];
void dfs(int u, int p)
{
    st[u] = ++cur;
    euler[cur] = u;
    depth[u] = depth[p] + 1;
    start[u] = ++Time;
    rmq[Time][0] = {depth[u], u};
    for (int v : g[u])
    {
        if (v == p)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        rmq[++Time][0] = {depth[u], u};
    }
    ed[u] = cur;
}

void buildRMQ()
{
    int lim = __lg(Time);
    For(k, 1, lim)
    {
        int tmp = MASK(k - 1);
        For(i, 1, Time)
        {
            rmq[i][k] = min(rmq[i][k - 1], rmq[i + tmp][k - 1]);
        }
    }
}

int lca(int u, int v)
{
    int Left = start[u], Right = start[v];
    if (Left > Right)
        swap(Left, Right);
    int k = __lg(Right - Left + 1);
    return min(rmq[Left][k], rmq[Right - MASK(k) + 1][k]).se;
}

int dist(int u, int v)
{
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

int a[nmax];
bool cmp(int x, int y)
{
    return st[x] < st[y];
}

void not_main()
{
    cin >> n >> q;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    buildRMQ();
    while (q--)
    {
        int k;
        cin >> k;
        For(i, 1, k)
        {
            cin >> a[i];
        }
        sort(a + 1, a + k + 1, cmp);
        int res = 0;
        For(i, 1, k - 1)
        {
            res += dist(a[i], a[i + 1]);
        }
        res += dist(a[1], a[k]);
        cout << res / 2 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}