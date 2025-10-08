#include <bits/stdc++.h>
using namespace std;

int indiv_eff[1000010];
int pair_eff[1000010];
int dp[1000010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> indiv_eff[i];
    for (int i = 2; i <= n; ++i)
        cin >> pair_eff[i];
    dp[0] = 0;
    dp[1] = indiv_eff[1];
    dp[2] = min(dp[1] + indiv_eff[2], pair_eff[2]);
    for (int i = 3; i <= n; ++i)
        dp[i] = min(dp[i - 1] + indiv_eff[i], dp[i - 2] + pair_eff[i]);
    cout << dp[n];
    return 0;
}