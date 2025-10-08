#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU
{
    vector<int> lab;

    DSU(int _n) : lab(_n + 1)
    {
        for (int i = 1; i <= _n; i++)
            lab[i] = i;
    }

    int get_root(int u)
    {
        if (u == lab[u])
            return u;
        return lab[u] = get_root(lab[u]);
    }

    bool merge(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u == v)
            return false;

        lab[v] = u;

        return true;
    }

    bool same_component(int u, int v)
    {
        return get_root(u) == get_root(v);
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n);
    for (int i = 1; i <= m; i++)
    {
        for (int y = 1; y <= n; y++)
        {
            int x;
            cin >> x;
            dsu.merge(x, y);
        }
    }

    int u, v;
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        cout << (dsu.same_component(u, v) ? "YES" : "NO") << '\n';
    }
    return 0;
}