#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 17;
const int outbound = 1e9 + 10;

int c[nmax][nmax];
int dp[nmax][(1 << nmax)];
int n;

void not_main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    for (int i = 0; i < n; ++i)
        for (int m = 0; m < (1 << n); ++m)
            dp[i][m] = outbound;
    for (int i = 0; i < n; ++i)
        dp[i][(1 << i)] = 0;
    for (int m = 1; m < (1 << n); ++m)
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
                    minimize(dp[y][m], dp[x][m - (1 << y)] + c[x][y]);
    }

    int res = outbound;
    for (int i = 0; i < n; ++i)
        minimize(res, dp[i][(1 << n) - 1]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}