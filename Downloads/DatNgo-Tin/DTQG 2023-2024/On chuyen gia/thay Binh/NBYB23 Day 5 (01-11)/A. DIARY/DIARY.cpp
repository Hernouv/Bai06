#include <bits/stdc++.h>
using namespace std;

int n;
int diary[110], g[110];
int ans[110], dp[110][110];

int cost(int l, int r)
{
    int ans = 0;
    for (int i = l + 1; i < r; ++i)
        if (diary[i] != i - l)
            ++ans;

    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DIARY.INP", "r"))
    {
        freopen("DIARY.INP", "r", stdin);
        freopen("DIARY.OUT", "w", stdout);
    }
    memset(ans, 0x3f, sizeof ans);
    memset(dp, 0x3f, sizeof dp);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> diary[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
            if (diary[j] != j - i + 1)
                ++g[i];
    }

    diary[0] = 0;
    dp[1][1] = (diary[1] != 0);
    ans[1] = min(ans[1], dp[1][1] + g[2]);
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            int c = cost(j, i) + (diary[i] != 0);
            for (int k = 0; k <= j; ++k)
            {
                dp[i][k + 1] = min(dp[i][k + 1], dp[j][k] + c);
                ans[k + 1] = min(ans[k + 1], dp[i][k + 1] + g[i + 1]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}