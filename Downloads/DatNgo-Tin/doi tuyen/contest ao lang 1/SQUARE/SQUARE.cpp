#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("SQUARE.INP", "r", stdin);
    freopen("SQUARE.OUT", "w", stdout);
    long long n, minx = 1e9 + 1, maxx = -1, miny = 1e9 + 1, maxy = -1;
    long long x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    long long res = max(maxx - minx, maxy - miny);
    cout << res * res;
    return 0;
}