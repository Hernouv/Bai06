#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 5e4 + 10;

int n, q, x;
int a[nmax];
long long res;

void query_solve()
{
    res = 0;
    int t = n;
    for (int i = 1; i <= n; ++i)
    {
        if (x - a[i] <= a[i])
            break;
        while (a[i] + a[t] > x)
            --t;
        if (t > i)
            res += (t - i);
        else
            break;
    }
    cout << res;
    cout << '\n';
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> q;
    while (q--)
    {
        cin >> x;
        query_solve();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SUMLX.INP", "r"))
    {
        freopen("SUMLX.INP", "r", stdin);
        freopen("SUMLX.OUT", "w", stdout);
    }
    not_main();
    return 0;
}