#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int max_forward[100010];
int min_backward[100010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("maxsum.inp", "r", stdin);
    // freopen("maxsum.out", "w", stdout);
    int n;
    cin >> n;

    // self - made algo

    // arr[0] = 0;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cin >> arr[i];
    //     arr[i] += arr[i - 1];
    // }
    // min_backward[0] = 0;
    // for (int i = 1; i <= n; ++i)
    //     min_backward[i] = min(arr[i], min_backward[i - 1]);
    // max_forward[n] = arr[n];
    // for (int i = n - 1; i >= 0; --i)
    //     max_forward[i] = max(arr[i], max_forward[i + 1]);
    // int res = INT_MIN;
    // for (int i = 0; i <= n; ++i)
    //     res = max(res, max_forward[i] - min_backward[i]);
    // cout << res;

    // kadane
    int res = INT_MIN, temp = 0;
    int tl = 1, tr = 1, l = 1, r = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        temp += arr[i];
        tr = i;
        if (temp < arr[i])
        {
            temp = arr[i];
            tl = i;
        }
        if (temp > res)
        {
            res = temp;
            l = tl, r = tr;
        }
    }
    cout << res << '\n';
    cout << l << ' ' << r;
    return 0;
}