#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 5e5 + 10;

struct node
{
    int id, u, v, w;
};
vector<node> e;

struct node2
{
    int id, dest;
};
vector<node2> graph[nmax];

int n, m;
int root[nmax];
int sz[nmax];
bool chosen[nmax];

int t;
int low[nmax], num[nmax], ia = 0;
void dfs(int p, int u)
{
    num[u] = ++ia;
    low[u] = n + 1;

    for (node2 v : graph[u])
    {
        if (v.dest == p)
            continue;

        if (num[v.dest])
            minimize(low[u], num[v.dest]);
        else
        {
            dfs(u, v.dest);
            minimize(low[u], low[v.dest]);
        }
    }
}

int biconnID[nmax], ic = 0;

bool if_bridge(int u, int v)
{
    if (num[u] > num[v])
        swap(u, v);
    if (low[v] >= num[v])
        return true;
    return false;
}

void bicc_ia(int u)
{
    for (node2 v : graph[u])
    {
        if (biconnID[v.id])
            continue;
        if (!if_bridge(u, v.dest))
        {
            biconnID[v.id] = ic;
            bicc_ia(v.dest);
        }
        else
            biconnID[v.id] = -1;
    }
}

void setDefault()
{
    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

bool if_inMST(int u, int v)
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

void not_main()
{
    cin >> n >> m;
    int tu, tv, tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        e.push_back({i, tu, tv, tw});
        graph[tu].push_back({i, tv});
        graph[tv].push_back({i, tu});
    }
    dfs(0, 1);

    for (int i = 0; i < m; ++i)
    {
        if (biconnID[i])
            continue;

        if (!if_bridge(e[i].u, e[i].v))
        {
            biconnID[e[i].id] = ++ic;
            bicc_ia(e[i].u);
        }
        else
            biconnID[i] = -1;
    }

    sort(whole(e), [](node &a, node &b)
         { return a.w < b.w; });

    setDefault();
    for (int i = 0; i < m; ++i)
    {
        if (if_inMST(e[i].u, e[i].v))
            chosen[e[i].id] = true;
        else
        {
            int j = i - 1;
            while (j >= 0 and e[j].w == e[i].w)
            {
                if (biconnID[e[j].id] == biconnID[e[i].id])
                    chosen[e[j].id] = false;
                j--;
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        cout << (chosen[i] ? "Yes " : "No ");
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mst.inp", "r"))
    {
        freopen("mst.inp", "r", stdin);
        freopen("mst.out", "w", stdout);
    }
    int s;
    cin >> s;
    not_main();
    return 0;
}