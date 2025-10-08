#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull a[500001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        ull x, y;
        cin >> x >> y;
        y += x;
        ull lo = 1, hi = n;
        ull lolvl, hilvl, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (a[mid] > x) hi = mid - 1;
            else if (a[mid] < x) lo = mid + 1;
            else break;
        }
        lolvl = mid;
        if (a[mid] > x) lolvl--;
        lo = 1, hi = n;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (a[mid] > y) hi = mid - 1;
            else if (a[mid] < y) lo = mid + 1;
            else break;
        }
        hilvl = mid;
        if (a[mid] > y) hilvl--;
        cout << hilvl - lolvl << '\n';
    }
    return 0;
}
