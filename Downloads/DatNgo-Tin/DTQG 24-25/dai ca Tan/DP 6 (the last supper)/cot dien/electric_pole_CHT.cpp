#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 5;
const int M = 1e3 + 5;
const ll inf = 2e18;

int n;
ll f[2][M], g[2][M], c;
int now, last;
ll h[N];

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    now = 0, last = 1;
    for (int i = 1; i <= n; i++)
    {
        now = 1 - now, last = 1 - last;
        ll temp = inf;
        for (int j = 1000; j >= h[i]; j--)
        {
            temp = min(temp + c, f[last][j]);
            f[now][j] = temp + 1LL * (j - h[i]) * (j - h[i]);
        }
        temp = inf;
        for (int j = 1; j <= 1000; j++)
        {
            temp = min(temp + c, f[last][j]);
            f[now][j] = min(f[now][j], temp + 1LL * (j - h[i]) * (j - h[i]));
            if (j < h[i])
                f[now][j] = inf;
        }
    }
    ll ans = inf;
    for (int i = 1; i <= 1000; i++)
        ans = min(ans, f[now][i]);
    cout << ans;
    return 0;
}