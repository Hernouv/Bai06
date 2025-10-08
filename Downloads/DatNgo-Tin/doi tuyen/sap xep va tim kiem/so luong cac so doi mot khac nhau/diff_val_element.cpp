#include <bits/stdc++.h>
using namespace std;

int arr[100010], n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("diffVal.inp", "r", stdin);
    // freopen("diffVal.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    arr[0] = INT_MIN;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (arr[i] != arr[i - 1])
            res++;
    cout << res;
    return 0;
}