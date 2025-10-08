#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct DSU
{
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_set(int x)
    {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx != fy)
        {
            parent[fy] = fx;
        }
    }
};

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (auto &x : c)
        cin >> x;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.union_set(u, v);
    }

    unordered_set<int> components;
    for (int i = 1; i <= n; i++)
        components.insert(dsu.find_set(i));
    int k = components.size();
    if (2LL * (k - 1) > n)
    {
        cout << "-1";
        return;
    }

    sort(c.begin(), c.end());
    ll total = 0;
    for (int i = 0; i < 2 * (k - 1); i++)
        total += c[i];
    cout << total;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("bridge.inp", "r"))
    {
        freopen("bridge.inp", "r", stdin);
        freopen("bridge.out", "w", stdout);
    }
    not_main();
    return 0;
}
