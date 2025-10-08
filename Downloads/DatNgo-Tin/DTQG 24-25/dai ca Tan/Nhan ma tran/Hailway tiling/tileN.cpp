#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct ma
{
    ll m[12];
} base;

struct mb
{
    ll m[12][12];
} expo;

ll n;
ll const_incr[6] = {0, 0, 0, 6, 9, 12};

void initialize()
{
    // base.m[0] = 1356;
    base.m[0] = 516;
    base.m[1] = 156;
    base.m[2] = 36;
    base.m[3] = 12;
    base.m[4] = 0;
    base.m[5] = 0;

    expo.m[0][0] = 2;
    expo.m[1][0] = -1;
    expo.m[2][0] = 0;
    expo.m[3][0] = 16;
    expo.m[4][0] = 16;
    expo.m[5][0] = 4;
    for (int i = 0; i < 5; ++i)
        expo.m[i][i + 1] = 1;
}

ma mul_base(ma a, mb b)
{
    ma ret;
    for (int i = 0; i < 6; ++i)
    {
        ret.m[i] = 0;
        for (int k = 0; k < 6; ++k)
            ret.m[i] = (ret.m[i] + 1LL * expo.m[k][i] * ((base.m[k] + const_incr[k]) % mod)) % mod;
    }
    return ret;
}

mb mul_expo(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < 6; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % mod;
        }
    return ret;
}

void not_main()
{
    cin >> n;
    initialize();
    if (n <= 5)
    {
        cout << base.m[5 - n];
        exit(0);
    }

    n -= 5;
    while (n)
    {
        if (n % 2)
            base = mul_base(base, expo);
        expo = mul_expo(expo, expo);
        n /= 2;
    }
    cout << base.m[0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}