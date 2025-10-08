#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 22;
const int mod = 1e9 + 7;

bool coup[nmax][nmax];
ll dp[nmax][(1 << nmax)];
vector<int> premsk[nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> coup[i][j];

    for (int i = 1; i < (1 << n); ++i)
        premsk[__builtin_popcount(i)].push_back(i);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int m : premsk[i])
            for (int it = 0; it < n; ++it)
                if (((m >> it) & 1) and coup[i][it])
                    dp[i][m] = (dp[i][m] + dp[i - 1][m ^ (1 << it)]) % mod;
    }

    cout << dp[n][(1 << n) - 1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}