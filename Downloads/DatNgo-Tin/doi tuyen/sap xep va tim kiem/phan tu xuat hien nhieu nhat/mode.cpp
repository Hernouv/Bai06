#include <bits/stdc++.h>
using namespace std;

int arr[100010], n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("mode.inp", "r", stdin);
    // freopen("mode.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int res = 0, freq = 0;
    arr[0] = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == arr[i - 1])
            freq++;
        else
        {
            res = max(res, freq);
            freq = 1;
        }
    }
    cout << res;
    return 0;
}