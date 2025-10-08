#include <bits/stdc++.h>
using namespace std;

const int cnst = 1e5;
const int nmax = 2e5 + 10;
int n, a[508], dp1[nmax], dp2[nmax], cnt = 0, dd1[nmax], dd2[nmax];

int main()
{
    freopen("BROCANDY.INP", "r", stdin);
    freopen("BROCANDY.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt += a[i];
    }

    memset(dd1, 0, sizeof(dd1));
    dd1[cnst] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 200000; j++)
        {
            if (!dd1[j])
                continue;
            int sum = j - cnst;
            int t = dp1[j];
            int inv_t = dp1[j] - sum;
            dd2[(t - (inv_t + a[i])) + cnst] = 1;
            dd2[((t + a[i]) - inv_t) + cnst] = 1;
            dd2[(t - inv_t) + cnst] = 1;
            dp2[(t - (inv_t + a[i])) + cnst] = max(dp2[(t - (inv_t + a[i])) + cnst], t);
            dp2[((t + a[i]) - inv_t) + cnst] = max(dp2[((t + a[i]) - inv_t) + cnst], t + a[i]);
            dp2[(t - inv_t) + cnst] = max(dp2[(t - inv_t) + cnst], t);
        }

        for (int j = 0; j <= 200000; j++)
        {
            dp1[j] = dp2[j];
            dp2[j] = 0;
            dd1[j] = dd2[j];
            dd2[j] = 0;
        }
    }

    cout << (cnt - dp1[cnst] * 2) + dp1[cnst];
    return 0;
}