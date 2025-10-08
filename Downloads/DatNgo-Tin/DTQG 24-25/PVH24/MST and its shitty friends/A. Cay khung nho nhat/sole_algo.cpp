#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

const int nmax = 5e5 + 10;

int n, m;
int root[nmax];
int sz[nmax];

struct node
{
    int id, u, v, w;
};
vector<node> edges;

int find_root(int u)
{
    return (root[u] == u ? u : find_root(root[u]));
}

bool conn(int u, int v)
{
    int ru = find_root(root[u]);
    int rv = find_root(root[v]);

    if (ru != rv)
    {
        if (sz[ru] < sz[rv])
            swap(ru, rv);
        root[rv] = ru;
        sz[ru] += sz[rv];
        return true;
    }
    return false;
}

void not_main()
{
    int s;
    cin >> s;

    cin >> n >> m;
    int tu, tv, tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        edges.push_back({i, tu, tv, tw});
    }
    sort(whole(edges), [](node &a, node &b)
         { return (a.w < b.w); });

    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (conn(u, v))
        {
            cout << edges[i].id << ' ';
            if (++cnt == n - 1)
                return;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mst.inp", "r"))
    {
        freopen("mst.inp", "r", stdin);
        freopen("mst.out", "w", stdout);
    }
    not_main();
    return 0;
}