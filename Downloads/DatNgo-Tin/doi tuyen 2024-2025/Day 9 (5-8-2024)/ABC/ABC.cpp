#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
const int nmax = 1e5 + 10;

struct EDGE
{
    int st, en;
};
vector<EDGE> edgelist;

stack<int> vlist;
int n, m, res = 0;
vector<int> graph[nmax];
vector<int> graph_scc[nmax];
bool inDeg[nmax], visit_scc[nmax];
int num[nmax], low[nmax], timer = 0;
int ccid[nmax], ccno = 0;

void dfs(int u)
{
    ++timer;
    num[u] = timer, low[u] = timer;
    vlist.push(u);

    for (int v : graph[u])
    {
        if (!ccid[v])
        {
            if (!num[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u])
    {
        ++ccno;
        int t;
        do
        {
            t = vlist.top();
            vlist.pop();
            ccid[t] = ccno;
        } while (t != u);
    }
}

void dfs_scc(int u)
{
    for (int v : graph_scc[u])
    {
        inDeg[v] = true;
        dfs_scc(v);
    }
}

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        edgelist.push_back({u, v});
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
            dfs(i);
    }

    for (EDGE e : edgelist)
    {
        if (ccid[e.st] != ccid[e.en])
            graph_scc[ccid[e.st]].push_back(ccid[e.en]);
    }

    for (int i = 1; i <= ccno; ++i)
        graph_scc[i].resize(unique(graph_scc[i].begin(), graph_scc[i].end()) - graph_scc[i].begin());

    for (int i = 1; i <= ccno; ++i)
        if (!inDeg[i])
            dfs_scc(i);

    for (int i = 1; i <= ccno; ++i)
        if (!inDeg[i])
            ++res;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ABC.INP", "r"))
    {
        freopen("ABC.INP", "r", stdin);
        freopen("ABC.OUT", "w", stdout);
    }
    not_main();
    return 0;
}