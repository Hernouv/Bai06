#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;

const int nmax = 1e3 + 10;

int n, k;
ll arr[nmax][nmax], res = 0;
ll strip[nmax];

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            arr[j][i] += arr[j - 1][i];

    for (int i = 1; i < k; ++i)
        for (int j = 1; j <= n; ++j)
            strip[j] += arr[j][i];

    for (int i = k; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            strip[j] += arr[j][i];
            strip[j] -= arr[j][i - 3];
        }

        for (int j = k; j <= n; ++j)
            maximize(res, strip[j] - strip[j - k]);
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BONUS.INP", "r"))
    {
        freopen("BONUS.INP", "r", stdin);
        freopen("BONUS.OUT", "w", stdout);
    }
    not_main();
    return 0;
}