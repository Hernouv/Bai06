#include <bits/stdc++.h>
using namespace std;

int w[110], val[110], quantity[110];
int dp[110][10010];
int n, lim_w;

void not_main()
{
    cin >> n >> lim_w;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> val[i] >> quantity[i];
    for (int i = 0; i <= lim_w; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= lim_w; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= min(quantity[i], j / w[i]); ++k)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * val[i]);
        }
    cout << dp[n][lim_w] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CAYKHE.INP", "r"))
    {
        freopen("CAYKHE.INP", "r", stdin);
        freopen("CAYKHE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}