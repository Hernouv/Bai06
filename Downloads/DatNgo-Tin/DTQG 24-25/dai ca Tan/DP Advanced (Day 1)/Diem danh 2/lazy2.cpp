#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 1e5 + 10;
const ll mod = 1e9 + 7;

int n, k1, k2;
int dp[12][12][nmax]; // absent, late, and day
int res;

void not_main()
{
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= k2; ++i)
        dp[0][i][i] = 1;

    dp[0][0][1] = 1;
    if (k1)
        dp[1][0][1] = 1;
    if (k2 > 1)
        dp[0][1][1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= min(i, k1); ++j)
        {
            if (j)
                for (int t = 0; t < min(i, k2); ++t)
                    dp[j][0][i] = (dp[j][0][i] + dp[j - 1][t][i - 1]) % mod;

            for (int t = 0; t < min(i, k2); ++t)
                dp[j][0][i] = (dp[j][0][i] + dp[j][t][i - 1]) % mod;

            for (int t = 1; t < min(i, k2); ++t)
                dp[j][t][i] = (dp[j][t][i] + dp[j][t - 1][i - 1]) % mod;
        }
    }
    for (int i = 0; i <= k1; ++i)
    {
        for (int j = 0; j < k2; ++j)
            res = (res + dp[i][j][n]) % mod;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}