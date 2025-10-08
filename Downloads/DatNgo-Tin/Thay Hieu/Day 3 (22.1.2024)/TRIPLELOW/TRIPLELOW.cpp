#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;

int n, x;
int a[nmax];
long long res = 0;

void not_main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    int lim1 = n;
    for (int i = 1; i < n - 1; ++i)
    {
        while (a[i] + a[lim1] > x)
            --lim1;
        if (lim1 <= i)
            break;
        int lim2 = n;
        for (int j = i + 1; j <= lim1; ++j)
        {
            while (a[i] + a[j] + a[lim2] > x)
                --lim2;
            if (lim2 <= j)
                break;
            else
                res += (lim2 - j);
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRIPLELOW.INP", "r"))
    {
        freopen("TRIPLELOW.INP", "r", stdin);
        freopen("TRIPLELOW.OUT", "w", stdout);
    }
    not_main();
    return 0;
}