#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int nmax = 1e3 + 5;
const int lim = 1e6;

ll res[4 * nmax * nmax];

int fgcd(int a, int b)
{
    while (a and b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return max(a, b);
}

void not_main()
{
    for (int x = 1; x < 1000; ++x)
    {
        for (int y = x; y <= 1000; ++y)
        {
            if (x * x + y * y > lim)
                break;
            if (fgcd(x, y) == 1)
            {
                int a = 2 * x * y;
                int b = y * y - x * x;
                int c = x * x + y * y;
                int p = a + b + c;
                res[p] = max(res[p], 1LL * (a * b) / 2);
            }
        }
    }

    for (int p = 12; p <= lim; ++p)
    {
        if (res[p] != 0)
            for (int k = 2; k * p <= lim; ++k)
                res[k * p] = max(res[k * p], 1LL * res[p] * k * k);
    }

    int T;
    cin >> T;
    int tnum;
    while (T--)
    {
        cin >> tnum;
        cout << res[tnum] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("LAKE.INP", "r"))
    {
        freopen("LAKE.INP", "r", stdin);
        freopen("LAKE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}