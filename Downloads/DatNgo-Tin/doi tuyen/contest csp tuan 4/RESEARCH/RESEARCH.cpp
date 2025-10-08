#include <bits/stdc++.h>
using namespace std;

int n, k;
long long h[2020];
set<int> proc_sub1;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("RESEARCH.INP", "r", stdin);
    freopen("RESEARCH.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    if (!k)
    {
        h[n + 1] = -1;
        long long res = 0;
        for (int i = 1; i <= n; ++i)
            proc_sub1.insert(h[i]);
        int prev_h = 0;
        for (auto x : proc_sub1)
        {
            int paint = 0;
            for (int i = 1; i <= n + 1; ++i)
            {
                if (h[i] >= x)
                    paint++;
                else
                {
                    if (paint)
                    {
                        res += x - prev_h;
                        paint = 0;
                    }
                }
            }
            prev_h = x;
        }
        cout << res;
    }
    else
    {
        h[n + 1] = 0x3f;
        bool sub2 = true;
        int cmp = h[1];
        for (int i = 2; i <= n; ++i)
        {
            if (h[i] < cmp)
            {
                sub2 = false;
                break;
            }
            cmp = h[i];
        }
        if (sub2)
            cout << h[n - k];
        else
        {
            if (n == k)
                cout << 1;
        }
    }
    return 0;
}