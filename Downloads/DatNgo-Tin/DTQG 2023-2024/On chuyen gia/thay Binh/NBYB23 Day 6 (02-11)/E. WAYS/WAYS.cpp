#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long

const int MAXN = 2e6 + 10;
const int mod = 1e9 + 7;

ll binpow(ll a, ll n, ll m = mod)
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
    return fac[n] * inv[r] % mod * inv[n - r] % mod;
}

void _precalc()
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }

    inv[MAXN] = binpow(fac[MAXN], mod - 2, mod);
    for (int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % mod;
    }
}

int add(int &a, int b)
{
    return a = ((a + b) % mod + mod) % mod;
}

int mul(int &a, int b)
{
    a %= mod;
    b %= mod;
    return a = (a * b) % mod;
}

int calc(int n, int k)
{
    int res = 0;

    int denom = (k + 1) * (k + 2);
    denom = binpow(denom, mod - 2);

    int numer = k + n + 1;
    mul(numer, nCr(k + n, n));
    add(numer, -k * k);
    add(numer, -3 * k);
    add(numer, -2);
    mul(numer, 2 * n);

    res = mul(numer, denom);
    add(res, n);

    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    cout << calc(n, k) << '\n';
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    _precalc();

    int t;
    cin >> t;
    while (t--)
        solve();
}