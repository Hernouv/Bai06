#include <bits/stdc++.h>
using namespace std;

int grid[110][110];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    int res = 0, cnt = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (grid[i][j] > res)
            {
                res = grid[i][j];
                cnt = 1;
            }
            else if (grid[i][j] == res)
            {
                cnt++;
            }
        }
    cout << res << ' ' << cnt;
    return 0;
}