#include <bits/stdc++.h>
using namespace std;

const int outbound = 1000000010;
int segTree_left[800010];
int segTree_right[800010];
int n, q;
int arr[200010];
int rq, k, x;

void construct(int id, int l, int r)
{
    if (l == r)
    {
        segTree_left[id] = arr[l] - l;
        segTree_right[id] = arr[l] + l;
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree_left[id] = min(segTree_left[id * 2], segTree_left[id * 2 + 1]);
    segTree_right[id] = min(segTree_right[id * 2], segTree_right[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (r < pos or l > pos)
        return;

    if (l == r)
    {
        segTree_left[id] = val - pos;
        segTree_right[id] = val + pos;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    segTree_left[id] = min(segTree_left[id * 2], segTree_left[id * 2 + 1]);
    segTree_right[id] = min(segTree_right[id * 2], segTree_right[id * 2 + 1]);
}

int getMin_left(int id, int l, int r, int L, int R)
{
    if (L > r or l > R)
        return outbound;
    if (L <= l and r <= R)
        return segTree_left[id];
    int mid = (l + r) / 2;
    return min(getMin_left(id * 2, l, mid, L, R), getMin_left(id * 2 + 1, mid + 1, r, L, R));
}

int getMin_right(int id, int l, int r, int L, int R)
{
    if (L > r or l > R)
        return outbound;
    if (L <= l and r <= R)
        return segTree_right[id];
    int mid = (l + r) / 2;
    return min(getMin_right(id * 2, l, mid, L, R), getMin_right(id * 2 + 1, mid + 1, r, L, R));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("PIZZA.INP", "r", stdin);
    // freopen("PIZZA.OUT", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    construct(1, 1, n);
    for (int i = 1; i <= q; ++i)
    {
        cin >> rq;
        if (rq == 1)
        {
            cin >> k >> x;
            arr[k] = x;
            update(1, 1, n, k, x);
        }
        else
        {
            cin >> k;
            int res = arr[k];
            if (k - 1 >= 1)
            {
                res = min(res, getMin_left(1, 1, n, 1, k - 1) + k);
            }
            if (k + 1 <= n)
            {
                res = min(res, getMin_right(1, 1, n, k + 1, n) - k);
            }
            cout << res << '\n';
        }
    }
    return 0;
}