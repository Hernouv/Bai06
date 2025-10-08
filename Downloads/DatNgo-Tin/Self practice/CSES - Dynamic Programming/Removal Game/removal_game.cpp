#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e3;
long long dp[nmax + 1][nmax + 1];
long long arr[nmax + 1];
long long sum = 0;
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i <= n; ++i)
        dp[i][i] = arr[i];

    for (int j = 2; j <= n; ++j)
        for (int i = j - 1; i >= 1; --i)
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);

    cout << (sum + dp[1][n]) / 2;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}