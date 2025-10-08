#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
const int outbound = 1e9 + 7;

int a[nmax];

int n, sum;

int isSubsetSum(int n, int sum)
{
    vector<int> dp(n + 5, outbound), dp2(n + 5, outbound);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < a[i])
                dp2[j] = min(dp2[j], dp[j]);
            if (j >= a[i])
                dp2[j] = min({dp2[j], dp[j - a[i]] + 1});
        }
        dp = dp2;
    }

    return dp[sum];
}

void not_main()
{
    cin >> n >> sum;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());

    int val = isSubsetSum(n, sum);
    if (val <= 0 or val > n)
        cout << -1;
    else
        cout << val;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SUBSETMIN.INP", "r"))
    {
        freopen("SUBSETMIN.INP", "r", stdin);
        freopen("SUBSETMIN.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
