#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
const int outbound = 1e18 + 1;

int n, m, t, res = -1;
vector<ii> graph[200010];
int par[200010], d[200010], val[200010];

void dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii>> scanlist;
    d[1] = 0;
    scanlist.push({0, 1});
    while (!scanlist.empty())
    {
        ii top = scanlist.top();
        scanlist.pop();
        int len = top.first, u = top.second;
        if (len > d[u])
            continue;
        for (ii x : graph[u])
        {
            int v = x.first, w = x.second;
            if (d[v] > d[u] + w)
            {
                par[v] = u;
                d[v] = d[u] + w;
                scanlist.push({d[v], v});
            }
            else if (d[v] == d[u] + w)
                par[v] = min(par[v], u);
        }
    }
}

vector<int> a[200010];

void dfs(int u, int p)
{
    for (int v : a[u])
    {
        if (v != p)
        {
            dfs(v, u);
            val[u] += val[v];
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SHORTCUT.INP", "r"))
    {
        freopen("SHORTCUT.INP", "r", stdin);
        freopen("SHORTCUT.OUT", "w", stdout);
    }

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        d[i] = outbound;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    dijkstra();
    for (int u = 2; u <= n; u++)
    {
        a[u].push_back(par[u]);
        a[par[u]].push_back(u);
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++)
        res = max(res, (d[i] - t) * val[i]);
    cout << res;
    return 0;
}