#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 5e2 + 10;

int accum_sum[nmax];
int arr[nmax][nmax];
int d, res = 2e9;
int m, n, A, B;

void reset()
{
    for (int i = 1; i <= m; ++i)
        accum_sum[i] = 0;
}

bool special_case()
{
    if (res == d)
    {
        cout << d;
        return 1;
    }
    return 0;
}

void not_main()
{
    cin >> m >> n >> A >> B;
    if (A > B)
        swap(A, B);
    d = B - A;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }

    for (int i = 1; i <= n; ++i)
    {
        reset();
        for (int j = i; j <= n; ++j)
        {
            for (int t = 1; t <= m; ++t)
                accum_sum[t] += arr[t][j];

            for (int l = 1; l <= n; ++l)
                for (int r = l; r <= n; ++r)
                {
                    int c = accum_sum[r] - accum_sum[l - 1];
                    minimize(res, abs(c - A) + abs(c - B));
                    if (res == d)
                    {
                        cout << d;
                        return;
                    }
                }
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RMINDIST.INP", "r"))
    {
        freopen("RMINDIST.INP", "r", stdin);
        freopen("RMINDIST.OUT", "w", stdout);
    }
    not_main();
    return 0;
}