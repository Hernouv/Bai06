#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;
const int outbound = 1e9 + 10;

multiset<int> row[nmax], col[nmax];
vector<vector<int>> grid;
vector<vector<int>> dp;
vector<vector<vector<int>>> del_row, del_col;
int n, m;

void not_main()
{
    cin >> n >> m;
    dp.resize(n + 2, vector<int>(m + 2));
    grid.resize(n + 2, vector<int>(m + 2));
    del_row.resize(n + 2, vector<vector<int>>(m + 2));
    del_col.resize(n + 2, vector<vector<int>>(m + 2));
    // for (int i = 1; i <= n; i++)
    //     row[i].clear();
    // for (int i = 1; i <= m; i++)
    //     col[i].clear();

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         del_row[i][j].clear(), del_col[i][j].clear(), dp[i][j] = 0;

    int tmp;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> tmp;
            grid[i][j] = tmp;
        }

    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            for (int x : del_row[i][j])
                row[i].erase(row[i].find(x));
            for (int x : del_col[i][j])
                col[j].erase(col[j].find(x));

            int min_row = outbound, min_col = outbound;
            if (!row[i].empty() or !col[j].empty())
            {
                if (!row[i].empty())
                    min_row = *(row[i].begin());
                if (!col[j].empty())
                    min_col = *(col[j].begin());
                dp[i][j] = min(min_row, min_col) + 1;
            }
            if ((i == 1 and j == 1) or dp[i][j] != 0)
            {
                int row_lim = i + grid[i][j] + 1;
                int col_lim = j + grid[i][j] + 1;

                if (row_lim <= n)
                    del_col[row_lim][j].push_back(dp[i][j]);
                if (col_lim <= m)
                    del_row[i][col_lim].push_back(dp[i][j]);

                row[i].insert(dp[i][j]);
                col[j].insert(dp[i][j]);
            }
        }
    cout << (dp[n][m] ? dp[n][m] : -1);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}