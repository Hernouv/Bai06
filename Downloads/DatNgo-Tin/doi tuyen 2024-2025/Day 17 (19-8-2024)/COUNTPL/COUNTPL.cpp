#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;

string inp;
bool palin[nmax][nmax];
int f[nmax], sz;

void palin_proc()
{
    for (int i = 1; i <= sz; ++i)
        palin[i][i] = true;
    for (int i = 1; i < sz; ++i)
        if (inp[i] == inp[i + 1])
            palin[i][i + 1] = true;
    for (int len = 3; len <= sz; ++len)
        for (int i = 1; i + len - 1 <= sz; ++i)
            if (inp[i] == inp[i + len - 1])
                if (palin[i + 1][i + len - 2] == true)
                    palin[i][i + len - 1] = true;
}

void not_main()
{
    cin >> inp;
    sz = inp.size();
    inp = ' ' + inp;
    palin_proc();

    for (int i = 1; i <= sz; ++i)
    {
        f[i] = 1e9;
        for (int j = i; j >= 1; --j)
            if (palin[j][i] == true)
                f[i] = min(f[i], f[j - 1] + 1);
    }
    cout << f[sz];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("NKPALIN.INP", "r"))
    {
        freopen("NKPALIN.INP", "r", stdin);
        freopen("NKPALIN.OUT", "w", stdout);
    }
    not_main();
    return 0;
}