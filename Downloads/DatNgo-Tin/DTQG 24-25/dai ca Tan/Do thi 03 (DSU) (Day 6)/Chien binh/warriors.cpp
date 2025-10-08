#include <bits/stdc++.h>
using namespace std;

const int nmax = 3e6 + 5;

int n, m;
int root[nmax], f[nmax];

int find_root(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

void dsu(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return;

    if (u < v)
        swap(u, v);
    root[v] = u;
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n + 1; ++i)
        root[i] = i;

    int l, r, x;
    for (int i = 1; i <= m; ++i)
    {
        cin >> l >> r >> x;
        while (l <= r)
        {
            l = find_root(l);
            if (l > r)
                break;
            if (l != x)
            {
                f[l] = x;
                dsu(l, l + 1);
            }
            else
                ++l;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << f[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}