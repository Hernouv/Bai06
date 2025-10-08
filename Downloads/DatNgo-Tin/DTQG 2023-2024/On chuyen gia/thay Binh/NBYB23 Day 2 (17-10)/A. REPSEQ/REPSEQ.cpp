#include <bits/stdc++.h>
using namespace std;

int arr[1010];
int n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    bool avail_sol = false;
    for (int i = 1; i <= n - k + 1; ++i)
    {
        if (avail_sol)
            break;

        for (int j = i; j <= n; ++j)
        {
            int sz = j - i + 1;
            if (i + (sz * k) - 1 > n)
                break;
            avail_sol = true;
            int lim = i + sz * (k - 1) - 1;
            for (int t = i; t <= lim; ++t)
            {
                if (arr[t] != arr[t + sz])
                {
                    avail_sol = false;
                    break;
                }
            }
            if (avail_sol)
            {
                cout << sz << '\n';
                for (int t = i; t < i + sz; ++t)
                    cout << arr[t] << ' ';
                break;
            }
        }
    }
    if (!avail_sol)
        cout << -1;
    return 0;
}