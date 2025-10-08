#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim = 1e6 + 10;
const ll outbound = 1e18;
int n;
ll x[lim];
int ans[lim];

int binS_LR(int id, int i, int L, int R)
{
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if ()
    }
}

int binS_RL(int l int L, int R)
{
    while (L <= R)
    {
    }
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    x[0] = -outbound;
    x[n + 1] = outbound;
    ans[1] = n;
    ans[n] = 1;
    for (int i = 2; i < n; ++i)
    {
        // int id = i;
        int l = i - 1, r = i + 1;
        while (l >= 1 and r <= n)
        {
            if (x[r] - x[id] < x[id] - x[l])
            {
                int pon s = binS_LR(l, r, n);
                id = pos;
                r = pos + 1;
            }
            else
            {
                int pos = binS_RL(id, 1, l);
                id = pos;
                l = pos - 1;
            }
        }
        if (l == 0)
            ans[i] = n;
        else
            ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] - 1 << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}

// stack? direction reverse point optimized