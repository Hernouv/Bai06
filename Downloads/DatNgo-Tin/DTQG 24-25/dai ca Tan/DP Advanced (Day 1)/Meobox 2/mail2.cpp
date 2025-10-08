#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

#define int long long
const int nmax = 505;
const int outbound = 1e18;

int dp[nmax][nmax];
int n, k;
int x[nmax];
int accumx[nmax];

int s_dist(int l, int r)
{
    int m = (l + r) / 2;
    return (1LL * (m - l + 1) * x[m] - (accumx[m] - accumx[l - 1])) + ((accumx[r] - accumx[m]) - 1LL * (r - m) * x[m]);
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
        accumx[i] = accumx[i - 1] + x[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = outbound;
        for (int t_k = 1; t_k <= k; ++t_k)
        {
            dp[i][t_k] = outbound;
            for (int j = 1; j <= i; ++j)
                minimize(dp[i][t_k], dp[j - 1][t_k - 1] + s_dist(j, i));
        }
    }
    cout << dp[n][k];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MEOBOX2.INP", "r"))
    {
        freopen("MEOBOX2.INP", "r", stdin);
        freopen("MEOBOX2.OUT", "w", stdout);
    }
    not_main();
    return 0;
}