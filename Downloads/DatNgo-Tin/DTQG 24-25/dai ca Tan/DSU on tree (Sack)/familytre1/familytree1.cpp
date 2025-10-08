#include <bits/stdc++.h>
using namespace std;

#define whole(__) __.begin(), __.end()
template <class X, class Y>
inline bool maximize(X &x, Y &y) { return x < y ? x = y, 1 : 0; }

const int nmax = 1e5 + 5;

int n, q;
int ances[nmax][19];
vector<int> graph[nmax];
int h[nmax];
vector<int> hlist[nmax];
int tin[nmax], tout[nmax], now = 0;

void pre_dfs(int u)
{
    tin[u] = ++now;
    for (int i = 1; i < 19; ++i)
        ances[u][i] = ances[ances[u][i - 1]][i - 1];
    hlist[h[u]].push_back(tin[u]);
    for (int v : graph[u])
        h[v] = h[u] + 1, pre_dfs(v);
    tout[u] = now;
}

int par(int v, int dep)
{
    for (int i = 0; (1 << i) <= dep; ++i)
        if ((dep >> i) & 1)
            v = ances[v][i];
    return v;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ances[i][0];
        if (ances[i][0])
            graph[ances[i][0]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (!ances[i][0])
            pre_dfs(i);

    cin >> q;
    for (int i = 1, v, k; i <= q; ++i)
    {
        cin >> v >> k;
        int tmp = h[v];
        v = par(v, k);
        k = tmp;

        if (!v or !k)
        {
            cout << 0 << ' ';
            continue;
        }
        int p1 = lower_bound(whole(hlist[k]), tin[v] + 1) - hlist[k].begin();
        int p2 = upper_bound(whole(hlist[k]), tout[v]) - hlist[k].begin() - 1;
        int ans = p2 - p1 + 1;
        cout << (ans ? ans - 1 : 0) << ' ';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}