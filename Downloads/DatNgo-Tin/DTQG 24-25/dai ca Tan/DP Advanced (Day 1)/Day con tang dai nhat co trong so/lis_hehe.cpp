#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 505;

int n;
long long w;
int a[(int)1e6 + 5];
int dp[nmax][nmax];

int b[(int)1e6 + 5];
void LIS()
{
    memset(b, 0x3f, sizeof b);
    b[0] -= 2 * b[0];
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k = lower_bound(b + 1, b + n + 1, a[i]) - b;
        b[k] = a[i];
        maximize(res, k);
    }

    cout << res;
}

void not_main()
{
    cin >> n >> w;
    long long s = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }

    if (s != w)
    {
        int res = 0;
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
            {
                for (int i_prev = i - 1; i_prev >= 0; --i_prev)
                    if (a[i] > a[i_prev])
                        minimize(dp[i][j], dp[i_prev][j - 1] + a[i]);

                if (dp[i][j] <= w)
                    maximize(res, j);
            }
        cout << res;
    }
    else
        LIS();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}