#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m;
int a[nmax];
int segTree[4 * nmax];
int tree_lazy[4 * nmax];

void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        segTree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = min(segTree[id * 2], segTree[id * 2 + 1]);
}

void lazy(int id)
{
    int t = tree_lazy[id];
    if (t == 0)
        return;
    tree_lazy[id] = 0;

    segTree[id * 2] = t;
    tree_lazy[id * 2] = t;

    segTree[id * 2 + 1] = t;
    tree_lazy[id * 2 + 1] = t;
}

void updateRange(int L, int R, int val, int id = 1, int l = 1, int r = n)
{
    if (r < L or l > R)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] = val;
        tree_lazy[id] = val;
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
    if (l > R or r < L)
        return 1e9 + 7;
    if (L <= l and r <= R)
        return segTree[id];

    lazy(id);
    int mid = (l + r) / 2;
    return min(getMin(L, R, id * 2, l, mid), getMin(L, R, id * 2 + 1, mid + 1, r));
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= 4 * n; ++i)
        segTree[i] = (int)1e9 + 7;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    construct();

    // for (int i = 1; i <= 4 * n; ++i)
    //     cout << segTree[i] << '\n';

    // cout << '\n';
    int rq_type, rq_l, rq_r, rq_w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> rq_type >> rq_l >> rq_r;
        if (rq_type == 1)
        {
            cin >> rq_w;
            updateRange(rq_l, rq_r, rq_w);
        }
        else if (rq_type == 2)
        {
            cout << getMin(rq_l, rq_r) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    clock_t timed = clock();
    not_main();
    timed = clock() - timed;
    // cout << '\nt = ' << timed / CLOCKS_PER_SEC;
    return 0;
}