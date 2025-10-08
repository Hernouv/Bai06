#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

struct node
{
    int st;
    int en;
    int w;
};
vector<node> edges;
vector<node> MaxST_edges;
vector<node> upgrade_needed;
vector<int> graph[nmax];

int n, m;
int parent[nmax];
int ancestor[18][nmax];
int sz[nmax];
int dist_source[nmax];

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

bool if_same_set(int u, int v)
{
    if (sz[u] < sz[v])
        swap(u, v);
    int par1 = find(u);
    int par2 = find(v);

    if (par1 != par2)
    {
        parent[v] = u;
        return false;
    }
    return true;
}

void create_graph()
{
    for (node e : MaxST_edges)
    {
        graph[e.st].push_back(e.en);
        graph[e.en].push_back(e.st);
    }
}

void dfs_MaxST(int par, int u)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
        }
    }
}

inline bool customOrder(node A, node B)
{
    return (A.w > B.w);
}

void setDefault()
{
    for (int i = 1; i <= n; ++i)
    {
        sz[i] = 1;
        parent[i] = i;
    }
}

void not_main()
{
    cin >> n >> m;
    setDefault();
    int a, b, c;
    for (int i = 1; i = m; ++i)
    {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), customOrder);

    for (node x : edges)
    {
        if (!if_same_set(x.st, x.en))
            MaxST_edges.push_back(x);
        else
            upgrade_needed.push_back(x);
    }

    create_graph();
    dfs_MaxST(-1, edges[0].st);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("hn.inp", "r"))
    {
        freopen("hn.inp", "r", stdin);
        freopen("hn.out", "w", stdout);
    }
    not_main();
    return 0;
}