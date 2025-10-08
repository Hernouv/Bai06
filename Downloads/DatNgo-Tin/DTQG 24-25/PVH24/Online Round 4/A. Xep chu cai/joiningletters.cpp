#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 15e4 + 10;

ll cntI[nmax], cntP[nmax], cntC[nmax];
string inp;

void not_main()
{
    ll res = 0;
    int sz = inp.length();
    inp = ' ' + inp;
    int cnt = 0;
    for (int i = 1; i <= sz; ++i)
    {
        cntI[i] = cntI[i - 1] + (inp[i] == 'I');
        cntP[i] = cntP[i - 1];
        cntC[i] = cntC[i - 1];
        if (inp[i] == 'P' and i > 2)
            cntP[i] += cntC[i - 2];
        else if (inp[i] == 'C' and i > 2)
        {
            ++cnt;
            cntC[i] += cntI[i - 2];
            if (cnt >= 2)
                res += cntP[i - 2];
        }
    }
    cout << res << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("joiningletters.inp", "r"))
    {
        freopen("joiningletters.inp", "r", stdin);
        freopen("joiningletters.out", "w", stdout);
    }
    while (cin >> inp)
    {
        if (inp[0] == '$')
            break;
        not_main();
    }
    return 0;
}