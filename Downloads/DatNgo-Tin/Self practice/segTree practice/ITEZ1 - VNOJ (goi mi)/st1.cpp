#include <bits/stdc++.h>
using namespace std;

int segTree[400010];
int arr[100010];
int n, q;
int rq_type, L, R, pos, val;

void construct(int id, int l, int r)
{
    if (l == r)
    {
        segTree[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        // arr[pos] = val;
        segTree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

int getMax(int id, int L, int R, int l, int r)
{
    if (r < L or R < l)
        return INT_MIN;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return max(getMax(id * 2, L, R, l, mid), getMax(id * 2 + 1, L, R, mid + 1, r));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    construct(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> rq_type;
        if (rq_type == 1)
        {
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else if (rq_type == 2)
        {
            cin >> L >> R;
            cout << getMax(1, L, R, 1, n) << '\n';
        }
    }
    return 0;
}