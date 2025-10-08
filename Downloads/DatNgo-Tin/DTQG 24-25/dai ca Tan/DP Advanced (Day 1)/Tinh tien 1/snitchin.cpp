#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;

const int nmax = 2010;
const ll outbound = 1e18;

int n;
int t[nmax];
ll c[nmax];
ll dp[nmax][2 * nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i] >> c[i];
        ++t[i];
    }

    // dp[0][0] = 0;
    for (int i = 1; i <= n + 2000; ++i)
        dp[0][i] = outbound;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 2000; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (t[i] <= j)
                minimize(dp[i][j], dp[i - 1][j - t[i]] + c[i]);
        }

    ll res = outbound;
    for (int j = n; j <= n + 2000; ++j)
        minimize(res, dp[n][j]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}