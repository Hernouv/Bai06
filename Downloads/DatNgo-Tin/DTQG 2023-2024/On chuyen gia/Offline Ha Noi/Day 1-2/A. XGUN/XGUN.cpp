#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 7;
int n, m;

int segTree[4 * N], lazy[4 * N];

void setDefault()
{
    for (int i = 0; i < 4 * N; ++i)
        lazy[i] = -1;
}

void lazy_update(int id, int l, int r)
{
    if (lazy[id] == -1 or l == r)
        return;

    int mid = (l + r) / 2;
    int first_half = id * 2, second_half = id * 2 + 1;

    segTree[first_half] = lazy[id] * (mid - l + 1);
    segTree[second_half] = lazy[id] * (r - mid);
    lazy[first_half] = lazy[id];
    lazy[second_half] = lazy[id];
    lazy[id] = -1;
}

void update(int L, int R, int val, int id, int l, int r)
{
    lazy_update(id, l, r);
    if (L > r or l > R)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] = val * (r - l + 1);
        lazy[id] = val;
        lazy_update(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(L, R, val, id * 2, l, mid);
    update(L, R, val, id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int get(int L, int R, int id, int l, int r)
{
    lazy_update(id, l, r);
    if (L > r or l > R)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) >> 1;
    return get(L, R, id * 2, l, mid) + get(L, R, id * 2 + 1, mid + 1, r);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    setDefault();
    cin >> n;

    int h;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h;
        update(i, i, h, 1, 1, n);
    }

    cin >> m;
    int pos, length;
    while (m--)
    {
        cin >> pos >> length;
        int val = get(pos, pos, 1, 1, n);
        cout << get(pos + 1, pos + length, 1, 1, n) - val * length << '\n';
        update(pos + 1, pos + length, val, 1, 1, n);
    }
    return 0;
}