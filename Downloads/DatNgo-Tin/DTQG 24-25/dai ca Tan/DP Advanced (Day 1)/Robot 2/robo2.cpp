#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int nmax = 210;
const ll outbound = 1e16;

int n, m;
ll grid[nmax][nmax];
ll dp[nmax][nmax][nmax];

ll getVal(int xa, int ya, int xb, int yb)
{
    if (xa < 1 or xa > n or ya < 1 or ya > m or xb < 1 or xb > n or yb < 1 or yb > m)
        return -outbound;
    return dp[xa][ya][xb];
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> grid[i][j];

    for (int x1 = 1; x1 <= n; ++x1)
        for (int y1 = 1; y1 <= m; ++y1)
            for (int x2 = 1; x2 <= n; ++x2)
                dp[x1][y1][x2] = -outbound;
    dp[1][1][1] = grid[1][1];

    for (int x1 = 1; x1 <= n; ++x1)
        for (int y1 = 1; y1 <= m; ++y1)
            for (int x2 = 1; x2 <= n; ++x2)
            {
                if (x1 == 1 and y1 == 1 and x2 == 1)
                    continue;
                int y2 = x1 + y1 - x2;
                if (y2 > 0 and y2 <= m)
                {
                    ll d1 = getVal(x1 - 1, y1, x2 - 1, y2);
                    ll d2 = getVal(x1 - 1, y1, x2, y2 - 1);
                    ll d3 = getVal(x1, y1 - 1, x2 - 1, y2);
                    ll d4 = getVal(x1, y1 - 1, x2, y2 - 1);

                    if (x1 == x2 and y1 == y2)
                        dp[x1][y1][x2] = max({d1, d2, d3, d4}) + grid[x1][y1];
                    else
                        dp[x1][y1][x2] = max({d1, d2, d3, d4}) + grid[x1][y1] + grid[x2][y2];
                }
            }

    cout << dp[n][m][n];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}