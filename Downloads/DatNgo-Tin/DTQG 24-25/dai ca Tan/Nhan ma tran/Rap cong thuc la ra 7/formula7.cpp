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

struct m4base
{
    ll m[5];
} base4;

struct m4expo
{
    ll m[5][5];
} expo4;

void initialize()
{
    base.m[0] = 3;
    base.m[1] = 2;
    base.m[2] = 1;

    expo.m[0][0] = 1;
    expo.m[1][0] = 1;
    expo.m[2][0] = 1;
    expo.m[0][1] = 1;
    expo.m[1][2] = 1;

    base4.m[0] = 6;
    base4.m[1] = 2;
    base4.m[2] = 0;
    base4.m[3] = 6;
    base4.m[4] = 1;

    expo4.m[0][0] = 1;
    expo4.m[1][0] = 1;
    expo4.m[2][0] = 1;
    expo4.m[3][0] = 1;
    expo4.m[0][1] = 1;
    expo4.m[1][2] = 1;
    expo4.m[3][3] = 1;
    expo4.m[4][3] = 2;
    expo4.m[4][4] = 1;
}

ll pwrmod(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b % 2)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}

ma mul_base(ma a, mb b)
{
    ma ret;
    for (int i = 0; i < 3; ++i)
    {
        ret.m[i] = 1;
        for (int k = 0; k < 3; ++k)
            ret.m[i] = 1LL * ret.m[i] * pwrmod(base.m[k], expo.m[k][i]) % mod;
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
            for (int k = 0; k < 3; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % (mod - 1);
        }
    return ret;
}

m4base mul_base4(m4base a, m4expo b)
{
    m4base ret;
    for (int i = 0; i < 5; ++i)
    {
        ret.m[i] = 0;
        for (int k = 0; k < 5; ++k)
            ret.m[i] = (ret.m[i] + 1LL * a.m[k] * b.m[k][i]) % (mod - 1);
    }
    return ret;
}

m4expo mul_expo4(m4expo a, m4expo b)
{
    m4expo ret;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < 5; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % (mod - 1);
        }
    return ret;
}

ll n;

void not_main()
{
    cin >> n;
    initialize();
    if (n <= 3)
    {
        cout << base.m[3 - n];
        exit(0);
    }

    int n2 = n;
    n -= 3;
    while (n)
    {
        if (n % 2)
            base = mul_base(base, expo);
        expo = mul_expo(expo, expo);
        n /= 2;
    }

    if (n2 <= 5)
    {
        base.m[0] = 1LL * base.m[0] * pwrmod(4, base4.m[5 - n2]) % mod;
        cout << base.m[0];
        exit(0);
    }
    n2 -= 5;
    while (n2)
    {
        if (n2 % 2)
        {
            base4 = mul_base4(base4, expo4);
        }
        expo4 = mul_expo4(expo4, expo4);
        n2 /= 2;
    }
    base.m[0] = 1LL * base.m[0] * pwrmod(4, base4.m[0]) % mod;
    cout << base.m[0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}