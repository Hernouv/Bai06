#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
const ll mod = 998244353;

vector<ll> w;
vector<int> par;
vector<vector<int>> graph;
vector<ll> maxw;
int n, q, it = 0;

void dfs(int u)
{
    for (int v : graph[u])
    {
        if (v == par[v])
            continue;
        if (v > n)
            maximize(maxw[u], w[v]);
        else
        {
            dfs(v);
            maximize(maxw[u], 1LL * maxw[v]);
        }
    }
    maxw[u] *= 2;
}

void backtrack(int u)
{
    if (u == 1)
        return;
    int tpar = par[u];
    ll tval = (u <= n ? maxw[u] : w[u]);
    if (maximize(maxw[tpar], tval * 2))
        backtrack(tpar);
    else
        return;
}

void not_main()
{
    cin >> n >> q;
    w.resize(2 * n + 5);
    maxw.resize(n + 5, 0);
    par.resize(2 * n + 5);
    graph.resize(n + 5, vector<int>(2));

    char c1, c2;
    int id1, id2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c1 >> id1 >> c2 >> id2;
        if (c1 == 'W')
            id1 += n;
        graph[i][0] = id1;
        par[id1] = i;
        if (c2 == 'W')
            id2 += n;
        graph[i][1] = id2;
        par[id2] = i;
    }

    for (int i = n + 1; i <= 2 * n + 1; ++i)
        cin >> w[i];

    dfs(1);

    for (int i = 1, rqtype, tu, tw; i <= q; ++i)
    {
        cin >> rqtype >> tu;
        if (rqtype == 1)
        {
            tu += n;
            cin >> tw;
            w[tu] = tw;
            backtrack(tu);
        }
        if (rqtype == 2)
            cout << maxw[tu] % mod << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("weight.inp", "r"))
    {
        freopen("weight.inp", "r", stdin);
        freopen("weight.out", "w", stdout);
    }
    not_main();
    return 0;
}