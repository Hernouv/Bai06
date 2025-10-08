#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (~0ull >> 1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int nmax = 2e5 + 10;
ll a[nmax << 2], b[nmax << 2], s[nmax << 2];
ll d[nmax], h[nmax];
int n, m;

struct node
{
    ll a, b, mx;
    node(ll a, ll b, ll mx) : a(a), b(b), mx(mx) {}
};
node null = node(-inf, -inf, 0);

void push_up(int rt)
{
    a[rt] = max(a[rt << 1], a[rt << 1 | 1]);
    b[rt] = max(b[rt << 1], b[rt << 1 | 1]);
    s[rt] = max(a[rt << 1] + b[rt << 1 | 1], max(s[rt << 1], s[rt << 1 | 1]));
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        a[rt] = 2 * h[l] - d[l - 1];
        b[rt] = 2 * h[l] + d[l - 1];
        s[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void _merge(node x, node y, node &z)
{
    z.mx = max(x.mx, y.mx);
    z.a = max(x.a, y.a);
    z.b = max(x.b, y.b);
    z.mx = max(z.mx, x.a + y.b);
}

node query(int L, int R, int l, int r, int rt)
{
    if (L <= l and r <= R)
    {
        node x = node(a[rt], b[rt], s[rt]);
        return x;
    }
    int m = (l + r) >> 1;
    node lx = null, ry = null, res = null;
    if (L <= m)
        lx = query(L, R, lson);
    if (m < R)
        ry = query(L, R, rson);
    if (lx.a == -inf)
    {
        res.a = max(res.a, ry.a);
        res.b = max(res.b, ry.b);
        res.mx = max(res.mx, ry.mx);
    }
    else if (ry.a == -inf)
    {
        res.a = max(res.a, lx.a);
        res.b = max(res.b, lx.b);
        res.mx = max(res.mx, lx.mx);
    }
    else
        _merge(lx, ry, res);
    return res;
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
    {
        d[i + n] = d[i];
        h[i + n] = h[i];
    }
    for (int i = 1; i <= (n << 1); ++i)
        d[i] = d[i - 1] + d[i];
    build(1, n << 1, 1);
    int x, y;
    ll A, B;
    while (m--)
    {
        cin >> x >> y;
        if (x <= y)
            cout << query(y + 1, x + n - 1, 1, n << 1, 1).mx << '\n';
        else
            cout << query(y + 1, x - 1, 1, n << 1, 1).mx << '\n';
    }
    return 0;
}