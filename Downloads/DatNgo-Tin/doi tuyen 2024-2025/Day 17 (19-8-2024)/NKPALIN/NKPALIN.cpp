#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e3 + 10;

string inp;
vector<char> res;
int f[nmax][nmax];

void proc_str(int l, int r, int L, int R)
{
    if (L > R)
        return;
    if (L == R)
    {
        res[L] = inp[l];
        return;
    }
    if (inp[l] == inp[r])
    {
        res[L] = res[R] = inp[l];
        proc_str(l + 1, r - 1, L + 1, R - 1);
    }
    else if (f[l][r] == f[l + 1][r])
        proc_str(l + 1, r, L, R);
    else if (f[l][r] == f[l][r - 1])
        proc_str(l, r - 1, L, R);
    return;
}

void not_main()
{
    cin >> inp;
    int sz = inp.size();
    inp = ' ' + inp;

    for (int i = sz; i >= 1; --i)
        for (int j = i; j <= sz; ++j)
        {
            if (i == j)
                f[i][j] = 1;
            else if (inp[i] == inp[j])
            {
                if (i + 1 == j)
                    f[i][j] = 2;
                else
                    f[i][j] = f[i + 1][j - 1] + 2;
            }
            else if (inp[i] != inp[j])
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        }
    res.resize(f[1][sz] + 1);
    proc_str(1, sz, 1, f[1][sz]);

    for (int i = 1; i < res.size(); ++i)
        cout << res[i];
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