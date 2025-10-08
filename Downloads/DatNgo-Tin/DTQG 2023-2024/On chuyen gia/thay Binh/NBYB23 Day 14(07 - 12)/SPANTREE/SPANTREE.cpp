#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> edge(m);
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < m; i++)
    {
        auto &[u, v, l, r] = edge[i];
        cin >> u >> v >> l >> r;
        u--, v--, l--, r--;
        if (i >= n - 1)
            continue;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }
    vector<int> fa(n, -1), dep(n), id(n);
    vector par(__lg(n) + 1, vector<int>(n)), mx(par);
    {
        auto dfs = [&](auto self, int u) -> void
        {
            for (auto &[v, i] : G[u])
                if (v != fa[u])
                {
                    fa[v] = par[0][v] = u, dep[v] = dep[u] + 1;
                    mx[0][v] = get<2>(edge[id[v] = i]);
                    self(self, v);
                }
        };
        dfs(dfs, 0);
        for (int i = 1; i < par.size(); i++)
        {
            par[i] = par[i - 1];
            for (int j = 0; j < n; j++)
            {
                if (!~par[i][j])
                    continue;
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][par[i][j]]);
                par[i][j] = par[i - 1][par[i - 1][j]];
            }
        }
    }
    {
        vector<int> ord(m - n + 1);
        iota(ord.begin(), ord.end(), n - 1);
        sort(ord.begin(), ord.end(), [&](int i, int j)
             { return get<3>(edge[i]) < get<3>(edge[j]); });
        vector<int> repr(n);
        iota(repr.begin(), repr.end(), 0);
        auto find = [&](int x)
        {
            while (x != repr[x])
                x = repr[x] = repr[repr[x]];
            return x;
        };
        for (int i : ord)
        {
            auto [u, v, l, r] = edge[i];
            while (1)
            {
                u = find(u), v = find(v);
                if (u == v)
                    break;
                if (dep[u] < dep[v])
                    swap(u, v);
                auto &[u0, v0, _, r0] = edge[id[u]];
                r0 = min(r0, r - 1);
                repr[u] = fa[u];
            }
        }
    }
    {
        for (int i = n - 1; i < m; i++)
        {
            auto &[u, v, l, r] = edge[i];
            if (dep[u] < dep[v])
                swap(u, v);
            int l0 = -1;
            for (int d = dep[u] - dep[v], j; d; d ^= 1 << j)
            {
                j = __builtin_ctz(d);
                l0 = max(l0, mx[j][u]), u = par[j][u];
            }
            if (u != v)
            {
                for (int j = par.size() - 1; ~j; j--)
                {
                    if (par[j][u] == par[j][v])
                        continue;
                    l0 = max({l0, mx[j][u], mx[j][v]});
                    u = par[j][u], v = par[j][v];
                }
                l0 = max({l0, mx[0][u], mx[0][v]});
            }
            l = max(l, l0 + 1);
        }
    }
    vector<vector<pair<int, int>>> item(m);
    for (int i = 0; i < m; i++)
    {
        auto &[u, v, l, r] = edge[i];
        if (l >= m || r < 0)
        {
            cout << "NO\n";
            return;
        }
        item[l].emplace_back(r, i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    vector<int> res(m);
    for (int i = 0; i < m; i++)
    {
        for_each(item[i].begin(), item[i].end(), [&](const auto &x)
                 { Q.push(x); });
        if (Q.empty() or Q.top().first < i)
        {
            cout << "NO\n";
            return;
        }
        res[Q.top().second] = i, Q.pop();
    }
    cout << "YES\n";
    for (int x : res)
    {
        cout << x + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}