#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
#define int long long

const int nmax = 210;
const int outbound = 1e18;

int grid[nmax][nmax];
int dp[nmax][nmax][nmax];
int n, m;
int res;

void not_main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j1 = 0; j1 < m; ++j1)
            for (int j2 = 0; j2 < m; ++j2)
                dp[i][j1][j2] = -outbound;

    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

    for (int i = 1; i < n; ++i)
    {
        for (int j1 = 0; j1 < m; ++j1)
        {
            for (int j2 = 0; j2 < m; ++j2)
            {
                for (int d1 = -1; d1 <= 1; ++d1)
                {
                    for (int d2 = -1; d2 <= 1; ++d2)
                    {
                        int prev_j1 = j1 + d1;
                        int prev_j2 = j2 + d2;
                        if (prev_j1 >= 0 and prev_j1 < m and prev_j2 >= 0 and prev_j2 < m)
                        {
                            int currVal = grid[i][j1];
                            if (j1 != j2)
                                currVal += grid[i][j2];
                            maximize(dp[i][j1][j2], dp[i - 1][prev_j1][prev_j2] + currVal);
                        }
                    }
                }
            }
        }
    }

    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
            maximize(res, dp[n - 1][j1][j2]);
    }

    cout << res << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}