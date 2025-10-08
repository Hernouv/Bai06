#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 510;
ll dp[nmax][nmax];
string str;
int sz;

void not_main()
{
    cin >> str;
    sz = str.size();
    str = ' ' + str;
    for (int i = 1; i <= sz; ++i)
        dp[i][i] = 1;
    for (int i = 1; i < sz; ++i)
        dp[i][i + 1] = (str[i] == str[i + 1] ? 2 : 1);
    for (int i = sz - 2; i >= 1; --i)
        for (int j = i + 2; j <= sz; ++j)
        {
            dp[i][j] = max({dp[i][j - 1], dp[i + 1][j], dp[i + 1][j - 1]});
            if (str[i] == str[j])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
        }
    cout << sz - dp[1][sz];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}