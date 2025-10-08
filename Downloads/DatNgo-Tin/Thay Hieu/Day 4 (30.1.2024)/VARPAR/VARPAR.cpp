#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 110;
typedef long double ld;

int n, k;
ld a[nmax];
ld variance[nmax][nmax];
ld avg[nmax][nmax];
ld dp[nmax][nmax];

void var_cal(int l, int r)
{
    ld tmp = avg[l][r];
    for (int i = l; i <= r; ++i)
        variance[l][r] += ((a[i] - tmp) * (a[i] - tmp));
    variance[l][r] /= (r - l + 1);
    return;
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    // for (int i = 1; i <= n; ++i)
    //     cout << fixed << setprecision(0) << a[i] << '\n';

    for (int i = 1; i <= n; ++i)
        avg[1][i] = avg[1][i - 1] + a[i];
    for (int i = 2; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            avg[i][j] = avg[1][j] - avg[1][i - 1];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            avg[i][j] /= (j - i + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            var_cal(i, j);

    // cout << fixed << setprecision(5) << variance[2][3] << '\n';

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            dp[i][j] = 1e9 + 7;
    dp[0][0] = 0;

    for (int p = 1; p <= k; ++p)
        for (int i = p; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                minimize(dp[i][p], dp[j][p - 1] + variance[j + 1][i]);

    cout << fixed << setprecision(5) << dp[n][k];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("VARPAR.INP", "r"))
    {
        freopen("VARPAR.INP", "r", stdin);
        freopen("VARPAR.OUT", "w", stdout);
    }
    not_main();
}