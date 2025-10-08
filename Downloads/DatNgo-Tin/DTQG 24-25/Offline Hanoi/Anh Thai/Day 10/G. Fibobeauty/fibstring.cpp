#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll inv[3];

ll n;
struct mt
{
    ll m[2][2];
};

mt mul(mt a, mt b, ll m)
{
    mt ret;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            ll tmp = 0;
            for (int k = 0; k < 2; ++k)
                tmp = (tmp + 1LL * a.m[i][k] * b.m[k][j]) % m;
            ret.m[i][j] = tmp;
        }
    return ret;
}

mt mt_pwrmod(mt base, mt up, ll expo, ll m)
{
    while (expo)
    {
        if (expo % 2)
            base = mul(base, up, m);
        up = mul(up, up, m);
        expo /= 2;
    }
    return base;
}

ll pwrmod(ll base, ll expo)
{
    ll ret = 1;
    while (expo)
    {
        if (expo % 2)
            ret = 1LL * (ret * base) % mod;
        base = 1LL * (base * base) % mod;
        expo /= 2;
    }
    return ret;
}

void not_main()
{
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    if (n == 1)
    {
        cout << 1;
        return;
    }

    n -= 1;
    struct mt b1cnt = {{{0, 1}, {0, 0}}};
    struct mt len1 = {{{1, 1}, {0, 0}}};
    struct mt len2 = {{{1, 1}, {0, 0}}};
    struct mt pwr = {{{0, 1}, {1, 1}}};

    // len1 = len1 * pwr;
    //  for (int i = 0; i < 2; ++i)
    //  {
    //      for (int j = 0; j < 2; ++j)
    //          cerr << len1.m[i][j] << ' ';
    //      cerr << '\n';
    //  }

    b1cnt = mt_pwrmod(b1cnt, pwr, n, mod);
    len1 = mt_pwrmod(len1, pwr, n, mod);
    len2 = mt_pwrmod(len2, pwr, n, mod - 1);

    ll cnt = b1cnt.m[0][1];
    ll len = len1.m[0][1];
    ll lenp = len2.m[0][1];

    cerr << cnt << ' ' << len << ' ' << lenp << '\n';
    cout << (1LL * cnt * (len - 1 + mod) % mod * pwrmod(2, (lenp * inv[2]) % mod) % mod + 1LL * cnt * pwrmod(2, (lenp * inv[1]) % mod)) % mod << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        not_main();
    return 0;
}