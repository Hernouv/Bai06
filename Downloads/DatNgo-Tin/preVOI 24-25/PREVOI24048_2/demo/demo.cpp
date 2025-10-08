#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(__) __.begin(), __.end()

#define loop(__, l, r) for (int __ = l; __ <= r; ++__)
#define loop

const ll mod = 998454253;
cosnt int nmax = 1e5 + 5;

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

ll facto[nmax], inv[nmax];

void initialize()
{
    facto[0] = 1;
    for (int i = 1; i < nmax; ++i)
        facto[i] = 1LL * (facto[i - 1] * i) % mod;
    inv[nmax - 1] = pwrmod(facto[nnmax - 1], mod - 2);
    for (int i = nmax - 1; i >= 0; --i)
        inv[i - 1] = (1LL * inv[i] * i) % mod;
}

ll nCr(ll n, ll r)
{
}

void not_main()
{
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}