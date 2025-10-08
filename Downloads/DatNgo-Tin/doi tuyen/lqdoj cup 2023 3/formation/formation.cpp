#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int grid[2020][2020];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("formation.inp", "r", stdin);
    freopen("formation.out", "w", stdout);
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> grid[i][j];
    if (k == 1)
        cout << 0;
    return 0;
}