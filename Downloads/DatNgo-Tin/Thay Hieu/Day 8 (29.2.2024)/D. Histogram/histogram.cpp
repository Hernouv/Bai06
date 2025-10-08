#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

int dp[(1 << 16)][16];
long long ways[(1 << 16)][16];

void dp_reset()
{
    for (int i = 0; i < (1 << 16); ++i)
        for (int j = 0; j < 16; ++j)
            dp[i][j] = -1;

    for (int i = 0; i < 16; ++i)
        ways[(1 << i)][i] = 1;
}

void initialize(vector<int> &a, vector<int> &b, int mask, int q)
{
    for (int i = 0; i < q; ++i)
    {
        if ((mask >> i) & 1)
            a.push_back(i);
        else
            b.push_back(i);
    }
}

void not_main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            return;
        dp_reset();

        vector<int> h;
        int t;
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            h.push_back(t);
        }

        for (int i = 0; i < n; ++i)
        {
            dp[(1 << i)][i] = 2 * h[i] + 2;
        }

        for (int i = 0; i < (1 << n); ++i)
        {
            vector<int> added_column, unadded_column;
            initialize(added_column, unadded_column, i, n);
            for (int x : unadded_column)
                for (int y : added_column)
                {
                    int mask_added = i + (1 << x);
                    int c = dp[i][y] - h[y] + abs(h[x] - h[y]) + h[x] + 2;
                    if (maximize(dp[mask_added][x], c))
                        ways[mask_added][x] = ways[i][y];
                    else if (dp[mask_added][x] == c)
                        ways[mask_added][x] += ways[i][y];
                }
        }

        int res1 = 0;
        int all = (1 << n) - 1;
        for (int i = 0; i < n; ++i)
            maximize(res1, dp[all][i]);
        cout << res1 << ' ';

        int res2 = 0;
        int t1 = all, t2 = 0, cmp_ans = -1;
        while (t1)
        {
            int c = dp[all][t2];
            if (maximize(cmp_ans, c))
                res2 = ways[all][t2];
            else if (cmp_ans == c)
                res2 += ways[all][t2];
            t1 /= 2;
            ++t2;
        }

        cout << res2 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("histogram.inp", "r"))
    {
        freopen("histogram.inp", "r", stdin);
        freopen("histogram.out", "w", stdout);
    }
    not_main();
    return 0;
}