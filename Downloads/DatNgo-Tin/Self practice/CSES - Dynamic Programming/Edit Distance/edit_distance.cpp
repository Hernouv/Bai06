#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

string a, b;
int dp[5010][5010];

void not_main()
{
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    cin >> a >> b;
    for (int i = 0; i <= a.size(); ++i)
        for (int j = 0; j <= b.size(); ++j)
        {
            if (i)
                minimize(dp[i][j], dp[i - 1][j] + 1);
            if (j)
                minimize(dp[i][j], dp[i][j - 1] + 1);
            if (i and j)
                minimize(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    cout << dp[a.size()][b.size()];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}