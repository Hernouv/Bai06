#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e4 + 10;

int n;
int t[nmax], r[nmax];
int dp[nmax], par[nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i < n; ++i)
        cin >> r[i];

    dp[n] = t[n];
    par[n] = n + 1;
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        int t1 = dp[i + 1] + t[i];
        int t2 = dp[i + 2] + r[i];
        if (t1 <= t2)
        {
            dp[i] = t1;
            par[i] = i + 1;
        }
        else
        {
            dp[i] = t2;
            par[i] = i + 2;
        }
    }
    cout << dp[1] << '\n';
    int track = 1;
    while (track <= n)
    {
        if (par[track] == track + 2)
        {
            cout << track + 1 << ' ';
            track += 2;
        }
        else
            track++;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TICK.INP", "r"))
    {
        freopen("TICK.INP", "r", stdin);
        freopen("TICK.OUT", "w", stdout);
    }
    not_main();
    return 0;
}