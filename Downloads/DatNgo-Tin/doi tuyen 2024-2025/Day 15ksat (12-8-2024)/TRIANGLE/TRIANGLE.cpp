#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e3 + 10;

int n;
ll a[nmax];
ll res = 0;

void not_main()
{
    cin >> n;
    ll t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t;
        a[i] = 1LL * t * t;
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j)
        {
            ll tmp_val = a[i] + a[j];
            int L = lower_bound(a + j + 1, a + n + 1, tmp_val) - a;
            int R = upper_bound(a + j + 1, a + n + 1, tmp_val) - a;
            res += (R - L);
            if (L == n + 1)
                break;
        }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRIANGLE.INP", "r"))
    {
        freopen("TRIANGLE.INP", "r", stdin);
        freopen("TRIANGLE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}