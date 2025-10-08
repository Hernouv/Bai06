#include <bits/stdc++.h>
using namespace std;

pair<int, long long> arr[500010], dp[500010];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].first >> arr[i].second;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = arr[i];
        for (int j = i - 1; j >= 1; --j)
        {
            if (dp[j].first < dp[i].first)
            {
                if (dp[j].second + arr[i].second > dp[i].second)
                {
                    dp[i].second = dp[j].second + arr[i].second;
                }
            }
            else
            {
                if (dp[j].second > dp[i].second)
                {
                    dp[i].first = dp[j].first;
                    dp[i].second = dp[j].second;
                }
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, dp[i].second);
    cout << res;
    return 0;
}