#include <bits/stdc++.h>
using namespace std;

#define int long long

const int nmax = 1e2 + 5;
int s[nmax];

void not_main()
{
    int w, f, n;
    cin >> w >> f >> n;
    int sum_s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        sum_s += s[i];
    }
    vector<bool> dp(sum_s + 1);
    dp[0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int w = sum_s; w - s[i] >= 0; --w)
        {
            dp[w] = (dp[w] or dp[w - s[i]]);
        }
    }
    int ans = 2e9;
    for (int i = 0; i <= sum_s; ++i)
    {
        if (dp[i])
        {
            ans = min(ans, max((i + w - 1) / w, (sum_s - i + f - 1) / f));
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BOSS1.INP", "r"))
    {
        freopen("BOSS1.INP", "r", stdin);
        freopen("BOSS1.OUT", "w", stdout);
    }
    int test = 1;
    // cin >> test;
    while (test--)
        not_main();
    return 0;
}