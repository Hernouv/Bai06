#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct mb
{
    ll m[4][4];
} base, expo;

void initialize()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            base.m[i][j] = 1;
    for (int i = 0; i < 4; ++i)
        base.m[i][i] = 0;

    expo = base;
}

mb mul_m(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < 4; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % mod;
        }
    return ret;
}

ll n;

void not_main()
{
    initialize();
    cin >> n;

    n--;
    while (n)
    {
        if (n % 2)
            base = mul_m(base, expo);
        expo = mul_m(expo, expo);
        n /= 2;
    }
    cout << base.m[0][0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}