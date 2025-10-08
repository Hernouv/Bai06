#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
ull n;
ull L[7], R[7], mul[7];
int t;

void preset()
{
    L[1] = 2, mul[1] = 1;
    for (int i = 2; i < 7; ++i)
    {
        L[i] = L[i - 1] * L[i - 1];
        R[i - 1] = L[i] - 1;
        mul[i] = i;
    }
    R[6] = (ull)1e18;
}

void not_main()
{
    cin >> t;
    preset();

    for (int i = 1; i <= t; ++i)
    {
        ull res = 0;
        cin >> n;
        for (int j = 1; j < 7; ++j)
        {
            if (n >= L[j])
            {
                ull Rt = min(R[j], n);
                ull length = Rt - L[j] + 1;
                res += (length * mul[j]);
            }
            else
                break;
        }
        cout << res << '\n';
    }
}

int32_t main()
{
    if (fopen("SUMCALC.INP", "r"))
    {
        freopen("SUMCALC.INP", "r", stdin);
        freopen("SUMCALC.OUT", "w", stdout);
    }
    not_main();
    return 0;
}