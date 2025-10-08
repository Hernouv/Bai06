#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // fopen;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 2; i <= n; ++i)
        arr[i] += arr[i - 1];

    arr[0] = 0;
    int res = 1e6;
    int l = 1, r = 1;
    while (r <= n)
    {
        while (arr[r] - arr[l - 1] < k and r <= n)
            ++r;
        if (arr[r] - arr[l - 1] == k)
        {
            res = min(res, r - l + 1);
            ++l;
        }
        else if (arr[r] - arr[l - 1] > k)
        {
            while (arr[r] - arr[l - 1] > k)
                ++l;
            if (arr[r] - arr[l - 1] == k)
            {
                res = min(res, r - l + 1);
                ++l;
            }
        }
    }

    if (res == 1e6)
        cout << -1;
    else
        cout << res;
    return 0;
}