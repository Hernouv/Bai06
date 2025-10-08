#include <bits/stdc++.h>
using namespace std;

const int nmax = 105;

bool dp[5005][nmax];
int a[nmax], accum[nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        accum[i] = accum[i - 1] + a[i];
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j1 = min(accum[i], accum[n] / 2); j1 >= 0; --j1)
            for (int j2 = min(accum[i], accum[n] / 2); j2 >= 0; --j2)
                if (dp[j1 - a[i]][j2] or dp[j1][j2 - a[i]])
                    dp[j1][j2] = true;
    }

    for (int i = accum[n] / 2; i >= 0; --i)
    {
        if (dp[i][i])
        {
            cout << i;
            return;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}