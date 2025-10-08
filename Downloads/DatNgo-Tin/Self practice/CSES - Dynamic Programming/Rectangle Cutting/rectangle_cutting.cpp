#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e3 + 10;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

int a, b;
long long cnt = 0;
int dp[nmax][nmax];

void not_main()
{
    cin >> a >> b;
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; ++k)
                    minimize(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for (int k = 1; k < j; ++k)
                    minimize(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}