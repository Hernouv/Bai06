#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
const ll outbound = 1e18;

int n, ec, k;
ll res = outbound;

struct mb
{
    vector<vector<ll>> m = vector<vector<ll>>(n, vector<ll>(n, outbound));
} base, expo;

mb mul_expo(mb a, mb b)
{
    mb ret;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                minimize(ret.m[i][k], a.m[i][j] + b.m[j][k]);

    return ret;
}

void not_main()
{
    cin >> n >> ec >> k;
    int tu, tv;
    ll tw;
    for (int i = 1; i <= ec; ++i)
    {
        cin >> tu >> tv >> tw;
        expo.m[tu - 1][tv - 1] = tw;
    }
    for (int i = 0; i < n; ++i)
    {
        base.m[i][i] = 0;
        expo.m[i][i] = 0;
    }

    while (k)
    {
        if (k % 2)
            base = mul_expo(base, expo);
        expo = mul_expo(expo, expo);
        k /= 2;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            minimize(res, base.m[i][j]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}