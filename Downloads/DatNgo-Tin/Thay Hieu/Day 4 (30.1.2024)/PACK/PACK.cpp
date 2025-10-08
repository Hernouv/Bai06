#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e2 + 10, mmax = 1e4 + 10;
int n, m;
int w[nmax], v[nmax];
long long dp[nmax][mmax];

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= m; ++i)
        cin >> v[i];

    for (int i = 0; i <= n + 1; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= m + 1; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                maximize(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }

    cout << dp[n][m] << '\n';

    stack<int> chosen_items;
    int id = n, track_w = m;
    while (id)
    {
        if (dp[id][track_w] == dp[id - 1][track_w - w[id]] + v[id])
        {
            chosen_items.push(id);
            track_w -= w[id];
        }
        --id;
    }

    cout << chosen_items.size() << '\n';
    while (!chosen_items.empty())
    {
        cout << chosen_items.top() << ' ';
        chosen_items.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PACK.INP", "r"))
    {
        freopen("PACK.INP", "r", stdin);
        freopen("PACK.OUT", "w", stdout);
    }
    not_main();
    return 0;
}