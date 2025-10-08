#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
int num[nmax], vx[nmax], ia = 0;
int ances[20][nmax];
int h[nmax];
int n, q;
set<int> numlist;
bool chosen[nmax];

void dfs(int par, int u)
{
    num[u] = ++ia;
    vx[ia] = u;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        ances[0][v] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[i][v] = ances[i - 1][ances[i - 1][v]];
        dfs(u, v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] > h[v])
            swap(u, v);
        int diff = h[v] - h[u];
        for (int i = 0; (1 << i) <= diff; ++i)
        {
            if ((diff >> i) & 1)
                v = ances[i][v];
        }
    }
    if (u == v)
        return u;
    int t = __lg(h[u]);
    for (int i = t; i >= 0; --i)
        if (ances[i][u] != ances[i][v])
        {
            u = ances[i][u];
            v = ances[i][v];
        }
    return ances[0][v];
}

void not_main()
{
    cin >> n >> q;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    dfs(0, 1);
    memset(chosen, false, sizeof chosen);
    for (int i = 1; i <= q; ++i)
    {
        cin >> tv;
        if (!chosen[tv])
        {
            numlist.insert(num[tv]);
            chosen[tv] = true;
        }
        else
        {
            numlist.erase(num[tv]);
            chosen[tv] = false;
        }
        int start = *numlist.begin();
        int last = *numlist.rbegin();
        cout << lca(vx[start], vx[last]) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}