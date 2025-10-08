#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;

int f[nmax][nmax];
string x, y;

void not_main()
{
    cin >> x >> y;
    int szx = x.size(), szy = y.size();
    x = ' ' + x;
    y = ' ' + y;

    for (int i = 1; i <= szx; ++i)
        for (int j = 1; j <= szy; ++j)
        {
            if (x[i] != y[j])
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            else
                f[i][j] = f[i - 1][j - 1] + 1;
        }

    cout << f[szx][szy];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("QBSTR.INP", "r"))
    {
        freopen("QBSTR.INP", "r", stdin);
        freopen("QBSTR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}