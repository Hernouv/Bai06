#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m;
int segTree[4 * nmax];
int tree_lazy[4 * nmax];
int a[nmax];

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

int lazy(int id)
{
    int t = tree_lazy[id];
    tree_lazy[id] = 0;

    segTree[id * 2] += t;
    tree_lazy[id * 2] += t;

    segTree[id * 2 + 1] += t;
    tree_lazy[id * 2 + 1] += t;
}

void update(int L, int R, int val, int id = 1, int l = 1, int r = n)
{
    if (l > R or r < L)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] += val;
        tree_lazy[id] += val;
        return;
    }

    lazy(id);

    int mid = (l + r) / 2;
    update(L, R, val, id * 2, l, mid);
    update(L, R, val, id * 2 + 1, mid + 1, r);

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
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    construct();

    int rq_type;
    int rq_l, rq_r, rq_w;

    for (int i = 1; i <= m; ++i)
    {
        cin >> rq_type;
        if (rq_type == 1)
        {
            cin >> rq_l >> rq_r >> rq_w;
            update(rq_l, rq_r, rq_w);
        }
        else
        {
            cin >> rq_l >> rq_r;
            cout << getMin(rq_l, rq_r) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("minrange1.inp", "r"))
    {
        freopen("minrange1.inp", "r", stdin);
        freopen("minrange1.out", "w", stdout);
    }
    clock_t time_rq = clock();
    not_main();
    time_rq = clock() - time_rq;
    // cout << '\n';
    // cout << "Running time: " << time_rq / CLOCKS_PER_SEC * 5 << " sec";
    return 0;
}