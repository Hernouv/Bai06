#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e5 + 10;

struct node
{
    int l, r;
    ll x, y;
} query[nmax];

int n, m, q;
ll a[nmax];

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        node &t = query[i];
        cin >> t.l >> t.r >> t.x >> t.y;
    }
    cin >> q;
    int p, u, v;
    for (int i = 1; i <= q; ++i)
    {
        cin >> p >> u >> v;
        ll tmp = a[p];
        for (int j = u; j <= v; ++j)
        {
            if (p < query[j].l or query[j].r < p)
                continue;
            if (tmp == query[j].x)
                tmp += query[j].y;
        }
        cout << tmp << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("cquery.inp", "r"))
    {
        freopen("cquery.inp", "r", stdin);
        freopen("cquery.out", "w", stdout);
    }
    not_main();
}