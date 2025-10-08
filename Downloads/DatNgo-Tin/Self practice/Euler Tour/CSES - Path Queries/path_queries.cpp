#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
int n, q;
vector<int> tour;
int tour_sz;
int st[nmax], en[nmax];
long long val[nmax];

int dfs_tour(int u, int par)
{
    tour.push_back(u);
    for (int v : graph[u])
    {
        if (v != par)
            tour.push_back(dfs_tour(v, u));
    }
    return u;
}

void create_tour()
{
    tour.push_back(0);
    dfs_tour(1, 0);
    tour.push_back(1);

    for (int i = 1; i <= tour_sz; ++i)
    {
        if (!st[tour[i]])
            st[tour[i]] = i;
        else
            en[tour[i]] = i;
    }
}

long long fenwickTree[nmax * 4];

void update(int pos, long long diff)
{
    while (pos <= tour_sz)
    {
        fenwickTree[pos] += diff;
        pos += (pos & (-pos));
    }
}

void construct()
{
    for (int i = 1; i <= n; ++i)
    {
        update(st[i], val[i]);
        update(en[i], -val[i]);
    }
}

long long getSum(int u)
{
    long long ret = 0;
    while (u > 0)
    {
        ret += fenwickTree[u];
        u -= (u & (-u));
    }
    return ret;
}

void not_main()
{
    cin >> n >> q;
    tour_sz = n * 2;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    create_tour();
    construct();

    int query_type, pos, x;
    long long va;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> pos >> va;
            update(st[pos], va - val[pos]);
            update(en[pos], val[pos] - va);
            val[pos] = va;
        }
        else
        {
            cin >> x;
            cout << getSum(st[x]) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}