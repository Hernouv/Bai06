#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int nmax = 2e5 + 10;

int n;
ll a[nmax];
ll rcnt[10];

void not_main()
{
    for (int i = 0; i <= 7; ++i)
        rcnt[i] = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        rcnt[a[i] % 7]++;
    }

    ll res = rcnt[0];
    for (int i = 1; i <= 3; ++i)
        res += min(rcnt[i], rcnt[7 - i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("THAYSO.INP","r"))
    {
        freopen("THAYSO.INP","r",stdin);
        freopen("THAYSO.OUT","w",stdout);
    }
    not_main();
    return 0;
}
