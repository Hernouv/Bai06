#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 1e4 + 10;

int test;
int tu, tv;
ll tw;
int p1, p2, k;
string rqtype;

int n;
vector<ill> graph[nmax];
int ances[16][nmax], h[nmax];
ll d[nmax];

void dfs(int par, int u)
{
    for (ill v : graph[u])
    {
        if (v.fi == par)
            continue;
        h[v.fi] = h[u] + 1;
        d[v.fi] = d[u] + v.se;
        ances[0][v.fi] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[i][v.fi] = ances[i - 1][ances[i - 1][v.fi]];
        dfs(u, v.fi);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] > h[v])
            swap(u, v);
        int diff = h[v] - h[u];
        for (int it = 0; (1 << it) <= diff; ++it)
            if ((diff >> it) & 1)
                v = ances[it][v];
    }
    if (u == v)
        return u;
    int t = __lg(h[u]);
    for (int i = t; i >= 0; --i)
    {
        if (ances[i][u] != ances[i][v])
        {
            u = ances[i][u];
            v = ances[i][v];
        }
    }
    return ances[0][u];
}

int binlift(int u, int lift)
{
    for (int i = 0; (1 << i) <= lift; ++i)
        if ((lift >> i) & 1)
            u = ances[i][u];
    return u;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        graph[i].clear();

    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].push_back({tv, tw});
        graph[tv].push_back({tu, tw});
    }

    dfs(0, 1);
    while (cin >> rqtype)
    {
        if (rqtype == "DONE")
            return;
        cin >> p1 >> p2;
        int common_par = lca(p1, p2);
        if (rqtype == "DIST")
        {
            cout << 1LL * d[p1] + d[p2] - 2 * d[common_par] << '\n';
            continue;
        }
        else
        {
            cin >> k;
            if (h[p1] - h[common_par] + 1 >= k)
                cout << binlift(p1, k - 1) << '\n';
            else
            {
                k -= (h[p1] - h[common_par] + 1);
                cout << binlift(p2, h[p2] - h[common_par] - k) << '\n';
            }
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> test;
    while (test--)
    {
        not_main();
        cout << '\n';
    }
    return 0;
}