#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;

int n;
ll candy_no[52];
ll res = 1e18;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> candy_no[i];
    sort(candy_no + 1, candy_no + n + 1);
    for (int i = 2; i <= n; ++i)
        candy_no[i] += candy_no[i - 1];

    for (int i = 1; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            ll a = candy_no[i];
            ll b = candy_no[j] - candy_no[i];
            ll c = candy_no[n] - candy_no[j];
            res = min(max({abs(a - b), abs(b - c), abs(c - a)}), res);
        }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("candy.inp", "r"))
    {
        freopen("candy.inp", "r", stdin);
        freopen("candy.out", "w", stdout);
    }
    not_main();
    return 0;
}