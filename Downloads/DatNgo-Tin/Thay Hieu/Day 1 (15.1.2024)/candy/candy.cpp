#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int dp[nmax][11];
int n, k;

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        dp[i][1] = 1;
    for (int i = 2; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}