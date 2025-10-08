#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;

int m, n, k;
int x[nmax], y[nmax], s[nmax];

void not_main()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
        cin >> y[i];
    for (int i = 1; i <= k; ++i)
        cin >> s[i];
    sort(x + 1, x + m + 1);
    sort(y + 1, y + n + 1);

    for (int s_iter = 1; s_iter <= k; ++s_iter)
    {
        int res = 2e9 + 7;
        int y_iter = n;
        for (int x_iter = 1; x_iter <= m; ++x_iter)
        {
            while (y_iter > 1 and y[y_iter] > s[s_iter] - x[x_iter])
                --y_iter;
            minimize(res, abs(x[x_iter] + y[y_iter] - s[s_iter]));
            if (y_iter < n)
                minimize(res, abs(x[x_iter] + y[y_iter + 1] - s[s_iter]));
        }
        cout << res << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SEQGAME.INP", "r"))
    {
        freopen("SEQGAME.INP", "r", stdin);
        freopen("SEQGAME.INP", "w", stdout);
    }
    not_main();
    return 0;
}