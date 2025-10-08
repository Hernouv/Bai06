#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 2e5 + 10;

int n;
vector<ill> adj[nmax];

ll d[nmax];
int inDeg[nmax];
int parent[nmax];
struct node
{
    ll deep;
    ll deep2;
} maxdep[nmax];
int deepestV_st, deepestV_en;
vector<int> maxdiam_path;
vector<ll> edgew_diam;
ll maxd = 0;
bool chosen[nmax];

void dfs0(int par, int u)
{
    if (inDeg[u] == 1)
    {
        if (maximize(maxd, d[u]))
            deepestV_st = u;
    }

    for (ill v : adj[u])
    {
        if (v.fi == par)
            continue;
        d[v.fi] = d[u] + v.se;
        dfs0(u, v.fi);
    }
}

queue<int> vq;
void bfs1(int u)
{
    vq.push(u);
    while (!vq.empty())
    {
        int V = vq.front();
        vq.pop();
        for (ill v : adj[V])
        {
            if (parent[v.fi])
                continue;
            d[v.fi] = d[V] + v.se;
            parent[v.fi] = V;
            if (inDeg[v.fi] == 1 and d[v.fi] >= maxd)
                deepestV_en = v.fi;
            vq.push(v.fi);
        }
    }
}

void dfs2(int u)
{
    maxdep[u].deep = d[u];
    for (ill v : adj[u])
    {
        if (parent[v.fi] == u)
            continue;
        dfs2(v.fi);

        if (chosen[v.fi])
            continue;

        if (maxdep[u].deep < maxdep[v.fi].deep)
        {
            maxdep[u].deep2 = maxdep[u].deep;
            maxdep[u].deep = maxdep[v.fi].deep + v.se;
        }
        else
            maximize(maxdep[u].deep2, maxdep[v.fi].deep + v.se);
    }
}

ll res = 2e18;
ll diam_par[nmax], diam_child[nmax];

void not_main()
{
    cin >> n;
    int tu, tv;
    ll tw;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv >> tw;
        ++inDeg[tu];
        ++inDeg[tv];
        adj[tu].emplace_back(tv, tw);
        adj[tv].emplace_back(tu, tw);
    }

    if (n == 2)
    {
        cout << 0;
        exit(0);
    }

    dfs0(0, 1);
    parent[deepestV_st] = -1;
    d[deepestV_st] = 0;
    bfs1(deepestV_st);

    int t = deepestV_en;
    while (t != deepestV_st)
    {
        maxdiam_path.push_back(t);
        chosen[t] = true;
        edgew_diam.push_back(d[t] - d[parent[t]]);
        t = parent[t];
    }
    chosen[t] = true;
    maxdiam_path.push_back(t);
    int sz = maxdiam_path.size();

    for (int i = 0; i < sz; ++i)
        dfs2(deepestV_st);

    parent[deepestV_st] = 0;
    diam_par[deepestV_st] = maxdep[deepestV_st].deep + maxdep[deepestV_st].deep2;
    for (int i = sz - 2; i >= 0; --i)
    {
        int id = maxdiam_path[i];
        diam_par[id] = diam_par[parent[id]] + edgew_diam[i];

        ll e1 = maxdep[id].deep - d[id];
        if (e1 < 0)
            e1 = 0;
        ll e2 = maxdep[id].deep2 - d[id];
        if (e2 < 0)
            e2 = 0;
        maximize(diam_par[id], e1 + e2);
    }

    for (int i = 0; i < sz - 1; ++i)
    {
        int id = maxdiam_path[i];

        ll e1 = maxdep[id].deep - d[id];
        if (e1 < 0)
            e1 = 0;
        ll e2 = maxdep[id].deep2 - d[id];
        if (e2 < 0)
            e2 = 0;
        diam_child[id] = max(e1 + e2, e1 + d[deepestV_en] - d[id]);
    }

    for (int i = 0; i < sz - 1; ++i)
    {
        int id = maxdiam_path[i];
        cerr << 'p' << ' ' << parent[id] << ' ' << id << '\n';
        cerr << diam_par[parent[id]] << ' ' << diam_child[id] << '\n';
        minimize(res, max(diam_par[parent[id]], diam_child[id]));
        maximize(diam_child[parent[id]], diam_child[id]);
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DIAMETER.INP", "r"))
    {
        freopen("DIAMETER.INP", "r", stdin);
        freopen("DIAMETER.OUT", "w", stdout);
    }
    not_main();
    return 0;
}