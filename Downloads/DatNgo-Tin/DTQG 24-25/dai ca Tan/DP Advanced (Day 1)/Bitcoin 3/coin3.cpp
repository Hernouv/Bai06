#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int nmax = 1e6 + 10;
const ll outbound = 1e18;

int n, k;
int a[nmax];
ll dp[nmax][2];

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int j = 1; j <= k; ++j)
    {
        ll mx = -outbound;
        int cur = j % 2, prev = 1 - cur;
        for (int i = 2; i <= n; ++i)
        {
            maximize(mx, dp[i - 2][prev] - a[i - 1]);
            dp[i][cur] = max(dp[i - 1][cur], a[i] + mx);
        }
    }
    cout << max(dp[n][0], dp[n][1]);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}