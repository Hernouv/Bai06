#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;
int f[nmax][nmax];
string a, b;

void not_main()
{
    cin >> a >> b;
    int sz_a = a.size(), sz_b = b.size();
    a = ' ' + a;
    b = ' ' + b;

    for (int i = 0; i <= max(sz_a, sz_b); ++i)
        f[0][i] = f[i][0] = i;

    for (int i = 1; i <= sz_a; ++i)
        for (int j = 1; j <= sz_b; ++j)
        {
            if (a[i] != b[j])
            {
                if (i < j)
                    f[i][j] = f[i][i] + j - i;
                else if (i > j)
                    f[i][j] = f[i - 1][j] + 1;
                else if (i == j)
                    f[i][j] = f[i - 1][j - 1] + 1;
            }
            else if (a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1];
            }
        }
    cout << f[sz_a][sz_b];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STRING.INP", "r"))
    {
        freopen("STRING.INP", "r", stdin);
        freopen("STRING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}