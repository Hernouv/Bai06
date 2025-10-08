#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 5e5 + 10;
int T, n;
ll a[nmax], ans[nmax];
int v[nmax];
bool erased[nmax];

ll res = 0;
int root[nmax], sz[nmax];
int find_root(int u)
{
    if (root[u] == u)
        return u;
    return (root[u] = find_root(root[u]));
}

void dsu(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    root[v] = u;
    sz[u] += sz[v];
    a[u] += a[v];
    res = max(res, a[u]);
}

void not_main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= T; ++i)
    {
        cin >> v[i];
        erased[v[i]] = true;
    }
    erased[0] = erased[n + 1] = true;

    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!erased[i])
        {
            res = max(res, a[i]);
            if (!erased[i + 1])
                dsu(i, i + 1);
        }
    }
    ans[T] = res;

    for (int i = T; i >= 2; --i)
    {
        erased[v[i]] = false;
        res = max(res, a[v[i]]);
        if (!erased[v[i] - 1])
            dsu(v[i] - 1, v[i]);
        if (!erased[v[i] + 1])
            dsu(v[i], v[i] + 1);
        ans[i - 1] = res;
    }

    for (int i = 1; i <= T; ++i)
        cout << ans[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}