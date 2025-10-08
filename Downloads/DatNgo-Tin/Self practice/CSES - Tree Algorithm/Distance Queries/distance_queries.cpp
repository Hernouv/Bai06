#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
vector<int> graph[nmax];
int h[nmax];
int ancestor[18][nmax];
int n, q;

void dfs(int u)
{
    for (int v : graph[u])
    {
        if (v != ancestor[0][u])
        {
            h[v] = h[u] + 1;
            ancestor[0][v] = u;
            for (int i = 1; (1 << i) <= n; ++i)
                ancestor[i][v] = ancestor[i - 1][ancestor[i - 1][v]];
            dfs(v);
        }
    }
}

int lca(int a, int b)
{
    if (h[a] != h[b])
    {
        if (h[a] < h[b])
            swap(a, b);
        int diff = h[a] - h[b];
        for (int i = 0; (1 << i) <= diff; ++i)
            if ((diff >> i) & 1)
                a = ancestor[i][a];
    }
    if (a == b)
        return a;
    int t = __lg(h[a]);
    for (int i = t; i >= 0; --i)
        if (ancestor[i][a] != ancestor[i][b])
        {
            a = ancestor[i][a];
            b = ancestor[i][b];
        }
    return ancestor[0][a];
}

void not_main()
{
    cin >> n >> q;
    int a, b;
    for (int i = 2; i <= n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        cout << h[a] + h[b] - 2 * h[lca(a, b)] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}