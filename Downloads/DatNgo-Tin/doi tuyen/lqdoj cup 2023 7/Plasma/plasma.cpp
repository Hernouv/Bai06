#include <bits/stdc++.h>
using namespace std;

int t, n;
int arr[100010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PLASMA.INP", "r"))
    {
        freopen("PLASMA.INP", "r", stdin);
        freopen("PLASMA.OUT", "w", stdout);
    }
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int posiCnt = 0;
        int negaCnt = 0;
        bool res = false;
        cin >> n;
        for (int j = 1; j <= n; ++j)
        {
            cin >> arr[i];
            if (arr[i] < 0)
                ++negaCnt;
            else if (arr[i] > 0)
                ++posiCnt;
        }
        vector<int> test;
        for (int j = 0; j <= pow(2, n) - 1; ++j)
        {
            if ((posiCnt - __builtin_popcount(j)) % 2 == 0)
            {
                for (int t = 1; t <= n; ++t)
                    test.push_back(arr[t]);
                for (int k = 0; k < n; ++k)
                    if ((j >> k) & 1)
                        test[k] = -test[k];
                bool valid = true;
                sort(test.begin(), test.end());
                for (int k = 1; k < test.size(); ++k)
                    if (test[k] == test[k - 1])
                    {
                        valid = false;
                        break;
                    }
                if (valid)
                {
                    res = true;
                    break;
                }
            }
        }
        if (res)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}