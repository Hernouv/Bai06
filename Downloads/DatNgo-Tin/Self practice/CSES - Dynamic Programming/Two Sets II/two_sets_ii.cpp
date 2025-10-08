#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long dp[501][130000];
int n;

void not_main()
{
    cin >> n;
    int t = n * (n + 1) / 2;
    if (t & 1)
    {
        cout << 0;
        return;
    }

    t >>= 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= t; ++j)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (j >= i)
            {
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= mod;
            }
        }
    cout << dp[n - 1][t];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}