#include <bits/stdc++.h>
using namespace std;

int a[1000001], n, k, minx = INT_MAX, maxx = 0;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
    }

    if (maxx - minx + 1 <= 2 * k)
    {
        for (int i = minx; i <= maxx)
    }
}
