#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e4 + 10;

struct EDGE
{
    int from;
    int to;
    int weight;
};
vector<EDGE> edges;

inline bool customSort(EDGE &a, EDGE &b)
{
    return (a.weight < b.weight);
}

int n, m;

int dsu_par[nmax];
int subtree_sz[nmax];
ll res = 0;

int find_root(int u)
{
    if (dsu_par[u] == u)
        return u;
    return dsu_par[u] = find_root(dsu_par[u]);
}

bool dsu(int a, int b)
{
    a = find_root(a);
    b = find_root(b);

    if (a == b)
        return true;
    else
    {
        if (subtree_sz[a] < subtree_sz[b])
            swap(a, b);
        subtree_sz[a] += subtree_sz[b];
        dsu_par[b] = a;
        return false;
    }
}

void not_main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), customSort);

    for (int i = 1; i <= n; ++i)
    {
        dsu_par[i] = i;
        subtree_sz[i] = 1;
    }

    for (EDGE e : edges)
    {
        int u = e.from;
        int v = e.to;

        if (!dsu(u, v))
            res += e.weight;
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GRAPH.INP", "r"))
    {
        freopen("GRAPH.INP", "r", stdin);
        freopen("GRAPH.OUT", "w", stdout);
    }
    not_main();
    return 0;
}