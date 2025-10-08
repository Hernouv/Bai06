#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define whole(_name) _name.begin(), _name.end()

const int nmax = 5e5 + 10;

int n, m, k;
int root[nmax];
int sz[nmax];
bool market[nmax];

struct node
{
    int u, v;
    ll w;
};
vector<node> edges;

int find_root(int u)
{
    return (root[u] == u ? u : root[u] = find_root(root[u]));
}

bool conn(int u, int v)
{
    int ru = find_root(root[u]);
    int rv = find_root(root[v]);

    if (ru == rv or (market[ru] and market[rv]))
        return false;

    if (sz[ru] < sz[rv])
        swap(ru, rv);
    root[rv] = ru;
    sz[ru] += sz[rv];
    if (market[rv])
        market[ru] = true;
    return true;
}

void not_main()
{
    cin >> n >> m >> k;
    int tnum;
    for (int i = 1; i <= k; ++i)
    {
        cin >> tnum;
        market[tnum] = true;
    }

    int tu, tv;
    ll tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        edges.push_back({tu, tv, tw});
    }
    sort(whole(edges), [](node &a, node &b)
         { return (a.w < b.w); });

    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }

    ll res = 0;
    for (int i = 0; i < m; ++i)
    {
        int u = edges[i].u, v = edges[i].v;
        ll w = edges[i].w;
        if (conn(u, v))
            res += w;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!market[find_root(i)])
        {
            cout << -1;
            return;
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRADE.INP", "r"))
    {
        freopen("TRADE.INP", "r", stdin);
        freopen("TRADE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}