#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 2e5 + 10;
const ll mod = 1e9 + 7;

vector<int> graph[nmax];
int ia = 0;
bool cyclic[nmax];
int parent[nmax];
bool special_tag[nmax];
int num[nmax], low[nmax];
int ancestor[18][nmax];
ll h[nmax];
ll n, m, a, b, c;

ll pwrmod(ll base, ll expo)
{
    if (expo == 0)
        return 1;
    if (expo == 1)
        return base;
    ll t = pwrmod(base, expo / 2);
    t = (t * t) % mod;
    if (expo % 2)
        t = (t * base) % mod;
    return t;
}

void dfs(int u, int par)
{
    num[u] = ++ia;
    low[u] = ia;
    for (int v : graph[u])
    {
        if (v != par)
        {
            if (!num[v])
            {
                parent[v] = u;
                h[v] = h[u] + 1;
                dfs(v, u);
                minimize(low[u], low[v]);
            }
            else
            {
                minimize(low[u], num[v]);
                if (num[u] == low[u])
                    special_tag[u] = true;
            }
        }
    }
}

void cyclic_tag()
{
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] > low[i] or special_tag[i])
            cyclic[i] = true;
    }
}

void binary_lift()
{
    for (int i = 1; i <= n; ++i)
        ancestor[0][i] = parent[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
}

int lca(int a, int b)
{
    if (h[a] != h[b])
    {
        if (h[a] < h[b])
            swap(a, b);
        int diff = h[a] - h[b];
        for (int i = 0; (1 << i) <= diff; ++i)
            if ((diff >> i) & 1)
                a = ancestor[i][a];
    }
    if (a == b)
        return a;
    while (true)
    {
        int t = 0;
        while (ancestor[t][a] != ancestor[t][b])
            ++t;
        if (!t)
            return parent[a];
        --t;
        a = ancestor[t][a];
        b = ancestor[t][b];
    }
}

void tree_case()
{
    ll res = 0;
    binary_lift();
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int common_par = lca(i, j);
            ll dist = h[i] + h[j] - 2 * h[common_par];
            ll temp = 1LL * (dist * a + (dist + 1) * b) % mod;
            res = (res + pwrmod(temp, c)) % mod;
        }
    cout << res;
}

void sub1()
{
    binary_lift();
    ll res = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (abs(h[i] - h[j] == 1))
            {
                ll t = (a + 2 * b) % mod;
                t = pwrmod(t, c);
                res = (res + t) % mod;
            }
            else
            {
                int common_par = lca(i, j);
                int x = i, y = j;
                ll f = 0, g = 0;

                while (cyclic[x] and graph[x].size() < 3 and x != common_par)
                {
                    ++f, ++g;
                    x = parent[x];
                }
                //++g;

                while (x != common_par)
                {
                    if (!cyclic[x] or (cyclic[x] and !cyclic[parent[x]]))
                        ++f, ++g;
                    x = parent[x];
                }

                while (cyclic[y] and graph[y].size() < 3 and y != common_par)
                {
                    ++f, ++g;
                    y = parent[y];
                }
                ++g;

                while (y != common_par)
                {
                    if (!cyclic[y] or (cyclic[y] and !cyclic[parent[y]]))
                        ++f, ++g;
                    y = parent[y];
                }

                cout << i << ' ' << j << ' ' << f << ' ' << g << '\n';

                ll t = 1LL * (f * a) % mod + (g * b) % mod;
                t = pwrmod(t, c);
                res = (res + t) % mod;
            }
        }
    cout << res;
}

void not_main()
{
    cin >> n >> m >> a >> b >> c;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[1] = 0;
    dfs(1, 0);
    cyclic_tag();

    // if (n == m + 1)
    // {
    //     tree_case();
    //     return;
    // }

    sub1();
    return;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CHAMELEON.INP", "r"))
    {
        freopen("CHAMELEON.INP", "r", stdin);
        freopen("CHAMELEON.OUT", "w", stdout);
    }
    not_main();
    return 0;
}