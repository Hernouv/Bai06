#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define bit(i, x) ((x >> i) & 1)

const int nmax = 25;

int n;
int a[nmax][nmax];
long long dp[1 << 21];

void not_main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    dp[0] = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        int t = __builtin_popcount(x);
        for (int i = 0; i < n; ++i)
            if (!bit(i, x))
            {
                int u = x + (1 << i);
                maximize(dp[u], dp[x] + a[i][t + 1]);
            }
    }
    cout << dp[(1 << n) - 1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}