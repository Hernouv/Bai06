#include <bits/stdc++.h>
using namespace std;

const int maxval = 1e5 + 10;

bool dp[101][maxval + 1];
int n;
int x[101];

void not_main()
{
    memset(dp, false, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= maxval; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            int prev_val = j - x[i];
            if (j >= x[i])
                if (dp[i - 1][prev_val])
                    dp[i][j] = true;
        }

    vector<int> possible_val;
    for (int i = 1; i <= maxval; ++i)
        if (dp[n][i] == true)
            possible_val.push_back(i);

    cout << possible_val.size() << '\n';
    for (int x : possible_val)
        cout << x << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}