#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int nmax = 1e2 + 10, pmax = 1e4 + 10;

int n, p;
long long a[nmax];
long long dp[nmax][pmax];

void not_main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[0][0] = 1;
    int lim = 0;
    for (int i = 1; i <= n; ++i)
    {
        lim += a[i];
        for (int j = 0; j <= min(lim, p); ++j)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j >= a[i])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
        }
    }
    cout << dp[n][p];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("COUNTSUM.INP", "r"))
    {
        freopen("COUNTSUM.INP", "r", stdin);
        freopen("COUNTSUM.OUT", "w", stdout);
    }
    not_main();
    return 0;
}