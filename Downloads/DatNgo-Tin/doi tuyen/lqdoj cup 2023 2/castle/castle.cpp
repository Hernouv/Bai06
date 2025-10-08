#include <bits/stdc++.h>
using namespace std;

int r, c;
int grid[2020][2020];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("castle.inp", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> grid[i][j];

    unsigned long long res = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            int si = 1, sj = 1;
            while (si + i <= r and sj + j <= c)
            {
                bool valid = true;
                int check = grid[si][sj];
                for (int k = si; k <= si + i; ++k)
                    for (int l = sj; l <= sj + j; ++l)
                    {
                        if (grid[k][l] != check)
                        {
                            valid = false;
                            break;
                        }
                    }
                if (valid)
                    res++;
                sj++;
                if (sj + j == c + 1)
                {
                    si++;
                    sj = 1;
                }
            }
        }
    cout << res;
    return 0;
}