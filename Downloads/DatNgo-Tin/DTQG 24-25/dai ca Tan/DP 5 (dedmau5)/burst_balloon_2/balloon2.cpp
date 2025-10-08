#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (len == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i][j - 1] + 1;
            for (int k = i; k <= j - 1; k++)
            {
                if (a[k] == a[j])
                {
                    int tmp = dp[i][k];
                    if (k + 1 <= j - 1)
                    {
                        tmp += dp[k + 1][j - 1];
                    }
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }
    }
    cout << dp[1][n];
}
