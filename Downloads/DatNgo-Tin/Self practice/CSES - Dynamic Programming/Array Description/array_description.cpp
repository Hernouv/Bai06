#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
const long long mod = 1e9 + 7;
int n, m;
int x[nmax];
long long dp[nmax][101];
long long ans;

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    if (x[1] == 0)
    {
        for (int i = 1; i <= m; ++i)
            dp[1][i] = 1;
    }
    else
        dp[1][x[1]] = 1;

    for (int i = 2; i <= n; ++i)
    {
        if (x[i] == 0)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] += dp[i - 1][j];
                if (j > 1)
                    dp[i][j] += dp[i - 1][j - 1];
                if (j < m)
                    dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
        else
        {
            dp[i][x[i]] += dp[i - 1][x[i]];
            if (x[i] > 1)
                dp[i][x[i]] += dp[i - 1][x[i] - 1];
            if (x[i] < m)
                dp[i][x[i]] += dp[i - 1][x[i] + 1];
            dp[i][x[i]] %= mod;
        }
    }

    for (int i = 1; i <= m; ++i)
        ans = (ans + dp[n][i]) % mod;

    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}