#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, k;
int a[nmax];

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("financial.inp", "r"))
    {
        freopen("financial.inp", "r", stdin);
        freopen("financial.out", "w", stdout);
    }
    not_main();
    return 0;
}