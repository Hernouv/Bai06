#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
int dp[1001][(1 << 10)];

void process_column(int column, int idx, int curr_mask, int next_mask)
{
    if (idx == n)
    {
        dp[column + 1][next_mask] = (dp[column + 1][next_mask] + dp[column][curr_mask]) % mod;
        return;
    }
    if ((curr_mask) & (1 << idx))
        process_column(column, idx + 1, curr_mask, next_mask);
    else
    {
        process_column(column, idx + 1, curr_mask, next_mask | (1 << idx));
        if (idx + 1 < n and !(curr_mask & (1 << (idx + 1))))
            process_column(column, idx + 2, curr_mask, next_mask);
    }
}

void not_main()
{
    cin >> n >> m;
    dp[0][0] = 1;
    for (int column = 0; column < m; ++column)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (dp[column][mask] > 0)
                process_column(column, 0, mask, 0);

    cout << dp[m][0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}