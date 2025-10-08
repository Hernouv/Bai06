#include <bits/stdc++.h>
using namespace std;
int grid[1010][1010];
int n, k, res, t;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> t;
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + t;
            if (i >= k and j >= k)
                res = max(res, grid[i][j] - grid[i - k][j] - grid[i][j - k] + grid[i - k][j - k]);
        }
    cout << res;
    return 0;
}