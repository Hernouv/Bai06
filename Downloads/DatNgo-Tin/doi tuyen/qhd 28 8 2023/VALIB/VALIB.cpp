#include <bits/stdc++.h>
using namespace std;

int w[101], val[101];
int dp[101][1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("VALIB.INP", "r", stdin);
    // freopen("VALIB.OUT", "w", stdout);
    int n, lim_w;
    cin >> n >> lim_w;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> val[i];
    for (int i = 0; i <= lim_w; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= lim_w; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= j / w[i]; ++k)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * val[i]);
        }
    cout << dp[n][lim_w] << '\n';
    int id = n, trace_w = lim_w;
    while (id)
    {
        if (trace_w >= w[id])
            while (dp[id][trace_w] == dp[id][trace_w - w[id]] + val[id])
            {
                cout << id << '\n';
                trace_w -= w[id];
            }
        id--;
    }
    return 0;
}