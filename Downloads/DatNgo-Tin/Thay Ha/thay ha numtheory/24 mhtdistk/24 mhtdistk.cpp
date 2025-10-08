#include <bits/stdc++.h>
using namespace std;

int m, n, u, v, k;
int cnt = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mhtdistk.inp", "r"))
    {
        freopen("mhtdistk.inp", "r", stdin);
        freopen("mhtdistk.out", "w", stdout);
    }
    cin >> m >> n >> u >> v >> k;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int manhattan_dist = abs(i - u) + abs(j - v);
            if (manhattan_dist <= k and manhattan_dist > 0)
                cnt++;
        }
    cout << cnt;
    return 0;
}