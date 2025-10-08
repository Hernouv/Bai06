#include <bits/stdc++.h>
using namespace std;

int arr[10010], n, k;
int dp[10010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int tmax = arr[i];
        for (int j = 0; j < min(i, k); ++j)
        {
            tmax = max(tmax, arr[i - j]);
            dp[i] = max(dp[i], (j + 1) * tmax + dp[i - j - 1]);
        }
    }
    cout << dp[n];
}