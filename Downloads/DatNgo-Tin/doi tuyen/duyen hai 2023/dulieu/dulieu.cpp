#include <bits/stdc++.h>
using namespace std;

int segTree[400010];
int arr[100010];
int n, q, L, R, pos;

int construct(int id, int l, int r, int arr[])
{
    if (l == r)
    {
        segTree[id] = arr[l];
        return arr[l];
    }
    int mid = (l + r) / 2;
    segTree[id] = max(construct(id * 2, l, mid, arr), construct(id * 2 + 1, mid + 1, r, arr));
    return segTree[id];
}

int getMax(int id, int L, int R, int l, int r)
{
    if (L <= l and r <= R)
        return segTree[id];
    if (l > R or L > r)
        return INT_MIN;
    int mid = (l + r) / 2;
    return max(getMax(id * 2, L, R, l, mid), getMax(id * 2 + 1, L, R, mid + 1, r));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("dulieu.inp", "r", stdin);
    // freopen("dulieu.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    construct(1, 1, n, arr);
    for (int i = 1; i <= q; ++i)
    {
        cin >> L >> R;
        int greatest = getMax(1, L, R, 1, n);
        int pos = find(arr + L, arr + R, greatest) - arr;
        int first_half = INT_MIN, second_half = INT_MIN;
        if (L <= pos - 1)
            first_half = getMax(1, L, pos - 1, 1, n);
        if (pos + 1 <= R)
            second_half = getMax(1, pos + 1, R, 1, n);
        int second_greatest = max(first_half, second_half);
        cout << greatest + second_greatest << '\n';
    }
    return 0;
}