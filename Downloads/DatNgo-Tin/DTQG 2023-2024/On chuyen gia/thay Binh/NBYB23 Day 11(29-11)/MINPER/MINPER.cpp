#include <bits/stdc++.h>
using namespace std;

#define int long long

const int nmax = 1000005;
int bit[nmax];

void update(int pos, int val)
{
    while (pos < nmax)
    {
        bit[pos] += val;
        pos += (pos & -pos);
    }
}

int get(int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= (pos & -pos);
    }
    return ans;
}

int n, m;

void not_main()
{
    while (true)
    {
        cin >> n >> m;
        if (n == -1)
            return;
        if (n == 1 or m == 0)
        {
            for (int i = 1; i <= n; ++i)
                cout << i << " ";
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                int cnt = n - i;
                int xmin = max(1LL, m - (cnt * (cnt - 1) / 2) + 1);
                cout << xmin + get(xmin) << " ";
                update(xmin, 1);
                m -= (xmin - 1);
            }
            memset(bit, 0, sizeof bit);
        }
        cout << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}