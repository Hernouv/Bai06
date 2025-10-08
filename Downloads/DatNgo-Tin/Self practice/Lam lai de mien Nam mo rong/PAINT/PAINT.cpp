#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
const long long mod = 1e9 + 7;
long long w, b, r, k, m;
long long fact[nmax], inv[nmax];
long long res = 0;

long long pwrmod(long long base, long long expo)
{
    if (!expo)
        return 1;
    long long t = pwrmod(base, expo >> 1);
    t = t * t % mod;
    if (expo & 1)
        t = t * base % mod;
    return t;
}

void setVal()
{
    fact[0] = 1;
    for (long long i = 1; i < nmax; ++i)
        fact[i] = fact[i - 1] * i % mod;
    inv[nmax - 1] = pwrmod(fact[nmax - 1], mod - 2);
    for (long long i = nmax - 1; i >= 1; --i)
        inv[i - 1] = inv[i] * i % mod;
}

long long nCr(long long n, long long r)
{
    if (n < r)
        return 0;
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

void sub1()
{
    if (m > min(b, r) + 1)
    {
        cout << 0;
        return;
    }

    long long tmin = min(b, r);
    long long tmax = max(b, r);

    if (m & 1)
    {
        res = res + nCr(tmax - 1, (m - 1) / 2) * nCr(tmin - 1, (m - 1) / 2) % mod;
        res = res * 2 % mod;
    }
    else
    {
        if ((tmin - 1) * 2 >= m)
            res = res + nCr(tmax - 1, m / 2 - 1) * nCr(tmin - 1, m / 2) % mod;
        res = res + nCr(tmax - 1, m / 2) * nCr(tmin - 1, m / 2 - 1) % mod;
    }
    cout << res << '\n';
}

void not_main()
{
    setVal();
    cin >> w >> b >> r >> k >> m;
    if (w == 0)
    {
        sub1();
        return;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PAINT.INP", "r"))
    {
        freopen("PAINT.INP", "r", stdin);
        freopen("PAINT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}