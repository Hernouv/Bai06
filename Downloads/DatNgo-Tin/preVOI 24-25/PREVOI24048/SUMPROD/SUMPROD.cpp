#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e5 + 5;
const ll mod = 998244353;

int n, q, k;
ll a[nmax];
ll segTree[4 * nmax], lazy[4 * nmax];

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
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

void down(int id, int l, int r)
{
    if (!lazy[id] or l == r)
        return;

    int mid = (l + r) / 2;
    segTree[id * 2] = 1LL * (segTree[id * 2] + ll(mid - l + 1) * lazy[id] % mod) % mod;
    lazy[id * 2] = (lazy[id * 2] + lazy[id]) % mod;
    segTree[id * 2 + 1] = 1LL * (segTree[id * 2 + 1] + ll(r - mid) * lazy[id] % mod) % mod;
    lazy[id * 2 + 1] = (lazy[id * 2 + 1] + lazy[id]) % mod;
    lazy[id] = 0;
}

void update(int L, int R, ll val, int id = 1, int l = 1, int r = n)
{
    if (L > r or R < l)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] = 1LL * (segTree[id] + ll(r - l + 1) * val % mod) % mod;
        lazy[id] = (lazy[id] + val) % mod;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    update(L, R, val, id * 2, l, mid);
    update(L, R, val, id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

ll getSum(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (L > r or R < l)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    down(id, l, r);
    int mid = (l + r) / 2;
    return 1LL * (getSum(L, R, id * 2, l, mid) + getSum(L, R, id * 2 + 1, mid + 1, r));
}

void not_main()
{
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    construct();

    for (int i = 1, qtype, l, r, x; i <= q; ++i)
    {
        cin >> qtype >> l >> r;
        if (qtype == 1)
        {
            cin >> x;
            update(l, r, (ll)x);
        }
        else
        {
            ll res = 0;
            for (int ti = l; ti <= r - k; ++ti)
            {
                ll a_ti = getSum(ti, ti);
                ll tval = getSum(ti + k, r);
                res = (res + 1LL * a_ti * tval % mod) % mod;
            }
            cout << res << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}