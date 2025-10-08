#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 5;
struct node
{
    long long x, y;
} a[nmax];

long long f[nmax];
int q[nmax];

bool cmp(const node &a, const node &b)
{
    return a.x > b.x or (a.x == b.x and a.y > b.y);
}

double slope(int x, int y)
{
    return double(f[x] - f[y]) / (a[y + 1].x - a[x + 1].x);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("KHOBAU.INP", "r"))
    {
        freopen("KHOBAU.INP", "r", stdin);
        freopen("KHOBAU.OUT", "w", stdout);
    }

    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        if (a[cnt].y < a[i].y)
            a[++cnt] = a[i];

    int l = 0, r = 0;
    for (int i = 1; i <= cnt; i++)
    {
        while (l < r and slope(q[l], q[l + 1]) <= a[i].y)
            l++;
        f[i] = f[q[l]] + a[q[l] + 1].x * a[i].y;
        while (l < r and slope(q[r - 1], q[r]) >= slope(q[r], i))
            r--;
        q[++r] = i;
    }
    cout << f[cnt];
    return 0;
}