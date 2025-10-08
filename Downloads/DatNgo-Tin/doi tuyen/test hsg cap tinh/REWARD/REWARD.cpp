#include <bits/stdc++.h>
using namespace std;

long long dp[100001];
int cnt[100001];
long long arr[100001];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("REWARD.INP", "w", stdin);
    // freopen("REWARD.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    dp[0] = 0;
    dp[1] = arr[1], cnt[1] = 1;
    dp[2] = arr[1] + arr[2], cnt[2] = 2;
    dp[3] = max(arr[1], arr[2]) + arr[3];

    if (arr[3] == arr[1] + arr[3])
        cnt[3] = 1;
    else
        cnt[3] = 2;

    for (int i = 4; i <= n; ++i)
    {
        // int case0 = (cnt[i - 1] < 2 ? dp[i - 1] + arr[i] : 0);
        // int case1 = dp[i - 2] + arr[i];
        // int case2 = dp[i - 3] + arr[i];
        // int case3 = dp[i - 1];
        // int case4 = dp[i - 3] + arr[i - 1] + arr[i];
        // int case5 = dp[i - 4] + arr[i - 1] + arr[i];
        dp[i] = dp[i - 1] + (cnt[i - 1] < 2 ? arr[i] : 0);
        cnt[i] = (cnt[i - 1] < 2 ? cnt[i - 1] + 1 : 0);

        int t = dp[i];
        dp[i] = max(dp[i], max(dp[i - 2], dp[i - 3]) + arr[i]);
        if (t != dp[i])
            cnt[i] = 1;

        t = dp[i];
        dp[i] = max(dp[i], max(dp[i - 3], dp[i - 4]) + arr[i - 1] + arr[i]);
        if (t != dp[i])
            cnt[i] = 2;
    }

    cout << dp[n];
    return 0;
}