#include <bits/stdc++.h>
using namespace std;

#define int long long
const int nmax = 17;

int s[nmax];
int dp[nmax][(1 << nmax)];
int n, k;

void not_main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 0; i < n; ++i)
        dp[i][(1 << i)] = 1;

    for (int m = 3; m < (1 << n); ++m)
    {
        if (__builtin_popcount(m) == 1)
            continue;

        vector<int> bit1;
        for (int i = 0; i < n; ++i)
            if ((m >> i) & 1)
                bit1.push_back(i);

        for (int x : bit1)
            for (int y : bit1)
                if (x != y)
                    if (abs(s[y] - s[x]) > k)
                        dp[y][m] += dp[x][m - (1 << y)];
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
        res += dp[i][(1 << n) - 1];
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}