#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e4 + 10;
const ll outbound = 1e18;

struct EDGE
{
    int from;
    int to;
    ll weight;
};
vector<EDGE> edges;

int n, m, s;
ll dist_src[nmax];
bool inf_loop[nmax];

void not_main()
{
    cin >> n >> m >> s;
    int a, b;
    ll c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    for (int i = 1; i < nmax; ++i)
        dist_src[i] = outbound;
    dist_src[s] = 0;

    for (int i = 1; i <= n; ++i)
        for (EDGE edge : edges)
        {
            int u = edge.from;
            int v = edge.to;
            ll w = edge.weight;
            if (dist_src[u] != outbound and dist_src[v] > dist_src[u] + w)
                dist_src[v] = dist_src[u] + w;
        }

    for (int i = 1; i <= n; ++i)
        for (EDGE edge : edges)
        {
            int u = edge.from;
            int v = edge.to;
            ll w = edge.weight;
            if (dist_src[u] != outbound and dist_src[v] > dist_src[u] + w)
            {
                dist_src[v] = dist_src[u] + w;
                inf_loop[v] = 1;
            }
        }

    for (int i = 1; i <= n; ++i)
    {
        if (inf_loop[i])
            cout << -2 << '\n';
        else if (dist_src[i] == outbound)
            cout << -1 << '\n';
        else
            cout << dist_src[i] << '\n';
    }
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