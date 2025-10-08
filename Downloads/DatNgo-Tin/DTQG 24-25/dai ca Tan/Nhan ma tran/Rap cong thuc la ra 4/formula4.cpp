#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct ma
{
    ll m[105];
} base;

struct mb
{
    ll m[105][105];
} expo;

int n;
ll k;

void initialize()
{
    expo.m[n][0] = 1;
    for (int i = 0; i < n - 1; ++i)
        expo.m[i][i + 1] = 1;
    expo.m[n][n] = 1;
}

ma mul_base(ma a, mb b)
{
    ma ret;
    for (int i = 0; i <= n; ++i)
    {
        ret.m[i] = 0;
        for (int k = 0; k <= n; ++k)
            ret.m[i] = (ret.m[i] + 1LL * base.m[k] * expo.m[k][i] % mod) % mod;
    }
    return ret;
}

mb mul_expo(mb a, mb b)
{
    mb ret;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k <= n; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j] % mod) % mod;
        }
    return ret;
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> base.m[n - i];
    for (int i = 0; i < n; ++i)
        cin >> expo.m[i][0];
    cin >> base.m[n];
    initialize();

    if (k < n)
    {
        cout << base.m[n - k - 1];
        exit(0);
    }

    k = (k - n + 1);
    while (k)
    {
        if (k % 2)
            base = mul_base(base, expo);
        expo = mul_expo(expo, expo);
        k /= 2;
    }
    cout << base.m[0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}