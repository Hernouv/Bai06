#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 1e5 + 10;
const ll mod = 1e9 + 7;

ll n;
ll dp[3][nmax]; // 2 for total
ll res;

void not_main()
{
    cin >> n;
    dp[0][1] = 1; // normal
    dp[1][1] = 1; // 1 day late
    dp[2][0] = 1;

    for (int i = 1; i < n; ++i)
    {
        dp[0][i + 1] = (dp[0][i] + dp[1][i]) % mod;
        dp[1][i + 1] = (dp[1][i + 1] + dp[0][i]) % mod;
    }
    for (int i = 1; i <= n; ++i)
        dp[2][i] = dp[0][i] + dp[1][i];
    res = dp[2][n];
    for (int i = 1; i <= n; ++i)
        res = (res + 1LL * dp[2][i - 1] * dp[2][n - i]) % mod;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}