#include "bits/stdc++.h"
#include "egg.h"
using namespace std;

const int inf = 2e9;

int solve(int e, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(e + 1, 0)), opt(n + 1, vector<int>(e));
    for (int i = 1; i <= n; i++)
        dp[i][0] = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= e; j++)
        {
            if (i == 1)
            {
                dp[i][j] = 1;
                opt[i][j] = 1;
                continue;
            }

            dp[i][j] = inf;
            for (int m = 1; m < i; m++)
            {
                int cost = max(dp[m - 1][j - 1], dp[i - m][j]) + 1;
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    opt[i][j] = m;
                }
            }
        }
    }
    int E = e, N = n;
    int ans = 0;
    while (N > 0)
    {
        int m = opt[N][E];
        if (drop(ans + m))
        {
            N = N - m;
            ans += m;
        }
        else
        {
            N = m - 1;
            E--;
        }
    }
    return ans;
}
