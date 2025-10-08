#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("QBSTR.INP", "r", stdin);
    // freopen("QBSTR.OUT", "w", stdout);
    cin >> a >> b;
    int sa = a.size(), sb = b.size();
    a = ' ' + a;
    b = ' ' + b;
    dp[0][sb] = sb;
    dp[sa][0] = sa;
    for (int i = 1; i <= sa; ++i)
        for (int j = 1; j <= sb; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[sa][sb];
    return 0;
}