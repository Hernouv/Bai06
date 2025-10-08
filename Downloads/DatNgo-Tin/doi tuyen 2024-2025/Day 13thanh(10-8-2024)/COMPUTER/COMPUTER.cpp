#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3;
int b1, b2, b3;
int res = 0;

void not_main()
{
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;

    int t = min(a1, b1);
    res += t;
    a1 -= t, b1 -= t;
    t = min(a2, b2);
    res += t;
    a2 -= t, b2 -= t;
    t = min(a3, b1 + b2);
    res += t;
    a3 -= t;
    t = min(b3, a1 + a2 + a3);
    res += t;

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("COMPUTER.INP", "r"))
    {
        freopen("COMPUTER.INP", "r", stdin);
        freopen("COMPUTER.OUT", "w", stdout);
    }
    not_main();
    return 0;
}