#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
const long long mod = 1e9 + 7;
long long dp[nmax];
int n;

void not_main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 6 and i >= j; ++j)
            dp[i] = (dp[i] + dp[i - j]) % mod;
    cout << dp[n];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}