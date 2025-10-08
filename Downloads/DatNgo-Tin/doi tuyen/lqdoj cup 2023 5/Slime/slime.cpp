#include <bits/stdc++.h>
using namespace std;

int element_cnt[5010];
int n, s, arr[200010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("slime.inp", "r", stdin);
    freopen("slime.out", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        element_cnt[arr[i]]++;
    }
    sort(arr + 1, arr + n + 1, greater<int>());
    if (s % 2)
        cout << 0;
    else
    {
        bool sub3 = true;
        for (int i = 1; i < n; ++i)
            if (arr[i] != arr[i - 1])
            {
                sub3 = false;
                break;
            }
        if (sub3)
        {
            int t = s / arr[1];
            while (t > 1)
            {
                if (t % 2)
                    break;
                t /= 2;
            }
            if (t != 1)
            {
                cout << 0;
            }
        }
    }
    return 0;
}