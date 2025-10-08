#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int median(int a, int b, int c)
{
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
    return b;
}

int n;
int a[nmax], b[nmax], c[nmax], d[nmax];
int x[2 * nmax], y[2 * nmax];

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TIGERSUGAR.INP", "r"))
    {
        freopen("TIGERSUGAR.INP", "r", stdin);
        freopen("TIGERSUGAR.OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (a[i] > c[i])
            swap(a[i], c[i]);
        if (b[i] > d[i])
            swap(b[i], d[i]);
        x[2 * i] = a[i];
        y[2 * i] = b[i];
        x[2 * i + 1] = c[i];
        y[2 * i + 1] = d[i];
    }
    sort(x, x + 2 * n);
    sort(y, y + 2 * n);
    int ans_x = x[n], ans_y = y[n];
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans_x < a[i])
            ans += a[i] - ans_x;
        if (ans_y < b[i])
            ans += b[i] - ans_y;
        if (c[i] < ans_x)
            ans += ans_x - c[i];
        if (d[i] < ans_y)
            ans += ans_y - d[i];
    }

    cout << ans << '\n';
    cout << ans_x << ' ' << ans_y << '\n';
    for (int i = 0; i < n; ++i)
        cout << median(a[i], ans_x, c[i]) << ' ' << median(b[i], ans_y, d[i]) << '\n';
    return 0;
}
