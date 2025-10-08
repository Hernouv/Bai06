#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
const long long mod = 1e9 + 7;
long long fact[nmax + 1], inv[nmax + 1];

long long expmod(long long base, long long exp)
{
    long long ret = 1;
    while (exp)
    {
        if (exp & 1)
            ret = ret * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return ret;
}

void factmod()
{
    fact[0] = 1;
    for (int i = 1; i <= nmax; ++i)
        fact[i] = fact[i - 1] * i % mod;
}

void invmod()
{
    inv[nmax] = expmod(fact[nmax], mod - 2);
    for (int i = nmax; i >= 1; --i)
        inv[i - 1] = inv[i] * i % mod;
}

long long nCr(long long n, long long r)
{
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

void not_main()
{
    factmod();
    invmod();
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}