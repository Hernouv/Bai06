#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string x, rx;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> x;
    rx = x;
    int xs = x.size();
    reverse(rx.begin(), rx.end());
    x = ' ' + x;
    rx = ' ' + rx;
    dp[0][xs] = xs;
    dp[xs][0] = xs;
    for (int i = 1; i <= xs; ++i)
        for (int j = 1; j <= xs; ++j)
        {
            if (x[i] == rx[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    int i, j;
    i = j = xs;
    string res = "";
    while (i and j)
    {
        if (x[i] == rx[j])
        {
            res += x[i];
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    cout << res;
}
// lmevxeyzl
// lzyexveml