#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e3 + 10;
vector<int> graph[nmax];
int earning[nmax];
int dp[nmax][nmax];
int n, m, C;

void not_main()
{
    cin >> n >> m >> C;
    for (int i = 1; i <= n; ++i)
        cin >> earning[i];
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    memset(dp, -0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int T = 1; T <= nmax; ++T)
        for (int i = 1; i <= n; ++i)
            for (int v : graph[i])
                maximize(dp[i][T], dp[v][T - 1] + earning[i]);

    int res = dp[1][0];
    for (int i = 1; i <= nmax; ++i)
        maximize(res, dp[1][i] - C * i * i);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}