#include <bits/stdc++.h>
using namespace std;

#define int long long

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 19;
const int outbound = 1e9 + 10;

int c[nmax][nmax], res;
int dp[nmax][(1 << nmax)];
vector<int> premsk[nmax];
int n, m, k;

void not_main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> c[i][i];

    int tu, tv, tc;
    for (int i = 0; i < k; ++i)
    {
        cin >> tu >> tv >> tc;
        c[tu - 1][tv - 1] = tc;
    }

    for (int i = 1; i < (1 << n); ++i)
        premsk[__builtin_popcount(i)].push_back(i);
    for (int i = 0; i < n; ++i)
        dp[i][(1 << i)] = c[i][i];

    for (int i = 1; i < min(m, n); ++i)
        for (int msk : premsk[i])
        {
            vector<int> bit0, bit1;
            for (int it = 0; it < n; ++it)
                if ((msk >> it) & 1)
                    bit1.push_back(it);
                else
                    bit0.push_back(it);

            for (int x : bit1)
                for (int y : bit0)
                    maximize(dp[y][msk + (1 << y)], dp[x][msk] + c[x][y] + c[y][y]);
        }

    for (int msk : premsk[min(m, n)])
        for (int i = 0; i < n; ++i)
            if ((msk >> i) & 1)
                maximize(res, dp[i][msk]);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}