#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    int posiCnt = 0, negaCnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            ++posiCnt;
        else
            ++negaCnt;
    }
    if (negaCnt == 0)
    {
        int res = 0, tmax = -1;
        for (int i = 1; i <= n; ++i)
        {
            res += arr[i];
            tmax = max(tmax, arr[i]);
        }
        cout << res - tmax;
    }
    else if (posiCnt <= 1)
    {
        cout << 0;
    }
    else
    {
        int res = 0;
        int t = 0, tmax = 0;
        for (int i = 1; i <= n; ++i)
        {
            t = max(t + arr[i], arr[i]);
            if (res < t)
            {
                res = t;
                tmax = max(tmax, arr[i]);
            }
        }
        cout << res - tmax;
    }
    return 0;
}