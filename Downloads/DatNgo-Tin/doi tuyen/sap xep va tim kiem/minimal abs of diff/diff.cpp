#include <bits/stdc++.h>
using namespace std;

long long arr[100010];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("diff.inp", "r", stdin);
    // freopen("diff.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    long long res = pow(10, 18) + 100;
    for (int i = 2; i <= n; ++i)
        res = min(res, abs(arr[i] - arr[i - 1]));
    cout << res;
    return 0;
}