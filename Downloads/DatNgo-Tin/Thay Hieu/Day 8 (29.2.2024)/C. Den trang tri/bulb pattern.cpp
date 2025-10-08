#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int outbound = 1e9 + 7;

int n, m, res = outbound;
int diff[17][17];
int dp[(1 << 17)][17];
string pattern[17];

void set_Default()
{
    for (int i = 0; i < (1 << m); ++i)
        for (int j = 0; j < m; ++j)
            dp[i][j] = outbound;
}

int countBit_one(string inp, int id)
{
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (inp[i] == '1')
        {
            ++ret;
        }
    }
    return ret;
}

int cnt_diff(string a, string b)
{
    int ret = 0;
    for (int i = 0; i < n; ++i)
        ret += (a[i] != b[i]);
    return ret;
}

void insertVal(vector<int> &proc, int mask)
{
    for (int i = 0; i < n; ++i)
        if (!((mask >> i) & 1))
            proc.push_back(i);
}

void not_main()
{
    cin >> n >> m;
    set_Default();
    for (int i = 0; i < m; ++i)
        cin >> pattern[i];

    // for (int i = 0; i < m; ++i)
    //     cout << pattern[i] << '\n';
    // cout << '\n';

    for (int i = 0; i < m; ++i)
        dp[(1 << i)][i] = countBit_one(pattern[i], i);

    // for (int i = 0; i < m; ++i)
    //     cout << dp[(1 << i)][i] << '\n';
    // cout << '\n';

    for (int i = 0; i < m - 1; ++i)
        for (int j = i + 1; j < m; ++j)
        {
            int tmp = cnt_diff(pattern[i], pattern[j]);
            diff[i][j] = tmp;
            diff[j][i] = tmp;
        }

    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //         cout << diff[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 0; i < (1 << m); ++i)
    {
        // vector<int> untried_patterns;
        // insertVal(untried_patterns, i);

        for (int b = 0; b < m; ++b)
            if ((i >> b) & 1)
                for (int x = 0; x < m; ++x)
                    if (!((i >> x) & 1))
                        minimize(dp[i + (1 << x)][x], dp[i][b] + diff[b][x]);
    }

    int all = (1 << m) - 1;
    for (int i = 0; i < m; ++i)
        minimize(res, dp[all][i]);

    // cout << '\n';
    // for (int i = 0; i < (1 << m); ++i)
    // {
    //     cout << "mask-" << i << ": ";
    //     for (int j = 0; j < m; ++j)
    //         cout << (dp[i][j] == outbound ? 0 : dp[i][j]) << ' ';
    //     cout << '\n';
    // }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("bulb.inp", "r"))
    {
        freopen("bulb.inp", "r", stdin);
        freopen("bulb.out", "w", stdout);
    }
    not_main();
    return 0;
}