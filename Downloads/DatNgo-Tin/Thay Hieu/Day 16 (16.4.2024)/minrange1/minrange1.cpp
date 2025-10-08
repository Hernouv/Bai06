#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m;
int segTree[4 * nmax];
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

void update(int pos, int val, int id = 1, int l = 1, int r = n)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(pos, val, id * 2, l, mid);
    update(pos, val, id * 2 + 1, mid + 1, r);
    segTree[id] = min(segTree[id * 2], segTree[id * 2 + 1]);
}

int getMin(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (l > R or r < L)
        return 1e9 + 7;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return min(getMin(L, R, id * 2, l, mid), getMin(L, R, id * 2 + 1, mid + 1, r));
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    construct();

    int rq_type, rq_id1, rq_id2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> rq_type >> rq_id1 >> rq_id2;
        if (rq_type == 1)
            update(rq_id1, rq_id2);
        else if (rq_type == 2)
            cout << getMin(rq_id1, rq_id2) << '\n';
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
    not_main();
    return 0;
}