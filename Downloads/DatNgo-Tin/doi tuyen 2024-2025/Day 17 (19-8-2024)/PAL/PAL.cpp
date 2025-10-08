#include <bits/stdc++.h>
using namespace std;

const int nmax = 210;
const int mod = 1e9 + 7;

string inp;
int f[nmax][nmax];

void not_main()
{
    cin >> inp;
    int sz = inp.size();
    inp = ' ' + inp;

    for (int i = 1; i <= sz; ++i)
        f[i][i] = 1;
    for (int i = sz - 1; i >= 1; --i)
        for (int j = i + 1; j <= sz; ++j)
        {
            if (inp[i] == inp[j])
                f[i][j] = (f[i + 1][j] + f[i][j - 1] + 1) % mod;
            else
                f[i][j] = (f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1]) % mod;
        }
    cout << f[1][sz];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PAL.INP", "r"))
    {
        freopen("PAL.INP", "r", stdin);
        freopen("PAL.OUT", "w", stdout);
    }
    not_main();
    return 0;
}