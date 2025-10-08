#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
int h[nmax];
int ances[19][nmax];
int n, q;
int r, x, y;
int cpar;

void dfs(int par, int u)
{
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        ances[0][v] = u;
        h[v] = h[u] + 1;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[i][v] = ances[i - 1][ances[i - 1][v]];
        dfs(u, v);
    }
}

int lca(int a, int b)
{
    if (h[a] != h[b])
    {
        if (h[a] > h[b])
            swap(a, b);
        int d = h[b] - h[a];
        for (int i = 0; (1 << i) <= d; ++i)
            if ((d >> i) & 1)
                b = ances[i][b];
    }
    if (a == b)
        return a;

    int t = __lg(h[a]);
    for (int i = t; i >= 0; --i)
    {
        if (ances[i][a] != ances[i][b])
        {
            a = ances[i][a];
            b = ances[i][b];
        }
    }
    return ances[0][a];
}

void not_main()
{
    cin >> n;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    dfs(0, 1);

    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> r >> x >> y;
        if (h[x] > h[y])
            swap(x, y);

        cpar = lca(x, y);
        int rx = lca(r, x);
        int ry = lca(r, y);

        if ((rx == r and lca(r, cpar) == cpar) or (ry == r and lca(r, cpar) == cpar))
        {
            cout << r << '\n';
            continue;
        }
        if (lca(ry, cpar) == cpar and ry != cpar)
        {
            cout << ry << '\n';
            continue;
        }
        if (lca(rx, cpar) == cpar and rx != cpar)
        {
            cout << rx << '\n';
            continue;
        }
        cout << cpar << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}