#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>

const int MAX = 1e5 + 10;

vector<int> adj[MAX];
int n, q, dep[MAX], T[MAX], P[MAX][30];

void DFS(int src, int par, int lev)
{
    dep[src] = lev;
    T[src] = par;

    for (int i = 0; i < adj[src].size(); i++)
    {
        int x = adj[src][i];

        if (x == par)
            continue;
        DFS(x, src, lev + 1);
    }
}
void initLCA()
{
    memset(P, -1, sizeof P);

    for (int i = 1; i <= n; i++)
        P[i][0] = T[i];
    for (int j = 1; 1 << j < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}
int lca_query(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);

    int log = log2(n);
    for (int i = log; i >= 0; i--)
    {
        if (dep[u] - (1 << i) >= dep[v])
            u = P[u][i];
    }
    if (u == v)
        return u;
    for (int i = log; i >= 0; i--)
    {
        if (P[u][i] != -1 && P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}
int dist(int u, int v)
{
    int lca = lca_query(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}

struct CentroidDecomposition
{
    int path[MAX], sub[MAX];
    bool vis[MAX];

    CentroidDecomposition()
    {
        memset(vis, 0, sizeof vis);
        memset(path, 0, sizeof path);
    }

    void subDFS(int src, int par)
    {
        sub[src] = 1;

        for (auto i : adj[src])
        {
            if (i == par || vis[i])
                continue;

            subDFS(i, src);
            sub[src] += sub[i];
        }
    }
    int centroid(int src, int par, int sz)
    {
        for (auto i : adj[src])
        {
            if (i == par || vis[i])
                continue;
            else if (sub[i] > sz)
                return centroid(i, src, sz);
        }
        return src;
    }
    void decompose(int src, int par)
    {
        subDFS(src, -1);
        int c = centroid(src, -1, sub[src] / 2);
        vis[c] = 1;
        path[c] = par;

        for (auto i : adj[c])
        {
            if (!vis[i])
                decompose(i, c);
        }
    }
} tree;

bool color[MAX];
multiset<int> node[MAX];

struct QueryHandler
{
    void update(int u)
    {
        color[u] ^= 1;
        int cur = u;

        while (cur != -1)
        {
            if (color[u])
                node[cur].insert(dist(u, cur));
            else
                node[cur].erase(node[cur].find(dist(u, cur)));

            cur = tree.path[cur];
        }
    }
    int query(int u)
    {
        int cur = u, ret = 1e9;

        while (cur != -1)
        {
            if (node[cur].size())
                ret = min(ret, *node[cur].begin() + dist(u, cur));

            cur = tree.path[cur];
        }
        if (ret == 1e9)
            ret = -1;
        return ret;
    }
} ds;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 1, 0);
    initLCA();

    tree.decompose(1, -1);

    for (int type, u; q--;)
    {
        cin >> type >> u;

        if (type == 1)
            ds.update(u);
        else
            cout << ds.query(u) << endl;
    }
}