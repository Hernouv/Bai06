#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

int dp[1001][100001];
int h[1001];
int s[1001];
int n, x;

void not_main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= x; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i])
                maximize(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
        }
    cout << dp[n][x];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}