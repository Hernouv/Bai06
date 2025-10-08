#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int nmax = 1e5 + 10;

int k, a[nmax], accum[nmax], n;
string s;

void not_main()
{
    cin >> k;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        a[i + 1] = s[i] - '0';

    for (int i = 1; i <= n; ++i)
        accum[i] = accum[i - 1] + a[i];

    ll res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tval = accum[i] + k - a[i];
        int p1 = lower_bound(accum + 1, accum + n + 1, tval) - accum;
        int p2 = upper_bound(accum + 1, accum + n + 1, tval) - accum - 1;
        if (accum[p1] == tval and accum[p2] == tval)
            res += 1LL * (p2 - p1 + 1);
        else
            break;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("NHIPHAN.INP","r"))
    {
        freopen("NHIPHAN.INP","r",stdin);
        freopen("NHIPHAN.OUT","w",stdout);
    }
    not_main();
    return 0;
}
