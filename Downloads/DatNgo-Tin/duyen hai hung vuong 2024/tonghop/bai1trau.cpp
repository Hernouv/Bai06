#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int sub_nmax = 1e3 + 10;
const int outbound = 1e9 + 7;

int dp[sub_nmax][sub_nmax];
int a[sub_nmax];
int n_sum[sub_nmax];
int n, k, res = outbound;

void defaultSet()
{
    memset(dp, outbound, sizeof dp);
}

void not_main()
{
    defaultSet();
    dp[0][0] = 0;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        n_sum[i] = n_sum[i - 1] + a[i];

    for (int i = 1; i <= n; ++i)
        dp[i][a[i]] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = a[i]; j <= min(k, n_sum[i]); ++j)
            if (dp[i][j] != outbound)
                for (int g = i + 1; g <= n; ++g)
                    if (j + a[g] <= k)
                        minimize(dp[g][j + a[g]], dp[i][j] + 1);

    for (int i = 1; i <= n; ++i)
        minimize(res, dp[i][k]);

    if (res <= 0 or res > n)
        cout << -1;
    else
        cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SUBSETMIN.INP", "r"))
    {
        freopen("SUBSETMIN.INP", "r", stdin);
        freopen("SUBSETMIN.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
