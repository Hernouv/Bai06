#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
const int mmax = 1e5 + 10;
const int mod = 998244353;

void add(int &x, const int &y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

int n, k, a[nmax], cnt[mmax], dp[2][nmax], sum[2][nmax];
void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int maxval = a[n], res = 0;

    for (int v = maxval / (k - 1); v >= 1; --v)
    {
        int prev = 0, cur = 1;
        for (int i = 1; i <= n; ++i)
            sum[prev][i] = i, dp[prev][i] = 1;
        for (int i = 2; i <= k; ++i)
        {
            for (int j = 1; j <= n; ++j)
                dp[cur][j] = sum[cur][j] = 0;
            int l = 1;
            for (int j = 1; j <= n; ++j)
            {
                while (l + 1 < j and a[j] - a[l + 1] >= v)
                    ++l;
                if (a[j] - a[l] < v)
                    continue;
                dp[cur][j] = sum[prev][l];
                sum[cur][j] = (sum[cur][j - 1] + dp[cur][j]) % mod;
            }
            prev ^= 1, cur ^= 1;
        }
        for (int i = 1; i <= n; ++i)
            add(cnt[v], dp[prev][i]);
        int tmp = (cnt[v] - cnt[v + 1] + mod) % mod;
        add(res, 1LL * v * tmp % mod);
    }
    cout << res;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BLOCKS.INP", "r"))
    {
        freopen("BLOCKS.INP", "r", stdin);
        freopen("BLOCKS.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
