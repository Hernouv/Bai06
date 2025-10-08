#include <bits/stdc++.h>
#define int long long

using namespace std;

const int nmax = 55;
const int mod = 1e9 + 7;

int n, m;
int dp[nmax][nmax][nmax * nmax];

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    if (m & 1)
    {
        cout << 0;
        return 0;
    }

    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 2 * j; k <= m; k += 2)
            {
                dp[i][j][k] = ((2 * j + 1) * dp[i - 1][j][k - 2 * j] % mod + (j + 1) * (j + 1) * dp[i - 1][j + 1][k - 2 * j] % mod) % mod;
                if (j >= 1)
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 2 * j]) % mod;
            }
        }
    }
    cout << dp[n][0][m];
    return 0;
}