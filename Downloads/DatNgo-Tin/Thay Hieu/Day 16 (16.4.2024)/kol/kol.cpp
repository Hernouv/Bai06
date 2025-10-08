#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m, z;

int segTree[4 * nmax];
int tree_lazy[4 * nmax];

void construct()
{
    for (int i = 1; i <= 4 * n; ++i)
        segTree[i] = m;
}

void lazy(int id)
{
    int t = tree_lazy[id];
    tree_lazy[id] = 0;

    segTree[id * 2] -= t;
    tree_lazy[id * 2] += t;

    segTree[id * 2 + 1] -= t;
    tree_lazy[id * 2 + 1] += t;
}

void updateRange(int L, int R, int val, int id = 1, int l = 1, int r = n)
{
    if (r < L or l > R)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] -= val;
        tree_lazy[id] += val;
        return;
    }

    lazy(id);
    int mid = (l + r) / 2;
    updateRange(L, R, val, id * 2, l, mid);
    updateRange(L, R, val, id * 2 + 1, mid + 1, r);
    segTree[id] = min(segTree[id * 2], segTree[id * 2 + 1]);
}

int getMin(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (r < L or l > R)
        return (int)1e9 + 7;
    if (L <= l and r <= R)
        return segTree[id];

    lazy(id);
    int mid = (l + r) / 2;
    return min(getMin(L, R, id * 2, l, mid), getMin(L, R, id * 2 + 1, mid + 1, r));
}

void not_main()
{
    cin >> n >> m >> z;
    construct();
    int u, v, w;
    for (int i = 1; i <= z; ++i)
    {
        cin >> u >> v >> w;
        if (w <= getMin(u, v - 1))
        {
            cout << "T\n";
            updateRange(u, v - 1, w);
        }
        else
            cout << "N\n";
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("kol.inp", "r"))
    {
        freopen("kol.inp", "r", stdin);
        freopen("kol.out", "w", stdout);
    }
    clock_t timed = clock();
    not_main();
    timed = clock() - timed;
    // cout << timed / CLOCKS_PER_SEC;
    return 0;
}