#include <bits/stdc++.h>
using namespace std;

int arr[1010][1010];
int sumRow[1010], sumColumn[1010];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("MATRIX.INP", "r", stdin);
    // freopen("MATRIX.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    for (int i = 1; i <= n; ++i)
        sumRow[i] = sumColumn[i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            sumColumn[j] += arr[i][j];
            sumRow[i] += arr[i][j];
        }

    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (sumRow[i] == sumColumn[j])
                res++;

    cout << res;
    return 0;
}