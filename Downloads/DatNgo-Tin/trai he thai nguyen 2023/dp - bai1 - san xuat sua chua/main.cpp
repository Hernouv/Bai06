#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[100001];
unsigned long long c[100001], y[100001];
unsigned long long res = 0;

int n, s;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    dp[0] = 0x3f;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> c[i] >> y[i];
    dp[1] = c[1] * y[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = c[i] * y[i];
        for (int j = 1; j < i; ++j) dp[i] = min(dp[i], c[j] * y[i] + s * (i - j) * y[i]);
        res += dp[i];
    }
    cout << res + dp[1];
    return 0;
}
