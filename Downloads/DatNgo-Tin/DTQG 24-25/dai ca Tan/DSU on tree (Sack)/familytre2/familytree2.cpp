#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool maximize(X &x, Y y) { return x < y ? x = y, 1 : 0; }

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 3e5 + 17;

unordered_map<string, int> graph[nmax];
int ans[nmax], n, sz[nmax], h[nmax], q;
string s[nmax];
bool mark[nmax];
vector<int> g[nmax];
vector<ii> qry[nmax];

void pre_dfs(int v = 0)
{
    sz[v] = 1;
    for (int u : g[v])
        h[u] = h[v] + 1, pre_dfs(u), sz[v] += sz[u];
}

void del(int v)
{
    auto it = graph[h[v]].find(s[v]);
    it->se--;
    if (!it->se)
        graph[h[v]].erase(it);
    for (int u : g[v])
        if (!mark[u])
            del(u);
}

void add(int v)
{
    graph[h[v]][s[v]]++;
    for (int u : g[v])
        if (!mark[u])
            add(u);
}

void dfs(int v = 0, bool keep = 0)
{
    int mx, bigChild = 0;
    for (int u : g[v])
        if (maximize(bigChild, sz[u]))
            mx = u;

    for (int u : g[v])
        if (u != mx)
            dfs(u, 1);

    if (bigChild)
        dfs(mx), mark[mx] = 1;

    add(v);
    for (ii q : qry[v])
        ans[q.se] = graph[h[v] + q.fi].size();

    if (bigChild)
        mark[mx] = 0;
    if (keep)
        del(v);
}

void not_main()
{
    cin >> n;
    for (int i = 1, p; i <= n; i++)
    {
        cin >> s[i] >> p;
        g[p].push_back(i);
    }

    cin >> q;
    for (int i = 0, v, k; i < q; i++)
    {
        cin >> v >> k;
        qry[v].push_back({k, i});
    }
    pre_dfs();
    dfs();

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}