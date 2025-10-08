#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e5 + 10;

int n;
ll cost[4][nmax];
ll dp[4][nmax];
ll res = (ll)1e18;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cost[1][i] >> cost[2][i] >> cost[3][i];

    for (int i = 1; i <= 3; ++i)
        dp[i][1] = cost[i][1];

    for (int i = 1; i < n; ++i)
    {
        dp[1][i + 1] = min(dp[2][i], dp[3][i]) + cost[1][i + 1];
        dp[2][i + 1] = min(dp[1][i], dp[3][i]) + cost[2][i + 1];
        dp[3][i + 1] = min(dp[2][i], dp[1][i]) + cost[3][i + 1];
    }

    for (int i = 1; i <= 3; ++i)
        res = min(res, dp[i][n]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}