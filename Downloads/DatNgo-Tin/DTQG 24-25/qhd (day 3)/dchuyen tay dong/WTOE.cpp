#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
const int outbound = 1e9;

int m, n;
int dp[nmax][nmax];

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dp[i][j];

    for (int i = 0; i <= n + 1; ++i)
    {
        dp[0][i] = outbound;
        dp[m + 1][i] = outbound;
    }
    // for (int i = 0; i <= m + 1; ++i)
    // {
    //     dp[i][0] = outbound;
    //     dp[i][n + 1] = outbound;
    // }

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[j][i] += max(dp[j - 1][i - 1], dp[j][i - 1], dp[j + 1][i - 1]);

    int res = -outbound;
    for (int i = 1; i <= m; ++i)
        maximize(res, dp[i][n]);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("WTOE.INP", "r"))
    {
        freopen("WTOE.INP", "r", stdin);
        freopen("WTOE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}