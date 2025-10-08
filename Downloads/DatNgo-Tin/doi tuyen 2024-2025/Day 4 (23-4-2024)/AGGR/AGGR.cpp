#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;

int n, c, res;
int x[nmax];

bool check(int m)
{
    int prev = (int)-1e9;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (x[i] - m >= prev)
            ++cnt, prev = x[i];
    return (cnt >= c ? true : false);
}

void not_main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    sort(x + 1, x + n + 1);

    if (c == 2)
    {
        cout << x[n] - x[1];
        return;
    }

    if (c == 3)
    {
        int res = 0;
        for (int i = 2; i < n; ++i)
        {
            int t = min(x[i] - x[1], x[n] - x[i]);
            maximize(res, t);
        }
        cout << res;
        return;
    }

    int l = 1, r = (int)1e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("AGGR.INP", "r"))
    {
        freopen("AGGR.INP", "r", stdin);
        freopen("AGGR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}