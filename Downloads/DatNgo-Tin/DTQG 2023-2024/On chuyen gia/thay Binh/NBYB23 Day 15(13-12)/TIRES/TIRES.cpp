#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
int phi[nmax], a[nmax];
set<int> d;
int n;

void setPhi()
{
    for (int i = 1; i < nmax; ++i)
        phi[i] = i;
    for (int i = 1; i < nmax; ++i)
        for (int j = 2 * i; j < nmax; j += i)
            phi[j] -= phi[i];
}

void not_main()
{
    setPhi();
    cin >> n;
    ++n;
    int res = 0;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j * j <= a[i]; ++j)
            if (a[i] % j == 0)
            {
                d.insert(a[i] / j);
                d.insert(j);
            }

    for (int x : d)
        res += phi[x];
    cout << res - 1;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}