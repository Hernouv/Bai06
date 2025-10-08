#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int nmax = 5e3 + 10;
const int M = 2e6 + 10;
const int lim = 1e6 + 10;

int n, q;
int arr[nmax];
ll dp[nmax][nmax];
short t[M], cnt[nmax][nmax];

void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int x = arr[i] + arr[j];
            cnt[i][j] += (abs(x) < lim ? t[lim - x] : 0);
            ++t[lim + arr[j]];
        }
        for (int j = i + 1; j <= n; ++j)
            t[lim + arr[j]] = 0;
    }

    for (int i = n; i >= 1; --i)
        for (int j = i + 2; j <= n; ++j)
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + (ll)cnt[i][j];

    int l, r;
    for (int i = 1; i <= q; ++i)
    {
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}