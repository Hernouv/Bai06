#include <bits/stdc++.h>
using namespace std;

int dp[110][1010];

int w[110], v[110];
int n, tw;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("VALIA.INP", "r", stdin);
    // freopen("VALIA.OUT", "w", stdout);
    cin >> n >> tw;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];
    for (int i = 0; i <= tw; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= tw; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    cout << dp[n][tw] << '\n';
    int id = n, trace_w = tw;
    while (id)
    {
        if (dp[id][trace_w] == dp[id - 1][trace_w - w[id]] + v[id])
        {
            cout << id << '\n';
            trace_w -= w[id];
        }
        id--;
    }
    return 0;
}