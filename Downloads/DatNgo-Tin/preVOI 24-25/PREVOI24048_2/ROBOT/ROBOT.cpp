#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ll2;
#define fi first
#define se second

#define loop(__, l, r) for (int __ = l; __ <= r; ++__)

int m, n, q;
vector<vector<ll>> diamonds;
vector<vector<ll>> dp;
vector<vector<char>> par;
vector<vector<bool>> original_path;

void backtrace_original_path(int x, int y)
{
    if (original_path[x][y] == true)
        return;

    original_path[x][y] = true;
    if (par[x][y] == 'L')
        backtrace_original_path(x, y - 1);
    else if (par[x][y] == 'U')
        backtrace_original_path(x - 1, y);
    else if (par[x][y] == 'B')
    {
        backtrace_original_path(x, y - 1);
        backtrace_original_path(x - 1, y);
    }
}

bool check_affected(int x, int y)
{
    if (y + 1 <= n and par[x][y + 1] != 'L')
        return false;
    if (x + 1 <= m and par[x + 1][y] != 'U')
        return false;
    return true;
}

void not_main()
{
    cin >> m >> n >> q;
    diamonds.resize(m + 4, vector<ll>(n + 4, 0));
    dp.resize(m + 4, vector<ll>(n + 4, 0));
    par.resize(m + 4, vector<char>(n + 4, 'A'));
    original_path.resize(m + 4, vector<bool>(n + 4, false));

    loop(i, 1, m)
    {
        loop(j, 1, n)
        {
            cin >> diamonds[i][j];
        }
    }

    loop(i, 1, m)
    {
        loop(j, 1, n)
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                dp[i][j] = dp[i][j - 1] + diamonds[i][j];
                par[i][j] = 'L';
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                {
                    dp[i][j] = dp[i - 1][j] + diamonds[i][j];
                    par[i][j] = 'U';
                }
            }
            else if (dp[i - 1][j] == dp[i][j - 1])
            {
                {
                    dp[i][j] = dp[i - 1][j] + diamonds[i][j];
                    par[i][j] = 'B';
                }
            }
        }
    }

    backtrace_original_path(m, n);

    int tx, ty;
    loop(i, 1, q)
    {
        cin >> tx >> ty;
        if (!original_path[tx][ty] or !check_affected(tx, ty))
        {
            cout << dp[m][n] << '\n';
            continue;
        }
        vector<vector<ll>> dp2 = dp;
        dp2[tx][ty] = 0;
        loop(ii, ty + 1, n)
            dp2[tx][ii] = max(dp2[tx - 1][ii], dp2[tx][ii - 1]) + diamonds[tx][ii];
        loop(ii, tx + 1, m)
        {
            loop(jj, ty, n)
            {
                dp2[ii][jj] = max(dp2[ii - 1][jj], dp2[ii][jj - 1]) + diamonds[ii][jj];
            }
        }
        cout << dp2[m][n] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ROBOT.INP", "r"))
    {
        freopen("ROBOT.INP", "r", stdin);
        freopen("ROBOT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}