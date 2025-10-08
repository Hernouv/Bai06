#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n, m;
vector<int> graph[nmax];
int low[nmax], num[nmax], ia = 0;
int parent[nmax];
vector<ii> res;

void dfs(int par, int u)
{
    num[u] = ++ia;
    low[u] = ia;
    parent[u] = par;

    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (!num[v])
        {
            dfs(u, v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
            dfs(0, i);
    }

    for (int i = 1; i <= n; ++i)
    {
        int p = i, pp = parent[p];
        if (pp and low[p] >= num[p])
        {
            pair<int, int> tmp = {p, pp};
            if (p > pp)
                swap(tmp.first, tmp.second);
            res.push_back(tmp);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (ii x : res)
        cout << x.fi << ' ' << x.se << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("IOI.INP", "r"))
    {
        freopen("IOI.INP", "r", stdin);
        freopen("IOI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}