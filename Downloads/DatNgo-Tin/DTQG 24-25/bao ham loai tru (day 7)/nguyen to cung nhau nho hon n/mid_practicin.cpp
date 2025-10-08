#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;

int proc()
{
    int ret = 0;
    vector<int> divs;
    int dn = n;
    for (int i = 2; i * i <= dn; ++i)
    {
        if (dn % i == 0)
            divs.pb(i);
        while (dn % i == 0)
            dn /= i;
    }
    if (dn > 1)
        divs.pb(dn);

    int sz = divs.size();
    for (int msk = 1; msk < (1 << sz); ++msk)
    {
        int bitcnt = 0, mult = 1;
        for (int i = 0; i < sz; ++i)
            if ((msk >> i) & 1)
            {
                ++bitcnt;
                mult *= divs[i];
            }

        int tcnt = n / mult;
        if (bitcnt % 2 == 0)
            ret -= tcnt;
        else
            ret += tcnt;
    }
    return n - ret;
}

void not_main()
{
    cin >> n;
    cout << proc();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("IOI.INP", "r"))
    {
        freopen("IOI.INP", "r", stdin);
        freopen("IOI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}