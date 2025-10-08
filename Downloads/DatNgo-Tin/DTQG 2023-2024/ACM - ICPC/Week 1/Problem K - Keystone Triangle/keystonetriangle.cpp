#include <bits/stdc++.h>
using namespace std;

int h[50010];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    int res = -1;
    for (int i = 1; i <= n; ++i)
    {
        int t = h[i];
        int l = 1, r = n;
        if (i - h[i] > 0)
            l += (i - h[i]);
        if (i + h[i] < n)
            r = i + h[i] - 1;

        for (int j = i - 1; j >= l; ++j)
            if (t > h[j] + i - j)
                t = h[j] + i - j;
        for (int j = i + 1; j <= r; ++j)
            if (t > h[j] + j - i)
                t = h[j] + j - i;
        // t = min(t, i, n - i + 1);
        if (t > i)
            t = i;
        if (t > n - i + 1)
            t = n - i + 1;
        if (res < t)
            res = t;
    }
    cout << res;
    return 0;
}