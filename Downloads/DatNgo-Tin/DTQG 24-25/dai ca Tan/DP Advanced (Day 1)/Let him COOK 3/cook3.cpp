#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int WE = 1e5 + 5;
int n, W;
int cnt[15][15];
int dp[WE];
vector<pair<int, int>> bags;

void not_main()
{
    cin >> n >> W;
    int tw, tv;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tw >> tv;
        cnt[tw][tv]++;
    }

    for (int i = 1; i <= 10; ++i)
        for (int j = 1; j <= 10; ++j)
        {
            if (cnt[i][j] == 0)
                continue;
            int tc = cnt[i][j];
            int temp = 1;
            int sum = 0;
            while (sum + temp <= tc)
            {
                bags.push_back({temp * i, temp * j});
                sum += temp;
                temp *= 2;
            }
            tc -= sum;
            if (tc > 0)
                bags.push_back({tc * i, tc * j});
        }

    for (pair<int, int> v : bags)
    {
        for (int j = W; j >= v.second; --j)
            dp[j] = max(dp[j], dp[j - v.second] + v.first);
    }
    cout << dp[W];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    not_main();
    return 0;
}
