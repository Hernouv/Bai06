#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 7e3 + 10;

int n;
long long res;
int pos[nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pos[i];
    sort(pos + 1, pos + n + 1);

    long long z_iter_min, z_iter_max;
    for (long long x_iter = 1; x_iter < n - 1; ++x_iter)
    {
        z_iter_min = 0, z_iter_max = 0;
        for (long long y_iter = x_iter + 1; y_iter < n; ++y_iter)
        {
            while (pos[z_iter_min] - pos[y_iter] < pos[y_iter] - pos[x_iter] and z_iter_min <= n)
                ++z_iter_min;
            while (pos[z_iter_max] - pos[y_iter] <= 2 * (pos[y_iter] - pos[x_iter]) and z_iter_max <= n)
                ++z_iter_max;

            res += (z_iter_max - z_iter_min);
        }
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RUNNING.INP", "r"))
    {
        freopen("RUNNING.INP", "r", stdin);
        freopen("RUNNING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}