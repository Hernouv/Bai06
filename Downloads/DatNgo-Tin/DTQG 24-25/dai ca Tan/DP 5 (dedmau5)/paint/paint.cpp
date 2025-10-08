#include <bits/stdc++.h>
using namespace std;

#define whole(__) __.begin(), __.end()

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TOMAU.INP", "r"))
    {
        freopen("TOMAU.INP", "r", stdin);
        freopen("TOMAU.OUT", "w", stdout);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
    dp[0][0][0] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k <= n; ++k)
                if (dp[i][j][k] < INT_MAX)
                {
                    int ai = a[i];

                    {
                        int ni = i + 1;
                        int nj = j > 0 ? j + 1 : (k == 0 ? 1 : 0);
                        int nk = max(0, k - 1);
                        dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k]);
                    }

                    {
                        int ni = i + 1;
                        int nj = j > 0 ? j + 1 : 0;
                        if (nj <= ai)
                            nj = 0;
                        int nk = max(0, k - 1);
                        dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                    }

                    {
                        int ni = i + 1;
                        int nj = j > 0 ? j + 1 : 0;
                        int nk = max(ai - 1, k - 1);
                        dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                    }
                }

    cout << *min_element(whole(dp[n][0]));
    return 0;
}