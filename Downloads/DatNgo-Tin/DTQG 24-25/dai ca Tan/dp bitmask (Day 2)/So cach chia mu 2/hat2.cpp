#include <bits/stdc++.h>
using namespace std;

const int nmax = 17, mmax = 51;
const int mod = 1e9 + 7;

bool coup[nmax][mmax];
int dp[mmax][(1 << nmax)];
int n, m;

void not_main()
{
    cin >> n >> m;
    int tcnt, tm;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tcnt;
        for (int j = 1; j <= tcnt; ++j)
        {
            cin >> tm;
            coup[i][tm] = true;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int msk = 0; msk < (1 << n); ++msk)
        {
            dp[i][msk] = dp[i - 1][msk];
            for (int it = 0; it < n; ++it)
                if ((msk >> it) & 1 and coup[it + 1][i])
                    dp[i][msk] = (dp[i][msk] + dp[i - 1][msk - (1 << it)]) % mod;
        }
    }

    cout << dp[m][(1 << n) - 1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}