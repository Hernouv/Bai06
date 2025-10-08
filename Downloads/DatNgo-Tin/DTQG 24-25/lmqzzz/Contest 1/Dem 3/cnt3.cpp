#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 2e5 + 40;
const ll mod = 998244353;

ll fact[nmax], ifact[nmax], inv[nmax];

ll pwrmod(ll base, ll expo)
{
    ll ret = 1;
    while (expo)
    {
        if (expo % 2)
            ret = ret * base % mod;
        base = base * base % mod;
        expo /= 2;
    }
    return ret;
}

void initialize()
{
    fact[0] = 1;
    for (int i = 1; i < nmax; ++i)
        fact[i] = fact[i - 1] * i % mod;

    ifact[nmax - 1] = pwrmod(fact[nmax - 1], mod - 2);
    for (int i = nmax - 1; i > 0; --i)
        ifact[i - 1] = ifact[i] * i % mod;
}

ll C(int n, int m)
{
    if (n < 0 or m < 0 or n < m)
        return 0;
    return fact[n] * ifact[m] % mod * ifact[n - m] % mod;
}

int n, m, k;

void not_main()
{
    cin >> n >> m >> k;
    ll ans = 0;
    for (int c = 0; c * n <= k; c++)
    {
        ll tval = C(m, c) * C(m - 1 + k - c * n, m - 1) % mod;
        if (c % 2)
            ans = (ans - tval + mod) % mod;
        else
            ans = (ans + tval) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    initialize();
    cin >> t;
    while (t--)
        not_main();
    return 0;
}