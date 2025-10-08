#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 175;
const ll outbound = 1e18;

int m, n, k;
int color[nmax];
ll c[nmax][nmax];
ll dp[nmax][nmax][nmax];
ll res = outbound;

void setDefault()
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            for (int t = 1; t <= k; ++t)
                dp[i][j][t] = outbound;
}

void not_main()
{
    cin >> m >> n >> k;
    setDefault();
    for (int i = 1; i <= m; ++i)
        cin >> color[i];

    color[m + 1] = -1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    ll v1[nmax], v2[nmax];
    int p1[nmax], p2[nmax];

    if (color[1])
        dp[1][color[1]][1] = 0;
    else
    {
        vector<ill> s[2];
        for (int i = 1; i <= n; ++i)
        {
            dp[1][i][1] = c[1][i];
            s[1].emplace_back(i, c[1][i]);
        }
        sort(whole(s[1]), [](ill &a, ill &b)
             { return (a.se < b.se); });
        v1[1] = s[1][0].se, v2[1] = s[1][1].se;
        p1[1] = s[1][0].fi, p2[1] = s[1][1].fi;
    }

    for (int i = 2; i <= m; ++i)
    {
        if (color[i] and !color[i - 1])
        {
            int tc = color[i];
            for (int t = 1; t < min(i, k + 1); ++t)
            {
                if (tc != p1[t])
                    minimize(dp[i][tc][t + 1], v1[t]);
                else
                    minimize(dp[i][tc][t + 1], v2[t]);
            }

            for (int t = 1; t < min(i, k + 1); ++t)
                minimize(dp[i][color[i]][t], dp[i - 1][color[i]][t]);

            continue;
        }
        if (color[i] and color[i - 1])
        {
            int tc = color[i];
            int tc2 = color[i - 1];
            if (tc == tc2)
            {
                for (int t = 1; t < min(i, k + 1); ++t)
                    dp[i][tc][t] = dp[i - 1][tc][t];
            }
            else
            {
                for (int t = 1; t < min(i, k + 1); ++t)
                    dp[i][tc][t + 1] = dp[i - 1][tc2][t];
            }
            continue;
        }
        if (color[i - 1] and !color[i])
        {
            int tc = color[i - 1];
            for (int j = 1; j < tc; ++j)
                for (int t = 1; t < min(i, k + 1); ++t)
                    minimize(dp[i][j][t + 1], dp[i - 1][tc][t] + c[i][j]);
            for (int j = tc + 1; j <= n; ++j)
                for (int t = 1; t < min(i, k + 1); ++t)
                    minimize(dp[i][j][t + 1], dp[i - 1][tc][t] + c[i][j]);

            for (int t = 1; t < min(i, k + 1); ++t)
                minimize(dp[i][tc][t], dp[i - 1][tc][t] + c[i][tc]);
        }
        if (!color[i - 1] and !color[i])
        {
            for (int j = 1; j <= n; ++j)
                for (int t = 1; t < min(i, k + 1); ++t)
                {
                    if (j != p1[t])
                        minimize(dp[i][j][t + 1], v1[t] + c[i][j]);
                    else
                        minimize(dp[i][j][t + 1], v2[t] + c[i][j]);

                    minimize(dp[i][j][t], dp[i - 1][j][t] + c[i][j]);
                }
        }
        if (!color[i])
        {
            vector<ill> s[nmax];
            for (int j = 1; j <= n; ++j)
                for (int t = 1; t <= min(i, k); ++t)
                    s[t].emplace_back(j, dp[i][j][t]);

            for (int t = 1; t <= min(i, k); ++t)
            {
                sort(whole(s[t]), [](ill &a, ill &b)
                     { return (a.se < b.se); });
                v1[t] = s[t][0].se, v2[t] = s[t][1].se;
                p1[t] = s[t][0].fi, p2[t] = s[t][1].fi;
            }
        }
    }

    for (int j = 1; j <= n; ++j)
        cerr << dp[2][j][1] << ' ';

    for (int i = 1; i <= n; ++i)
        minimize(res, dp[m][i][k]);
    cout << (res == outbound ? -1 : res);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}