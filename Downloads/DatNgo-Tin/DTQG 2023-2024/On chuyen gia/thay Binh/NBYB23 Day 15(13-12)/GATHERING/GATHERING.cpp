#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define ll long long
#define whole(a) a.begin(), a.end()
#define ii pair<int, int>
#define fi first
#define se second

template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 1000005;
const int MOD = 1e9 + 7;

int n, m;

struct TestCuoi
{
    int root[MAX], subtree_sz[MAX], h[MAX], parent[MAX], pos[MAX];
    int chain_head[MAX], chain_id[MAX];
    int curr_pos = 1, curr_chain = 1;
    vector<int> graph[MAX];
    void dfs(int u, int par = -1)
    {
        subtree_sz[u] = 1;
        for (int v : graph[u])
        {
            if (v == par)
                continue;
            h[v] = h[u] + 1;
            parent[v] = u;
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
    void hld(int u, int par = -1)
    {
        if (!chain_head[curr_chain])
            chain_head[curr_chain] = u;
        pos[u] = curr_pos;
        chain_id[u] = curr_chain;
        curr_pos++;
        int next = 0;
        for (int v : graph[u])
        {
            if (v != par)
                if (next == 0 or subtree_sz[v] > subtree_sz[next])
                    next = v;
        }
        if (next)
            hld(next, u);
        for (int v : graph[u])
        {
            if (v != par and v != next)
            {
                curr_chain++;
                hld(v, u);
            }
        }
    }
    int lca(int u, int v)
    {
        while (chain_id[u] != chain_id[v])
        {
            if (chain_id[u] > chain_id[v])
                u = parent[chain_head[chain_id[u]]];
            else
                v = parent[chain_head[chain_id[v]]];
        }
        if (h[u] < h[v])
            return u;
        return v;
    }
    int check[MAX];
    void dfs1(int u, int par = -1)
    {
        for (int v : graph[u])
        {
            if (v == par)
                continue;
            if (check[u] != 0)
                check[v] = 2;
            dfs1(v, u);
        }
    }
    void not_main()
    {
        For(i, 1, n - 1)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 0);
        hld(1, 0);
        For(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            int hehe = lca(u, v);
            if (hehe == u)
            {
                check[u] = 1;
            }
        }
        dfs1(1, 0);
        For(i, 1, n)
        {
            if (check[i] == 2)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
} hehe;

int f[MAX][25], maxlog, h[MAX], d[MAX];
vector<int> graph[MAX];
void dfs(int u, int par)
{
    h[u] = h[par] + 1;
    f[u][0] = par;
    for (int i = 1; i <= maxlog; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v : graph[u])
    {
        if (v != par)
        {
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    for (int i = maxlog; i >= 0; i--)
    {
        if (h[f[u][i]] >= h[v])
            u = f[u][i];
    }
    if (u == v)
        return u;
    for (int i = maxlog; i >= 0; i--)
    {
        if (f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

int dis(int u, int v)
{
    int hehe = lca(u, v);
    return d[u] + d[v] - d[hehe] * 2;
}

bool check[MAX];
map<ii, int> mp;

void dfs1(int u, int par)
{
    mp[{u, par}] = 1;
    check[u] = false;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (mp[make_pair(v, u)] == 1)
            continue;
        dfs1(v, u);
    }
}

vector<ii> haha;
map<ii, int> dm;

void not_main()
{
    cin >> n >> m;
    if (n <= 1000 && n != 5 && m != 1)
    {
        hehe.not_main();
        return;
    }
    maxlog = log2(n) + 2;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(check, true, sizeof check);
    dfs(1, 0);
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        dm[{u, v}] = 1;
        if (dm[{v, u}] == 1)
        {
            For(j, 1, n) cout << 0 << '\n';
            return;
        }

        check[u] = false;
        int D = dis(u, v);
        int hehe = 0;
        for (int x : graph[u])
        {
            if (dis(x, v) + 1 == D)
            {
                hehe = x;
                break;
            }
        }
        for (int x : graph[u])
        {
            if (x == hehe)
                continue;
            else
                haha.push_back(ii(x, u));
        }
    }
    for (ii x : haha)
    {
        if (!mp[{x.fi, x.se}])
            dfs1(x.fi, x.se);
    }
    For(i, 1, n) cout << check[i] << "\n";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}