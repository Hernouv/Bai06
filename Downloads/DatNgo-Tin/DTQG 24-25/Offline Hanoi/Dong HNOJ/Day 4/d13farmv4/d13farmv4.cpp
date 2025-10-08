#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int N = 1e5 + 10;

int n, q;
int a[N];
ii que[N];
ll ans[N];

int p[N];
ll ev[N], od[N];
int last[N];
int Find(int u)
{
    if (u == p[u])
        return u;
    p[u] = Find(p[u]);
    return p[u];
}
ll res = 0;
int sz[N];
void Join(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (sz[v] % 2 == 0)
    {
        od[v] += od[u];
        ev[v] += ev[u];
        p[u] = v;
        sz[v] += sz[u];
    }
    else
    {
        res -= od[u];
        res += ev[u];
        od[v] += ev[u];
        ev[v] += od[u];
        sz[v] += sz[u];
        p[u] = v;
    }
}

struct edge
{
    int u, v, w;
} e[N];

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
    {
        e[i] = {i - 1, i, a[i] - a[i - 1]};
    }
    sort(e + 2, e + n + 1, [](edge a, edge b)
         { return a.w < b.w; });

    for (int i = 1; i <= n; ++i)
        p[i] = i, ev[i] = 0, od[i] = a[i], res += 1ll * a[i], sz[i] = 1;
    for (int i = 1; i <= q; ++i)
    {
        cin >> que[i].fi;
        que[i].se = i;
    }

    int j = 2;

    sort(que + 1, que + q + 1);

    for (int i = 1; i <= q; i++)
    {
        while (j <= n && e[j].w <= que[i].fi)
        {
            Join(e[j].u, e[j].v);
            j++;
        }
        ans[que[i].se] = res;
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
