#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define whole(_name) _name.begin(), _name.end()
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

const int nmax = 3e5 + 5;

int n, m, num[nmax], low[nmax], N = 0, ccid[nmax], key[nmax];
vector<ii> graph[nmax];
vector<ii> newg[nmax];
vector<int> cc;
int check[nmax];

void tarjan(int u, int p)
{
    num[u] = low[u] = ++num[0];
    cc.push_back(u);
    for (ii x : graph[u])
    {
        int v = x.fi;
        if (v == p)
            continue;
        if (!num[v])
        {
            tarjan(v, u);
            minimize(low[u], low[v]);
        }
        else
            minimize(low[u], num[v]);
    }
    if (num[u] == low[u])
    {
        N++;
        while (true)
        {
            int v = cc.back();
            cc.pop_back();
            ccid[v] = N;

            if (u == v)
                break;
        }
    }
}

void dfs(int u, int p, int keys)
{
    int t = max(keys, key[u]);
    maximize(check[u], t);
    for (ii v : newg[u])
    {
        if (v.fi == p)
            continue;
        dfs(v.fi, u, max(t, v.se));
    }
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    for (int i = 1; i <= n; ++i)
        if (!num[i])
            tarjan(i, 0);

    for (int u = 1; u <= n; ++u)
    {
        for (ii x : graph[u])
        {
            int v = x.fi, c = x.se;
            if (ccid[u] == ccid[v])
                maximize(key[ccid[u]], max(c, key[ccid[v]]));
            else
                newg[ccid[u]].push_back({ccid[v], c});
        }
    }

    int a, b;
    cin >> a >> b;

    dfs(ccid[a], 0, 0);
    if (check[ccid[b]])
        cout << "YES";
    else
        cout << "NO";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}