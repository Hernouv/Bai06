#include <bits/stdc++.h>
using namespace std;
#define int long long

const long long mod = 1000000007;

int n;
char A[1010][1010];

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }
}

int dp[503][503][2];

void add(int &x, int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

void sol()
{
    memset(dp, 0, sizeof(dp));
    dp[1][n][0] = (A[1][1] == A[n][n]);

    // int test = sizeof(dp) / 1024 / 1024;
    // cout << test << endl;

    for (int k = 0; k < n; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = n; i2 >= i1; i2--)
            {
                dp[i1][i2][(k + 1) & 1] = 0;
            }
        }
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = n; i2 >= i1; i2--)
            {
                int j1 = k + 2 - i1;
                int j2 = 2 * n - k - i2;
                int k1 = k & 1;
                int k2 = (k + 1) & 1;

                if (A[i1][j1 + 1] == A[i2][j2 - 1])
                {
                    add(dp[i1][i2][k2], dp[i1][i2][k1]);
                }
                if (A[i1][j1 + 1] == A[i2 - 1][j2])
                {
                    add(dp[i1][i2 - 1][k2], dp[i1][i2][k1]);
                }
                if (A[i1 + 1][j1] == A[i2][j2 - 1])
                {
                    add(dp[i1 + 1][i2][k2], dp[i1][i2][k1]);
                }
                if (A[i1 + 1][j1] == A[i2 - 1][j2])
                {
                    add(dp[i1 + 1][i2 - 1][k2], dp[i1][i2][k1]);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        add(res, dp[i][i][(n - 1) & 1]);
    }
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        in();
        if (n == 0)
            break;
        sol();
    }
    return 0;
}