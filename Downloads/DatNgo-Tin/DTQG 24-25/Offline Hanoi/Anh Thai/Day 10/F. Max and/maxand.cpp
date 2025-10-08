#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e6 + 5;

int n;
int a[nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());

    for (int i = 2; i <= n; ++i)
        a[i] = a[1] & a[i];

    sort(a + 2, a + n + 1, greater<int>());

    ll res = 0;
    ll tnum = (1 << 30) - 1;
    for (int i = 1; i <= n; ++i)
    {
        tnum &= a[i];
        res += tnum;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}