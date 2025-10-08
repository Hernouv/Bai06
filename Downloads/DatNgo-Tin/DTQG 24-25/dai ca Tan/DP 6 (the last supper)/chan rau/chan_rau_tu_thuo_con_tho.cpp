#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INFLL LLONG_MAX

vector<vector<ll>> dp1, dp2, DP;
vector<int> a;
int n, k;
ll ans = INFLL;

void solve(int l, int r, int lo, int ro, int q)
{
    if (r < l)
        return;
    int m = (l + r) / 2;
    ll bm = INFLL;
    int bi;
    for (int i = max(lo, m); i <= ro; i++)
    {
        if (DP[i + 1][q - 1] != INFLL)
        {
            if (DP[i + 1][q - 1] + dp2[i][m] < bm)
            {
                bm = DP[i + 1][q - 1] + dp2[i][m];
                bi = i;
            }
        }
    }
    DP[m][q] = bm;
    if (m == 0)
        ans = min(ans, bm);
    solve(l, m - 1, lo, bi, q);
    solve(m + 1, r, bi, ro, q);
}

int32_t main()
{
    cin >> n >> k;
    k++;

    dp1.resize(n + 2, vector<ll>(n + 2));
    dp2.resize(n + 2, vector<ll>(n + 2));
    DP.resize(n + 2, vector<ll>(n + 2));
    a.resize(n + 2);

    for (int i = 0; i < n; i++)
    {
        DP[i][0] = INFLL;
    }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp1[i][j] = dp1[i][j - 1] + (a[i] ^ a[j]);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dp2[i][j] = dp2[i][j + 1] + dp1[j][i];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        solve(0, n - 1, 0, n - 1, i);
    }

    cout << ans;
    return 0;
}
