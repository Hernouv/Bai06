#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    reverse(a.begin() + 1, a.end());

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    static long long dp[5001][5001];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;

    for (int j = 1; j <= n; j++)
    {
        for (int i = j; i <= n; i++)
        {
            long long best = -1;
            for (int l = j - 1; l < i; l++)
            {
                if (dp[l][j - 1] == -1)
                    continue;
                long long sum = prefix[i] - prefix[l];
                if (sum >= dp[l][j - 1])
                {
                    if (best == -1 || sum < best)
                    {
                        best = sum;
                    }
                }
            }
            dp[i][j] = best;
        }
    }

    int ans = 0;
    for (int j = 1; j <= n; j++)
    {
        if (dp[n][j] != -1)
            ans = j;
    }

    cout << ans << "\n";
    return 0;
}
