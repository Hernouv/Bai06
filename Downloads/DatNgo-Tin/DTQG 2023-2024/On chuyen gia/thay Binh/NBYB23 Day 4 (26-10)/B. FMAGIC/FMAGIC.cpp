#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long

#define all(v) v.begin(), v.end()
#define create_unique(vec) \
    sort(all(vec));        \
    vec.resize(unique(all(vec)) - vec.begin());

#define endl '\n'
#define db(val) "[" #val " = " << (val) << "] "
#ifdef LOCAL_DEBUG
#define clog cerr
#else
#define clog \
    if (0)   \
    cerr
#endif

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

template <
    class S,
    S (*op)(S, S),
    S (*e)()>
struct SegTree
{
    int _n;
    vector<S> st;

    SegTree(int _n) : _n(_n), st(_n * 4 + 1, e()) {}

    void update(int p, S x, int id, int lx, int rx)
    {
        if (p > rx || p < lx)
            return;
        if (lx == rx)
        {
            st[id] = x;
            return;
        }

        int mid = (lx + rx) / 2;
        update(p, x, id * 2, lx, mid);
        update(p, x, id * 2 + 1, mid + 1, rx);

        st[id] = op(st[id * 2], st[id * 2 + 1]);
    }

    S query(int u, int v, int id, int lx, int rx)
    {
        if (u > rx || v < lx)
            return e();
        if (u <= lx && v >= rx)
            return st[id];

        int mid = (lx + rx) / 2;
        return op(query(u, v, id * 2, lx, mid), query(u, v, id * 2 + 1, mid + 1, rx));
    }

    void update(int p, S x)
    {
        update(p, x, 1, 1, _n);
    }

    S query(int u, int v)
    {
        return query(u, v, 1, 1, _n);
    }
};

const int MAXN = 3e6 + 10;
const int MOD = 3046201;

ll binpow(ll a, ll n, ll m = MOD)
{
    a %= m;
    ll res = 1;

    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n /= 2;
    }

    return res;
}

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll nCr(int n, int r)
{
    if (n < r)
        return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void _precalc()
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }

    inv[MAXN] = binpow(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % MOD;
    }
}

using S = int;
S op(int l, int r) { return (l + r) % MOD; }
S e() { return 0; }

void solve()
{
    int n;
    cin >> n;

    SegTree<S, op, e> tree(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tree.update(i, x);
    }

    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++)
    {
        char tp;
        int u, v;
        cin >> tp >> u >> v;

        if (tp == 'C')
            tree.update(u, v);
        else
        {
            int m = v - u + 1;
            int sum = tree.query(u, v);
            int x = sum / m;
            int r = sum % m;

            if (m == 1)
            {
                cout << 1 << endl;
                continue;
            }
            clog << m << " " << sum << " " << x << " " << r << endl;

            int ans = nCr(m, r);

            // 1 -> r
            ans *= fac[sum];
            ans %= MOD;
            ans *= binpow(binpow(fac[x + 1], r), MOD - 2);
            ans %= MOD;
            ans *= binpow(fac[sum - (x + 1) * r], MOD - 2);
            ans %= MOD;

            // r+1 -> n
            sum -= (x + 1) * r;

            ans *= fac[sum];
            ans %= MOD;
            ans *= binpow(binpow(fac[x], m - r), MOD - 2);
            ans %= MOD;
            ans *= binpow(fac[sum - x * (m - r)], MOD - 2);
            ans %= MOD;

            cout << ans << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    _precalc();

    int t = 1;
    while (t--)
        solve();
}