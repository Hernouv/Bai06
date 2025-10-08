#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 510;
const ll outbound = 1e18;

int op[nmax][nmax];
ll dp[nmax][nmax];
string str;
int sz, k;

void not_main()
{
    cin >> k;
    cin >> str;
    sz = str.size();
    str = ' ' + str;
    for (int i = 1; i < sz; ++i)
        if (str[i] != str[i + 1])
            op[i][i + 1] = 1;

    for (int i = sz - 2; i >= 1; --i)
        for (int j = i + 2; j <= sz; ++j)
        {
            op[i][j] = op[i + 1][j - 1];
            if (str[i] != str[j])
                op[i][j] += 1;
        }

    for (int i = 1; i <= sz; ++i)
        dp[i][1] = op[1][i];
    for (int i = 2; i <= sz; ++i)
        for (int t = 2; t <= min(i, k); ++t)
        {
            dp[i][t] = outbound;
            for (int j = t - 1; j < i; ++j)
                dp[i][t] = min(dp[i][t], dp[j][t - 1] + op[j + 1][i]);
        }

    cout << dp[sz][k];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}