#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 5;
const int outbound = 2e9 + 3;
int n, m;

vector<int> graph[nmax];
int low[nmax], num[nmax], ia = 0;
int conn_ed[nmax];
int connID[nmax], id;

stack<int> conn;
void dfs(int u)
{
    low[u] = num[u] = ++ia;
    conn_ed[u] = 1;
    conn.push(u);

    for (int v : graph[u])
    {
        if (conn_ed[v] == 1)
            low[u] = min(low[u], num[v]);
        else if (!conn_ed[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == num[u])
    {
        int t;
        ++id;
        do
        {
            t = conn.top();
            conn.pop();
            connID[t] = id;
            conn_ed[t] = 2;
        } while (t != u);
    }
}

bool degIn[nmax];
int res = 0;

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
        if (!conn_ed[i])
            dfs(i);

    for (int i = 1; i <= n; ++i)
    {
        for (int v : graph[i])
        {
            int a = connID[i], b = connID[v];
            if (a != b)
                degIn[b] = true;
        }
    }

    for (int i = 1; i <= id; ++i)
        res += (!degIn[i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("HELI.INP", "r"))
    {
        freopen("HELI.INP", "r", stdin);
        freopen("HELI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}