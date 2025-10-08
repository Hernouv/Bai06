#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
const long long mod = 1e9 + 7;
long long dp[nmax][nmax];
char grid[nmax][nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];

    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % mod;
            else
                dp[i][j] = 0;

    cout << dp[n][n];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}