#include <bits/stdc++.h>
using namespace std;

const int nmax = 110;
const int lim_w = 1e6 + 10;
const long long mod = 1e9 + 7;
int n, x;
int c[nmax];
long long dp[lim_w];

void not_main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= x; ++w)
            if (w >= c[i])
                dp[w] = (dp[w] + dp[w - c[i]]) % mod;

    cout << dp[x];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}