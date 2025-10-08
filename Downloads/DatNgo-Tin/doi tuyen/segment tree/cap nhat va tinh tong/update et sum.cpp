#include <bits/stdc++.h>
using namespace std;

long long segTree[400010];
int arr[100010];
int n, m;
char rq;
int pos, v, L, R;
long long sum = 0;

void update(int id, int pos, int l, int r, int v)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, pos, l, mid, v);
    update(id * 2 + 1, pos, mid + 1, r, v);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int getSum(int id, int L, int R, int l, int r)
{
    if (l > R or L > r)
        return 0;
    if (L <= l and R >= r)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(id * 2, L, R, l, mid) + getSum(id * 2 + 1, L, R, mid + 1, r);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("update_et_sum.inp", "r", stdin);
    // freopen("update_et_sum.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> rq;
        if (rq == 'S')
        {
            cin >> pos >> v;
            update(1, pos, 1, n, v);
        }
        else if (rq == 'Q')
        {
            cin >> L >> R;
            sum = 0;
            cout << getSum(1, L, R, 1, n);
            // cout << sum << '\n';
        }
    }
    return 0;
}