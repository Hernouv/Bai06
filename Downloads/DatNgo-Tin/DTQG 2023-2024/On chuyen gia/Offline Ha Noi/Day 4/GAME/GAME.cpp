#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5000 + 10;
const int MOD = 1e9 + 7;

int add(int a, int b)
{
    return ((a + b) % MOD + MOD) % MOD;
}

int dp[MAXN][MAXN];
int k;
int f(int m, int n)
{
    if (m > n)
        m = n;
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <= 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = add(add(f(m - 1, n), f(m, n - m)), -f(m - 1, n - m - k));
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GAME.INP", "r"))
    {
        freopen("GAME.INP", "r", stdin);
        freopen("GAME.OUT", "w", stdout);
    }
    int m, n;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    cout << f(m, n);
    return 0;
}