#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll x, ll y)
{
    while (x and y)
    {
        if (x > y)
            x %= y;
        else
            y %= x;
    }
    return max(x, y);
}

void not_main()
{
    ll n1, n2;
    cin >> n1 >> n2;
    cout << gcd(n1, n2);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CHIAQUA.INP","r"))
    {
        freopen("CHIAQUA.INP","r",stdin);
        freopen("CHIAQUA.OUT","w",stdout);
    }
    not_main();
    return 0;
}
