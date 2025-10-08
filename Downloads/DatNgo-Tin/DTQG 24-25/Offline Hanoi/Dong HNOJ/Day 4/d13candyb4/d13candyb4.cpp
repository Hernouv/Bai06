#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mx = 1e5 + 6;
const int mx_sqrt = 350;
int n, k, MOD, dp[mx_sqrt][mx], ans;

void add(int &a, const int &b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void Process()
{
    cin >> n >> k >> MOD;
    dp[0][0] = 1;
    for (int i = 1; i <= sqrt(n) + 1; ++i)
        for (int j = 0; j <= n; ++j)
        {
            if (j >= i)
                add(dp[i][j], dp[i][j - i]);
            if (j - 1 - (i - 1) * (k + 1) >= 0)
                add(dp[i][j], dp[i - 1][j - 1 - (i - 1) * (k + 1)]);
        }
    for (int i = 2; i <= sqrt(n) + 1; ++i)
        add(ans, dp[i][n]);
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(NULL);
    Process();
    return 0;
}