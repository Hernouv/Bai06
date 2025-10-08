#include <bits/stdc++.h>
using namespace std;

const int nmax = 510;

char a[nmax][nmax];
int val[nmax][nmax];
int cnt[5];
int n, m;

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= 5 * m + 1; ++i)
        for (int j = 1; j <= 5 * n + 1; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
                val[i][j] = 0;
            else if (a[i][j] == '*')
                val[i][j] = val[i - 1][j] + 1;
            else if (a[i][j] == '.')
                val[i][j] = val[i - 1][j];
        }

    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            ++cnt[val[5 * i][5 * j + 2]];

    for (int i = 0; i < 5; ++i)
        cout << cnt[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}