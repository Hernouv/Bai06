#include <bits/stdc++.h>
using namespace std;

int arr1[1001], arr2[1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PAFLOWER.INP", "r", stdin);
    freopen("PAFLOWER.OUT", "w", stdout);
    int a, b, n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr1[i] >> arr2[i];
    }
    sort(arr1 + 1, arr1 + n + 1);
    sort(arr2 + 1, arr2 + n + 1, greater<int>());
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (arr1[i] + arr2[i] != -2)
            res++;
    cout << res;
    return 0;
}