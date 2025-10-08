#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct ma
{
    ll m[3];
} base;

struct mb
{
    ll m[3][3];
} expo;

ll n;

void initialize()
{
    base.m[0] = 22;
    base.m[1] = 7;
    base.m[2] = 2;

    expo.m[0][0] = 2;
    expo.m[1][0] = 3;
    expo.m[2][0] = 2;
    expo.m[0][1] = 1;
    expo.m[1][2] = 1;
}

ma mul_base(ma a, mb b)
{
    ma ret;
    for (int i = 0; i < 3; ++i)
    {
        ret.m[i] = 0;
        for (int k = 0; k < 3; ++k)
            ret.m[i] = (ret.m[i] + 1LL * base.m[k] * expo.m[k][i] % mod) % mod;
    }
    return ret;
}

mb mul_expo(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < 4; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j] % mod) % mod;
        }
    return ret;
}

void not_main()
{
    cin >> n;
    initialize();
    if (n <= 3)
    {
        cout << base.m[3 - n];
        exit(0);
    }
    n -= 3;
    while (n)
    {
        if (n % 2)
            base = mul_base(base, expo);
        expo = mul_expo(expo, expo);
        n /= 2;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}