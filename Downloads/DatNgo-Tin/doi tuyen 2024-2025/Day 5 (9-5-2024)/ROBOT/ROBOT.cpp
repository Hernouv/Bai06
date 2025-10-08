#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e7 + 10;
const int mod = 1e9 + 7;

typedef long long ll;
ll fact_n, fact_m;
ll inv[nmax];
int pwr2[nmax];
ll sum_res;
int n, m;

ll pwrmod(ll base, ll expo)
{
    if (!expo)
        return 1;
    ll t = pwrmod(base, expo / 2);
    t = (t * t) % mod;
    if (expo % 2)
        t = (t * base) % mod;
    return t;
}

void set_fact()
{
    fact_n = 1;
    for (int i = 1; i <= n; ++i)
        fact_n = fact_n * i % mod;
    fact_m = fact_n;
    for (int i = n + 1; i <= m; ++i)
        fact_m = fact_m * i % mod;
}

void set_inv()
{
    inv[m] = pwrmod(fact_m, mod - 2);
    for (int i = m; i >= 1; --i)
        inv[i - 1] = inv[i] * i % mod;
}

void set_pwr2()
{
    pwr2[0] = 1;
    for (int i = 1; i <= m; ++i)
        pwr2[i] = pwr2[i - 1] * 2 % mod;
}

ll cm(ll a, ll b)
{
    return fact_m * inv[b] % mod * inv[a - b] % mod;
}

ll cn(ll a, ll b)
{
    return fact_n * inv[b] % mod * inv[a - b] % mod;
}

void not_main()
{
    cin >> n >> m;

    if (n > m)
        swap(n, m);
    set_fact();
    set_inv();
    set_pwr2();

    for (int i = 0; i <= n; ++i)
        sum_res = (sum_res + (cm(m, i) * cn(n, i) % mod * pwr2[i] % mod)) % mod;

    cout << sum_res;
}

int32_t main()
{
    if (fopen("ROBOT.INP", "r"))
    {
        freopen("ROBOT.INP", "r", stdin);
        freopen("ROBOT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}