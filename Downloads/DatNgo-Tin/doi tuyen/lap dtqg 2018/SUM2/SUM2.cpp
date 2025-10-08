#include <bits/stdc++.h>
using namespace std;
const int MIN_INF = -1e9 + 7, MAXN = 1e6 + 7;
int n, l, r;
int st[4 * MAXN];
int a[MAXN];
int s[MAXN];
int res = 0;
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int query(int id, int l, int r, int u, int v)
{
    if (v < l or r < u)
    {
        return MIN_INF;
    }
    if (u <= l and r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("SUM2.INP", "r", stdin);
    // freopen("SUM2.OUT", "w", stdout);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        if (i + l > n)
            continue;
        int r1 = min(n, i + r);
        res = max(res, query(1, 1, n, i + 1, r1) - s[i]);
    }
    cout << res;
    return 0;
}