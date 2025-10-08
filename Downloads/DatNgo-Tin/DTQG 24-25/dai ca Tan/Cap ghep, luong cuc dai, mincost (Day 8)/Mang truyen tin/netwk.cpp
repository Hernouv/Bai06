#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second

const int nmax = 111;
const int V = nmax * nmax;
vector<iii> e;
vector<int> a[nmax];
int c[nmax][nmax], f[nmax][nmax], T[nmax], Q[nmax];
int m, n, s, t, res, ans;

void Init(int lim)
{
    int i, j, u, v;
    for (i = 1; i <= n; i++)
    {
        a[i].clear();
        for (j = 1; j <= n; j++)
        {
            f[i][j] = 0;
            c[i][j] = V;
        }
    }
    for (i = 0; i < m; i++)
        if (e[i].fi > lim)
        {
            u = e[i].se.fi;
            v = e[i].se.se;
            a[u].push_back(v);
            a[v].push_back(u);
        }
}

void Init2(int lim)
{
    int i, j, u, v;
    for (i = 1; i <= n; i++)
    {
        a[i].clear();
        for (j = 1; j <= n; j++)
        {
            f[i][j] = 0;
            c[i][j] = V;
        }
    }
    for (i = 0; i < m; i++)
    {
        u = e[i].se.fi;
        v = e[i].se.se;
        a[u].push_back(v);
        a[v].push_back(u);

        if (e[i].fi <= lim)
            c[u][v] = c[v][u] = 1;
    }
}

bool FindPath()
{
    int l = 1, r = 1, u, v, i;
    Q[1] = s;
    for (i = 1; i <= n; i++)
        T[i] = 0;
    while (l <= r)
    {
        u = Q[l++];
        for (i = 0; i < a[u].size(); i++)
        {
            v = a[u][i];
            if (T[v] == 0 && c[u][v] > f[u][v])
            {
                Q[++r] = v;
                T[v] = u;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}

void IncFlow()
{
    int u, v, d = (int)2e9;
    v = t;
    while (v != s)
    {
        u = T[v];
        d = min(d, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while (v != s)
    {
        u = T[v];
        f[u][v] += d;
        f[v][u] -= d;
        v = u;
    }
}

int maxFlow()
{
    while (FindPath())
        IncFlow();
    int flow = 0;
    for (int i = 0; i < a[s].size(); i++)
        flow += f[s][a[s][i]];
    return flow;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    int u, v, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        e.push_back(iii(c, ii(u, v)));
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> s >> t;
    int l = 0, r = V, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        Init(mid);
        if (FindPath())
        {
            l = mid + 1;
        }
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    Init2(res);
    ans = maxFlow();
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        if (i == s or T[i] > 0)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                int v = a[i][j];
                if (T[v] == 0)
                    cout << i << ' ' << v << '\n';
            }
        }
    return 0;
}
