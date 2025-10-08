#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[105];
ll memo_table[105][105][105];

ll dp(int i, int j, int k)
{
    if (i > j)
        return 0;
    if (memo_table[i][j][k] != -1)
        return memo_table[i][j][k];

    while (i < j and a[j] == a[j - 1])
    {
        j--;
        k++;
    }

    ll res = dp(i, j - 1, 0) + (k + 1) * (k + 1);

    for (int m = i; m < j; m++)
    {
        if (a[m] == a[j])
        {
            ll temp = dp(i, m, k + 1) + dp(m + 1, j - 1, 0);
            res = max(res, temp);
        }
    }

    return memo_table[i][j][k] = res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(memo_table, -1, sizeof(memo_table));
    cout << dp(0, n - 1, 0);
}
