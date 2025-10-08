#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int ans = 1, g = gcd(a[0][0], a[n - 1][m - 1]);
    vector<vector<char>> dp(n, vector<char>(m));
    for (int x = 1; x * x <= g; ++x)
    {
        if (g % x > 0)
        {
            continue;
        }
        vector<int> cand = {x, g / x};
        for (int el : cand)
        {
            for (int i = 0; i < n; ++i)
            {
                dp[i].assign(m, 0);
            }
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (a[i][j] % el > 0)
                    {
                        continue;
                    }
                    if (!dp[i][j] && i)
                    {
                        dp[i][j] = (dp[i - 1][j] == 1 ? 1 : 0);
                    }
                    if (!dp[i][j] && j)
                    {
                        dp[i][j] = (dp[i][j - 1] == 1 ? 1 : 0);
                    }
                }
            }
            if (dp[n - 1][m - 1])
            {
                ans = max(ans, el);
            }
        }
    }
    cout << ans << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GCD.INP", "r"))
    {
        freopen("GCD.INP", "r", stdin);
        freopen("GCD.OUT", "w", stdout);
    }
    not_main();
    return 0;
}