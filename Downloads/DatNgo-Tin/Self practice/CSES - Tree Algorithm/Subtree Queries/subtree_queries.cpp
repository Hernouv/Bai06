#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

int n, q;
vector<int> graph[nmax];
vector<int> tour;
int st[nmax], en[nmax];
long long val[nmax];
int tour_sz;

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
        if (!st[tour[i]])
            st[tour[i]] = i;
        else
            en[tour[i]] = i;
}

long long segTree[nmax * 8];

void construct(int id = 1, int l = 1, int r = tour_sz)
{
    if (l == r)
    {
        segTree[id] = val[tour[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

void update(int pos, int change_val, int id = 1, int l = 1, int r = tour_sz)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id] = change_val;
        return;
    }
    int mid = (l + r) / 2;
    update(pos, change_val, id * 2, l, mid);
    update(pos, change_val, id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

long long getSum(int L, int R, int id = 1, int l = 1, int r = tour_sz)
{
    if (l > R or r < L)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(L, R, id * 2, l, mid) + getSum(L, R, id * 2 + 1, mid + 1, r);
}

void not_main()
{
    cin >> n >> q;
    tour_sz = n * 2;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    create_tour();
    construct();

    int query_type, s, x;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> s >> x;
            update(st[s], x);
            update(en[s], x);
        }
        else
        {
            cin >> s;
            cout << getSum(st[s], en[s]) / 2 << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}