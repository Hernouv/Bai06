#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("LIQ.INP", "r", stdin);
    freopen("LIQ.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; --j)
            if (arr[i] >= arr[j] and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    int res = 0;
    for (int i = n; i >= 1; --i)
        res = max(res, dp[i]);
    cout << res;
    return 0;
}
// 13205