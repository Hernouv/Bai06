#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second

const int nmax = 2e5 + 10;
int n, m, q;
ll w[nmax], ans[nmax];
bool erased[nmax];

struct edge
{
    int u, v;
};
vector<edge> edgelist;

struct query
{
    int type;
    int id;
    ll val_diff;
} queries[nmax];

struct node
{
    int id;
    ll sum_w;
    bool operator<(const node &other) const
    {
        if (sum_w == other.sum_w)
            return id < other.id;
        return (sum_w > other.sum_w);
    }
};
set<node> conn_compo;

int root[nmax], sz[nmax];

int find_root(int u)
{
    if (root[u] == u)
        return u;
    return (root[u] = find_root(root[u]));
}

void dsu(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return;

    conn_compo.erase(node{u, w[u]});
    conn_compo.erase(node{v, w[v]});

    if (sz[u] < sz[v])
        swap(u, v);
    root[v] = u;
    sz[u] += sz[v];
    w[u] += w[v];
    conn_compo.insert({u, w[u]});
}

void not_main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    edgelist.push_back({0, 0});
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edgelist.push_back({u, v});
    }

    char qtype;
    int qid;
    ll val;
    for (int i = 1; i <= q; ++i)
    {
        cin >> qtype >> qid;
        if (qtype == 'D')
        {
            erased[qid] = true;
            queries[i] = {1, qid, 0};
        }
        else
        {
            cin >> val;
            queries[i] = {2, qid, w[qid] - val};
            w[qid] = val;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        conn_compo.insert({i, w[i]});
    }

    for (int i = 1; i <= m; ++i)
    {
        if (!erased[i])
        {
            dsu(edgelist[i].u, edgelist[i].v);
        }
    }

    node tmp = *conn_compo.begin();
    ans[q] = tmp.sum_w;

    for (int i = q; i >= 2; --i)
    {
        if (queries[i].type == 1)
        {
            int t_id = queries[i].id;
            dsu(edgelist[t_id].u, edgelist[t_id].v);
        }
        else
        {
            int t_root = find_root(queries[i].id);
            conn_compo.erase({t_root, w[t_root]});
            w[t_root] += queries[i].val_diff;
            conn_compo.insert({t_root, w[t_root]});
        }
        node tmp = *conn_compo.begin();
        ans[i - 1] = tmp.sum_w;
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}