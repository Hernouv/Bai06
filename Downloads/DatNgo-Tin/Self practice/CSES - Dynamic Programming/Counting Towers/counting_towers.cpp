#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
const long long mod = 1e9 + 7;

long long dp[2][nmax];

void not_main()
{
    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 1e6; ++i)
    {
        dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % mod;
        dp[1][i] = (4 * dp[1][i - 1] + dp[0][i - 1]) % mod;
    }

    int t;
    cin >> t;
    int n;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        cout << (dp[0][n] + dp[1][n]) % mod << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}