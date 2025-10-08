#include <bits/stdc++.h>
using namespace std;

const long long outbound = -1e15;
long long grid[112][112];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("max.inp", "r", stdin);
    freopen("max.out", "w", stdout);
    for (int i = 1; i <= 110; ++i)
        for (int j = 1; j <= 110; ++j)
            grid[i][j] = outbound;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            grid[i][j] = max({grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1]}) + grid[i][j];
    long long res = outbound;
    for (int i = 1; i <= n; ++i)
        res = max(res, grid[n][i]);
    cout << res;
    return 0;
}