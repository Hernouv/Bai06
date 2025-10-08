#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int nmax = 1e6 + 10;

ll a, b, c;

ll calc(ll num)
{
    if (num == 0)
        return 0;
    ll rem = num % 9;
    return (num / 9) + (rem == c);
}

void not_main()
{
    cin >> a >> b >> c;
    if (a == 0 and c == 0)
    {
        cout << 1;
        return;
    }
    cout << calc(b) - calc(a - 1);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TAOSO.INP","r"))
    {
        freopen("TAOSO.INP","r",stdin);
        freopen("TAOSO.OUT","w",stdout);
    }
    not_main();
    return 0;
}
