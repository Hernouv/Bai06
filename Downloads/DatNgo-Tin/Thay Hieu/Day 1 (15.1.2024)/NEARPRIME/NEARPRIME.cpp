#include <bits/stdc++.h>
using namespace std;

int n;
bool checkPrime(int inp)
{
    for (int i = 2; i * i <= n; ++i)
        if (inp % i == 0)
            return false;
    return true;
}

void not_main()
{
    cin >> n;
    while (!checkPrime(n))
        ++n;
    cout << n;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("NEARPRIME.INP", "r"))
    {
        freopen("NEARPRIME.INP", "r", stdin);
        freopen("NEARPRIME.OUT", "w", stdout);
    }
    not_main();
    return 0;
}