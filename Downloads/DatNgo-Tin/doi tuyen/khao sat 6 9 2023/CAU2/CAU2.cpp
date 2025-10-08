#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int compress[1001][1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];
    if (k == 1)
    {
        int res = -1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                res = max(res, arr[i][j]);
        cout << res;
    }
    else if (k == n)
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                res += arr[i][j];
        cout << res;
    }
    else
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int i = 1; i <= k; ++i)
                compress[1][j] += arr[i][j];
            for (int i = k + 1; i <= n; ++i)
                compress[i - k + 1][j] = compress[i - k][j] - arr[i - k][j] + arr[i][j];
        }
        int res = -1;
        for (int i = 1; i <= n - k + 1; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= k; ++j)
                sum += compress[i][j];
            res = max(res, sum);
            for (int j = k + 1; j <= n; ++j)
            {
                sum -= compress[i][j - k];
                sum += compress[i][j];
                res = max(res, sum);
            }
        }
        cout << res;
    }
    return 0;
}