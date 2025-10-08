#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct ma
{
    ld m[4];
} base;

struct mb
{
    ld m[4][4];
} expo;

ll n;
ld p;

void initialize()
{
    base.m[0] = 1;

    expo.m[0][0] = ld(1 - p);
    expo.m[1][0] = p;
    expo.m[0][1] = p;
    expo.m[1][1] = ld(1 - p);
    expo.m[0][2] = 1;
    expo.m[1][3] = 1;
}

ma mul_base(ma a, mb b)
{
    ma ret;
    for (int i = 0; i < 4; ++i)
    {
        ret.m[i] = 0;
        for (int k = 0; k < 4; ++k)
            ret.m[i] = (ret.m[i] + 1LL * base.m[k] * expo.m[k][i]);
    }
    return ret;
}

mb mul_expo(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < 4; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]);
        }
    return ret;
}

void not_main()
{
    cin >> n >> p;
    initialize();
    while (n)
    {
        if (n % 2)
            base = mul_base(base, expo);
        expo = mul_expo(expo, expo);
        n /= 2;
    }
    cout << fixed << setprecision(6) << base.m[0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}