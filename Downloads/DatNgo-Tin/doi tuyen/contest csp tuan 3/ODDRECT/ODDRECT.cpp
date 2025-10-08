#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("ODDRECT.INP", "w", stdin);
    freopen("ODDRECT.OUT", "w", stdout);
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            grid[i][j] = 0;
    int n;
    int x1, y1, x2, y2;
    int xmin = 1001, xmax = -1, ymin = 1001, ymax = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        xmin = min(xmin, x1);
        ymin = min(ymin, y1);
        xmax = max(xmax, x2);
        ymax = max(ymax, y2);
        for (int j = y1; j <= y2; ++j)
            for (int k = x1; k <= x2; ++k)
                grid[k][j]++;
    }
    int res = 0;
    for (int i = ymin; i <= ymax; ++i)
        for (int j = xmin; j <= xmax; ++j)
            res += (grid[j][i] % 2);
    cout << res;
    return 0;
}