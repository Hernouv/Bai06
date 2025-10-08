#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e3 + 5;

int n;
ll a[2 * nmax];
ll dp[2 * nmax][2 * nmax];
int res = 0;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; ++i)
        dp[i][i] = a[i];
    for (int i = 2 * n - 1; i >= 1; --i)
        for (int j = i + 1; j <= 2 * n; ++j)
        {
            int l = (j - i + 1);
            if (l > n)
                break;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    for (int i = 1; i <= n; ++i)
        if (a[i] - dp[i + 1][i + n - 1] > 0)
        {
            ++res;
        }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SELECT.INP", "r"))
    {
        freopen("SELECT.INP", "r", stdin);
        freopen("SELECT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}