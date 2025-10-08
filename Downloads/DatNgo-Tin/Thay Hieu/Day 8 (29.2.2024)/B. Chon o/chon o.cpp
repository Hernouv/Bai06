#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e4 + 10;
int n;
int a[4][nmax], dp[16][nmax], res = -1e9;
vector<int> valid = {0, 1, 2, 4, 5, 8, 9, 10};

void not_main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 4; ++j)
        {
            cin >> a[j][i];
            maximize(res, a[j][i]);
        }
    if (res <= 0)
    {
        cout << res;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int x1 : valid)
        {
            int t_sum = 0;
            for (int it = 0; it < 4; ++it)
                if ((x1 >> it) & 1)
                    t_sum += a[it][i];

            for (int x2 : valid)
                if (!(x1 & x2))
                    maximize(dp[x1][i], dp[x2][i - 1] + t_sum);
        }
    }

    for (int i = 0; i < 11; ++i)
        maximize(res, dp[i][n]);
    cout << res;
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