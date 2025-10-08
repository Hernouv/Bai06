#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

const int maxk = (int)2e4 + 100;
int dp[2][maxk];
const int mid = maxk / 2;
const int maxn = (int)1e3 + 100;
int a[maxn];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int t = 0, nt = 1;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        add(ans, dp[t][mid]);
        if (i == n)
            break;
        dp[t][mid]++;
        memset(dp[nt], 0, sizeof dp[nt]);

        for (int j = 0; j < maxk; j++)
        {
            int cur = dp[t][j];
            if (cur == 0)
                continue;
            add(dp[nt][j + a[i]], cur);
            add(dp[nt][j - a[i]], cur);
        }
        swap(t, nt);
    }
    cout << ans;
    return 0;
}