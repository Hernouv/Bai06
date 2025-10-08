#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 5e5 + 10;
const int outbound = 1e9 + 10;

vector<ii> pos_list[2 * nmax];
vector<vector<int>> dp;
vector<vector<int>> grid;

int row[nmax], col[nmax];
int n, m;
int res = 0;

void not_main()
{
    cin >> n >> m;
    grid.resize(n + 2, vector<int>(m + 2));
    dp.resize(n + 2, vector<int>(m + 2));
    int tmp;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> tmp;
            grid[i][j] = tmp;
        }
    }
    int maxVal = -1, minVal = outbound;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int tVal = grid[i][j] + nmax - 10;
            pos_list[tVal].emplace_back(i, j);
            minimize(minVal, tVal);
            maximize(maxVal, tVal);
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i].push_back(0);

    for (int i = minVal; i <= maxVal; ++i)
    {
        for (ii x : pos_list[i])
        {
            maximize(dp[x.fi][x.se], max(row[x.fi], col[x.se]) + 1);
            maximize(res, dp[x.fi][x.se]);
        }

        for (ii x : pos_list[i])
        {
            maximize(row[x.fi], dp[x.fi][x.se]);
            maximize(col[x.se], dp[x.fi][x.se]);
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}