#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct mb
{
    ll m[101][101];
} base, expo;

ll steps, res = 0;
int n, m;

mb mul_m(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            ret.m[i][j] = 0;
            for (int k = 0; k < n; ++k)
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % mod;
        }
    return ret;
}

void not_main()
{
    cin >> n >> m >> steps;

    int tu, tv;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv;
        tu--;
        tv--;
        base.m[tu][tv] = 1;
    }
    expo = base;
    steps--;
    while (steps)
    {
        if (steps % 2)
            base = mul_m(base, expo);
        expo = mul_m(expo, expo);
        steps /= 2;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res = (res + base.m[i][j]) % mod;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}