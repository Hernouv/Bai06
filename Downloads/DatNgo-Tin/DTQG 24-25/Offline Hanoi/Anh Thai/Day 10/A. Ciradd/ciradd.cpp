#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<ll, int> lli;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

int n;
ll a[1005], accum[1005];
ll dp[1005][1005];
ll res = (ll)2e18;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; ++i)
        accum[i] = accum[i - 1] + a[i];

    memset(dp, 0x3f3f, sizeof dp);
    for (int i = 1; i <= 2 * n; ++i)
        dp[i][i] = 0;
    for (int i = 1; i < 2 * n; ++i)
        dp[i][i + 1] = a[i] + a[i + 1];

    for (int len = 3; len <= n; ++len)
        for (int i = 1; i + len - 1 <= 2 * n; ++i)
        {
            int j = i + len - 1;
            ll ta = accum[j] - accum[i - 1];
            for (int k = i; k < j; ++k)
                minimize(dp[i][j], dp[i][k] + dp[k + 1][j] + ta);
        }

    for (int i = 1; i <= n; ++i)
    {
        cerr << dp[i][i + n - 1] << '\n';
        minimize(res, dp[i][i + n - 1]);
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}