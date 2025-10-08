#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;
const ll outbound = 1e18;

int n, m, k, q;
vector<ill> graph[nmax];
bool chosen[nmax];
vector<int> chosen_list;

ll safety[nmax];
int d_par[nmax];

priority_queue<ill, vector<ill>, greater<ill>> pq;
void dijkstra()
{
    int n1 = n + 1;
    chosen[n1] = true;
    for (int i = 1; i <= n; ++i)
    {
        safety[i] = outbound;
    }
    for (int x : chosen_list)
    {
        graph[n1].emplace_back(x, 0);
        graph[x].emplace_back(n1, 0);
    }
    pq.emplace(n1, 0);

    while (!pq.empty())
    {
        ill V = pq.top();
        pq.pop();
        if (safety[V.fi] < V.se)
            continue;

        for (ill v : graph[V.fi])
        {
            if (v.fi == d_par[V.fi])
                continue;
            if (minimize(safety[v.fi], safety[V.fi] + v.se))
            {
                d_par[v.fi] = V.fi;
                pq.emplace(v.fi, safety[v.fi]);
            }
        }
    }
}

struct node
{
    int u, v;
    ll w;
};
vector<node> edgelist;

int parent[nmax];
void dfs_edgelist(int u)
{
    for (ill v : graph[u])
    {
        if (v.fi == parent[u])
            continue;
        edgelist.push_back({u, v.fi, min(safety[u], safety[v.fi])});
        if (!parent[v.fi])
        {
            parent[v.fi] = u;
            dfs_edgelist(v.fi);
        }
    }
}

int root[nmax];
int sz[nmax];
int find_root(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

bool conn(int u, int v)
{
    int ru = find_root(u);
    int rv = find_root(v);
    if (ru != rv)
    {
        if (sz[ru] < sz[rv])
            swap(ru, rv);
        root[rv] = ru;
        sz[ru] += sz[rv];
        return true;
    }
    return false;
}

vector<ill> gMST[nmax];
void mst_construct()
{
    sort(whole(edgelist), [](node &a, node &b)
         { return a.w > b.w; });

    for (int i = 1; i <= n + 1; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }

    for (node e : edgelist)
        if (conn(e.u, e.v))
        {
            gMST[e.u].emplace_back(e.v, e.w);
            gMST[e.v].emplace_back(e.u, e.w);
        }
}

int ancestor[18][nmax];
ll minSafety_onPath[18][nmax];
int h[nmax];
void dfs_ancestor(int u)
{
    for (ill v : gMST[u])
    {
        if (v.fi == ancestor[0][u])
            continue;
        ancestor[0][v.fi] = u;
        h[v.fi] = h[u] + 1;
        minSafety_onPath[0][v.fi] = v.se;
        for (int i = 1; (1 << i) <= n; ++i)
        {
            ancestor[i][v.fi] = ancestor[i - 1][ancestor[i - 1][v.fi]];
            minSafety_onPath[i][v.fi] = min(minSafety_onPath[i - 1][v.fi], minSafety_onPath[i - 1][ancestor[i - 1][v.fi]]);
        }
        dfs_ancestor(v.fi);
    }
}

ll query_proc(int u, int v)
{
    ll mu = safety[u], mv = safety[v];
    if (h[u] != h[v])
    {
        if (h[u] > h[v])
        {
            swap(u, v);
            swap(mu, mv);
        }
        int d = h[v] - h[u];
        for (int i = 0; (1 << i) <= d; ++i)
            if ((d >> i) & 1)
            {
                minimize(mv, minSafety_onPath[i][v]);
                v = ancestor[i][v];
            }
    }
    if (u == v)
        return min(mu, mv);

    int t = __lg(h[u]);
    for (int i = t; i >= 0; --i)
    {
        if (ancestor[i][u] != ancestor[i][v])
        {
            minimize(mu, minSafety_onPath[i][u]);
            minimize(mv, minSafety_onPath[i][v]);
            u = ancestor[i][u];
            v = ancestor[i][v];
        }
    }
    minimize(mu, minSafety_onPath[0][u]);
    minimize(mv, minSafety_onPath[0][v]);
    return min(mu, mv);
}

void not_main()
{
    cin >> n >> m >> k >> q;
    int tu, tv, tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].emplace_back(tv, tw);
        graph[tv].emplace_back(tu, tw);
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> tu;
        chosen[tu] = true;
        chosen_list.push_back(tu);
    }
    dijkstra();
    parent[1] = -1;
    dfs_edgelist(1);
    mst_construct();
    dfs_ancestor(1);

    for (int i = 1; i <= q; ++i)
    {
        cin >> tu >> tv;
        cout << query_proc(tu, tv) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("WALK.INP", "r"))
    {
        freopen("WALK.INP", "r", stdin);
        freopen("WALK.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
