#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 5e5 + 10;
const ll inf = 2e9;

int n, k;
struct node
{
    ll h, s;
} mounts[nmax], f[nmax];

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> mounts[i].h >> mounts[i].s;
    f[1] = mounts[1];
    for (int i = 2; i <= n; ++i)
    {
        f[i] = {inf, inf};
        for (int j = max(0, i - k); j < i; ++j)
        {
            int H = max(f[j].h, mounts[i].h);
            int S = max(f[j].s, mounts[i].s);
            if (1LL * f[i].h * f[i].s > 1LL * H * S)
                f[i] = {H, S};
        }
    }
    ll res = 1LL * inf * inf;
    for (int i = max(1, n - k + 1); i <= n; ++i)
        res = min(res, 1LL * f[i].h * f[i].s);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mnjump.inp", "r"))
    {
        freopen("mnjump.inp", "r", stdin);
        freopen("mnjump.out", "w", stdout);
    }
    not_main();
    return 0;
}