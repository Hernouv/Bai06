/*
    Loli has hopium for VOI 2023.
    Brain stopped working at 15:10 05.12.2022.
*/
#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

#define ll long long
// #define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define fr first
#define sc second
#define fi(x, a, b) for (int x = (int)(a); (x) <= (int)(b); ++(x))
#define fd(x, a, b) for (int x = (int)(a); (x) >= (int)(b); --(x))
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

#define task "DISTK"
#define nmax 100007
const int mod = (int)1e9 + 7;

int n, m, k;
int res = 0;
vi g[nmax];
int par[nmax];
int Tsize, Subsize[nmax];
int h[nmax];
const int lgN = 17;
int RMQ[nmax][lgN + 1];
set<pii> st[nmax];

void dfs(int u)
{
    for (int v : g[u])
    {
        if (v != RMQ[u][0])
        {
            h[v] = h[u] + 1;
            RMQ[v][0] = u;
            fi(j, 1, lgN) RMQ[v][j] = RMQ[RMQ[v][j - 1]][j - 1];
            dfs(v);
        }
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    int delta = h[u] - h[v];
    fi(i, 0, lgN) if ((delta >> i) & 1) u = RMQ[u][i];
    if (u == v)
        return u;
    fd(i, lgN, 0)
    {
        if (RMQ[u][i] != RMQ[v][i])
        {
            u = RMQ[u][i];
            v = RMQ[v][i];
        }
    }
    return RMQ[u][0];
}

int dis(int u, int v)
{
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void DFS_size(int u, int p)
{
    ++Tsize;
    Subsize[u] = 1;
    for (int v : g[u])
        if (v != p && !par[v])
        {
            DFS_size(v, u);
            Subsize[u] += Subsize[v];
        }
}

int GetCentroid(int u, int p)
{
    for (int v : g[u])
        if (v != p && !par[v] && Subsize[v] * 2 > Tsize)
            return GetCentroid(v, u);
    return u;
}

void Decompose(int u, int p)
{
    Tsize = 0;
    DFS_size(u, 0);
    int Centroid = GetCentroid(u, 0);
    int sz = Subsize[Centroid];
    if (p == 0)
        par[Centroid] = Centroid;
    else
        par[Centroid] = p;
    for (int v : g[Centroid])
        if (!par[v])
            Decompose(v, Centroid);
}

bool state[nmax];

void loli()
{
    cin >> n;
    fi(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    Decompose(1, 0);
    cin >> m;
    while (m--)
    {
        int type, u;
        cin >> type >> u;
        if (type == 1)
        {
            state[u] ^= 1;
            if (state[u])
            {
                int v = u;
                st[v].insert({0, u});
                while (v != par[v])
                {
                    v = par[v];
                    st[v].insert({dis(u, v), u});
                }
            }
            else
            {
                int v = u;
                st[v].erase({0, u});
                while (v != par[v])
                {
                    v = par[v];
                    st[v].erase({dis(u, v), u});
                }
            }
        }
        else
        {
            int v = u, res = oo;
            if (!st[u].empty())
                minimize(res, (*st[u].begin()).fr);
            while (v != par[v])
            {
                v = par[v];
                if (!st[v].empty())
                    minimize(res, (*st[v].begin()).fr + dis(u, v));
            }
            cout << (res == oo ? -1 : res) << '\n';
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test = 1;
    // freopen(task".INP","r",stdin);
    // freopen(task".OUT","w",stdout);
    // cin >> test;
    while (test--)
        loli();
    return 0;
}