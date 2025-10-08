#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 110;
const int lim_w = 1e6 + 10;
const int outbound = 1e9 + 7;

int c[nmax];
long long dp[lim_w];
int n, x;

void not_main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    dp[0] = 0;
    for (int i = 1; i <= x; ++i)
        dp[i] = outbound;

    for (int i = 1; i <= n; ++i)
        for (int w = 0; w <= x; ++w)
            if (w >= c[i])
                minimize(dp[w], dp[w - c[i]] + 1);

    cout << (dp[x] == outbound ? -1 : dp[x]);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}