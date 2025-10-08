#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define int long long

const int nmax = 1e4 + 10;
int n;
int a[8][nmax], dp[256][nmax], res = -1e9;
vector<int> valid;

void initialize(int base, int L)
{
    int new_base = base + (1 << L);
    valid.push_back(new_base);

    if (L > 5)
        return;
    for (int i = L + 2; i < 8; ++i)
        initialize(new_base, i);
}

void not_main()
{
    valid.push_back(0);
    for (int i = 0; i < 8; ++i)
        initialize(0, i);

    cin >> n;
    for (int j = 0; j < 8; ++j)
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[j][i];
            maximize(res, a[j][i]);
        }
    if (res <= 0)
    {
        cout << res;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int x1 : valid)
        {
            int t_sum = 0;
            for (int it = 0; it < 8; ++it)
                if ((x1 >> it) & 1)
                    t_sum += a[it][i];

            for (int x2 : valid)
                if (!(x2 & x1))
                    maximize(dp[x1][i], dp[x2][i - 1] + t_sum);
        }
    }

    for (int x : valid)
        maximize(res, dp[x][n]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}