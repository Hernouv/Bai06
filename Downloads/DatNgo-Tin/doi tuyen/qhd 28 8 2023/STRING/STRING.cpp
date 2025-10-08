#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("STRING.INP", "r", stdin);
    // freopen("STRING.OUT", "w", stdout);
    cin >> a >> b;
    int a_sz = a.size(), b_sz = b.size();
    a = ' ' + a;
    b = ' ' + b;
    dp[0][b_sz] = b_sz;
    dp[a_sz][0] = a_sz;
    for (int i = 1; i <= a_sz; ++i)
        for (int j = 1; j <= b_sz; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    cout << dp[a_sz][b_sz];
    return 0;
}