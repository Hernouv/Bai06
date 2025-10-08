#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tri;
const int nmax = 105;
int n, m, p, q, f[nmax][nmax][2];

void not_main()
{
    int i, j;
    cin >> n >> m >> p >> q;
    memset(f, -1, sizeof(f));
    queue<tri> Q;
    Q.push({n, m, 0});
    f[n][m][0] = 0;
    while (!Q.empty())
    {
        auto [x, y, tp] = Q.front();
        Q.pop();
        if (x == 0)
        {
            cout << f[x][y][tp];
            return;
        }
        if (tp == 0)
        {
            for (i = 0; i <= min(p, x); ++i)
                for (j = 0; j <= min(p - i, y); ++j)
                {
                    if (x - i > 0 and (y - j) - (x - i) > q)
                        continue;
                    if (f[x - i][y - j][tp ^ 1] == -1)
                        f[x - i][y - j][tp ^ 1] = f[x][y][tp] + 1, Q.push({x - i, y - j, tp ^ 1});
                }
        }
        else
        {
            for (i = 0; i <= min(p, n - x); ++i)
                for (j = 0; j <= min(p - i, m - y); ++j)
                {
                    if (n - x - i > 0 and (m - y - j) - (n - x - i) > q)
                        continue;
                    if (f[x + i][y + j][tp ^ 1] == -1)
                        f[x + i][y + j][tp ^ 1] = f[x][y][tp] + 1, Q.push({x + i, y + j, tp ^ 1});
                }
        }
    }
    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
