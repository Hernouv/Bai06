#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &nums)
{
    vector<int> v;
    v.push_back(1);
    for (int it : nums)
        v.push_back(it);
    v.push_back(1);
    int n = v.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j - i < 2)
                continue;
            int ans = 0;
            for (int k = i + 1; k < j; ++k)
            {
                int tmp = v[k] * v[i] * v[j] + dp[i][k] + dp[k][j];
                ans = max(ans, tmp);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[0][n - 1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    solve(v);
}