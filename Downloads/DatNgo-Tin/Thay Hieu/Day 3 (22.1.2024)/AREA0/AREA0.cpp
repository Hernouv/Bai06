#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 410;

int m, n;
long long arr[nmax][nmax];
long long suffix_sum[nmax][nmax];
int res[nmax][nmax];

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            suffix_sum[i][j] = arr[i][j] + suffix_sum[i - 1][j] + suffix_sum[i][j - 1] - suffix_sum[i - 1][j - 1];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int v = n;
            for (int u = i; u <= m; ++u)
            {
                while (v >= j and suffix_sum[u][v] - suffix_sum[i - 1][v] - suffix_sum[u][j - 1] + suffix_sum[i - 1][j - 1] > 0)
                    --v;

                if (v >= j)
                    maximize(res[i][j], (u - i + 1) * (v - j + 1));
                else
                    break;
            }
        }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << res[i][j] << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("AREA0.INP", "r"))
    {
        freopen("AREA0.INP", "r", stdin);
        freopen("AREA0.OUT", "w", stdout);
    }
    not_main();
    return 0;
}