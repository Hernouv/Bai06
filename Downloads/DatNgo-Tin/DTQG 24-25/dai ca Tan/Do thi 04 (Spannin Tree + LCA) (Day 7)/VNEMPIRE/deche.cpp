#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole_arr(_name, _sz) _name + 1, _name + _sz + 1

const int nmax = 1e5 + 10;

int n, m = 0;
ll res = 0;

struct planet
{
    int x, y, z, id;
} planets[nmax];

struct edge
{
    int dist, id1, id2;
} edges[3 * nmax];

int d_cal(int na, int nb)
{
    int t1 = abs(planets[na].x - planets[nb].x);
    int t2 = abs(planets[na].y - planets[nb].y);
    int t3 = abs(planets[na].z - planets[nb].z);
    return min({t1, t2, t3});
}

void add_edges()
{
    for (int i = 1; i < n; ++i)
        edges[++m] = {d_cal(i, i + 1), planets[i].id, planets[i + 1].id};
}

int root[nmax];
int sz[nmax];

int find_root(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

bool dsu(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u, v);
    root[v] = u;
    sz[u] += sz[v];
    return true;
}

void not_main()
{
    cin >> n;
    int tx, ty, tz;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tx >> ty >> tz;
        planets[i] = {tx, ty, tz, i};
    }

    sort(whole_arr(planets, n), [](planet &a, planet &b)
         { return (a.x < b.x); });
    add_edges();
    sort(whole_arr(planets, n), [](planet &a, planet &b)
         { return (a.y < b.y); });
    add_edges();
    sort(whole_arr(planets, n), [](planet &a, planet &b)
         { return (a.z < b.z); });
    add_edges();

    sort(whole_arr(edges, m), [](edge &a, edge &b)
         { return (a.dist < b.dist); });

    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (dsu(edges[i].id1, edges[i].id2))
            res += (ll)edges[i].dist;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}