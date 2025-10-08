#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long lazy;
    long long val;
};
node segTree[400010];
int n, q;
long long arr[100010];
long long rq_type, L, R, val;

void construct(int id, int l, int r)
{
    if (l == r)
    {
        segTree[id].val = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id].val = max(segTree[id * 2].val, segTree[id * 2 + 1].val);
}

void lazy_proc(int id)
{
    long long update_val = segTree[id].lazy;

    segTree[id * 2].lazy += update_val;
    segTree[id * 2].val += update_val;

    segTree[id * 2 + 1].lazy += update_val;
    segTree[id * 2 + 1].val += update_val;

    segTree[id].lazy = 0;
}

void update(int id, int L, int R, int l, int r, long long val)
{
    if (R < l or r < L)
        return;
    if (L <= l and r <= R)
    {
        segTree[id].val += val;
        segTree[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;
    lazy_proc(id);
    update(id * 2, L, R, l, mid, val);
    update(id * 2 + 1, L, R, mid + 1, r, val);

    segTree[id].val = max(segTree[id * 2].val, segTree[id * 2 + 1].val);
}

long long getMax(int id, int L, int R, int l, int r)
{
    if (L > r or l > R)
        return -1e18;
    if (L <= l and r <= R)
        return segTree[id].val;
    int mid = (l + r) / 2;
    lazy_proc(id);
    return max(getMax(id * 2, L, R, l, mid), getMax(id * 2 + 1, L, R, mid + 1, r));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
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
            cin >> L >> R >> val;
            update(1, L, R, 1, n, val);
        }
        else if (rq_type == 2)
        {
            cin >> L >> R;
            cout << getMax(1, L, R, 1, n) << '\n';
        }
    }
    return 0;
}