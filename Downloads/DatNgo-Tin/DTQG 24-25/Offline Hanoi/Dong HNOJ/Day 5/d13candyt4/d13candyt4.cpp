#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;
const int lim = 105;
const ll outbound = 1e18;

int m, T;
ll d[nmax];
ll ad[nmax];
ll dp[105][105];
int cnt[105][105];
ii par[105][105];
int n[2 * lim];
ll ans[2 * lim];

void not_main()
{
    cin >> m >> T;
    for (int i = 1; i <= m; ++i)
        cin >> d[i];
    sort(d + 1, d + m + 1);
    for (int i = 1; i <= m; ++i)
        ad[i] = ad[i - 1] + d[i];

    int S = 0;
    for (int i = 1; i <= T; ++i)
    {
        cin >> n[i];
        n[i] %= m;
        maximize(S, n[i]);
    }
    for (int i = 2; i <= S; ++i)
        for (int s = i; s <= S; ++s)
            dp[i][s] = outbound;
    for (int s = 1; s <= S; ++s)
    {
        dp[1][s] = 1LL * ad[m - s] * s;
        cnt[1][s] = s;
    }

    for (int i = 1; i < S; ++i)
    {
        for (int s = i; s <= S; ++s)
        {
            int c = cnt[i][s];
            int pc = 0;
            ii pidx = {i, s};
            for (int k = 1; s + k <= S; ++k)
            {
                if (k > c)
                {
                    pc = c;
                    c = cnt[par[i][s].fi][par[i][s].se];
                    pidx = {par[i][s].fi, par[i][s].se};
                }

                if (k < c)
                {
                    int t = k - pc;
                    if (minimize(dp[i + 1][s + k], dp[i][s] + ad[m - t] * t))
                    {
                        cnt[i + 1][s + k] = k;
                        par[i + 1][s + k] = pidx;
                    }
                }
                else if (k == c)
                {
                    if (minimize(dp[i + 1][s + k], dp[i][s]))
                    {
                        cnt[i + 1][s + k] = k;
                        par[i + 1][s + k] = pidx;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= T; ++i)
    {
        if (!n[i])
        {
            cout << 0 << '\n';
            continue;
        }
        ll res = outbound;
        ii idx;
        for (int j = 1; j <= n[i]; ++j)
            minimize(res, dp[j][n[i]]);
        cout << res << ' ';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}