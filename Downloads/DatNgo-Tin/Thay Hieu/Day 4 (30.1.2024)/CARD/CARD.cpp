#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 110;

int n;
int a[nmax];
int dp[nmax][nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = 0;
        for (int j = i; j <= n; ++j)
            dp[i][j] = 1e9 + 7;
    }

    for (int l = 2; l <= n; ++l)
        for (int i = 1; i <= n - l + 1; ++i)
            for (int j = i; j <= i + l - 1; ++j)
                for (int k = i; k <= j; ++k)
                    minimize(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);

    cout << dp[1][n];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CARD.INP", "r"))
    {
        freopen("CARD.INP", "r", stdin);
        freopen("CARD.OUT", "w", stdout);
    }
    not_main();
    return 0;
}