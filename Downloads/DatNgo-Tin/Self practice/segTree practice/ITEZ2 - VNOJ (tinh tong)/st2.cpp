#include <bits/stdc++.h>
using namespace std;

long long segTree[400010];
long long arr[100010];
int n, q;
int rq_type, L, R, pos, val;

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
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

long long getSum(int id, int L, int R, int l, int r)
{
    if (r < L or R < l)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(id * 2, L, R, l, mid) + getSum(id * 2 + 1, L, R, mid + 1, r);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n >> q;
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
            cout << getSum(1, L, R, 1, n) << '\n';
        }
    }
    return 0;
}