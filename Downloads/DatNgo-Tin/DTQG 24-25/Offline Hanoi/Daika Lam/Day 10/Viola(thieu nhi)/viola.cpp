#include <bits/stdc++.h>
using namespace std;

int a[12][12];
int r, c, n, k;

void not_main()
{
    cin >> r >> c >> n >> k;
    int tx, ty;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tx >> ty;
        a[tx][ty] = 1;
    }

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];

    int res = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            for (int ii = i; ii <= r; ++ii)
                for (int jj = j; jj <= c; ++jj)
                    if (a[ii][jj] - a[i - 1][jj] - a[ii][j - 1] + a[i - 1][j - 1] >= k)
                        ++res;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}