#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int N = 255, INF = 1e9;
vector<ii> g[4 * N + 2];
vector<int> c, f;
ii res[N];
int n, m;

void addEdge(int u, int v, int lim)
{
    g[u].push_back(make_pair(v, c.size()));
    g[v].push_back(make_pair(u, c.size() + 1));
    c.push_back(lim);
    c.push_back(0);
    f.push_back(0);
    f.push_back(0);
}

void maxflow(int s, int t, int n)
{
    while (true)
    {
        vector<ii> tr(n, make_pair(INF, INF));
        tr[s] = make_pair(-1, -1);
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (ii it : g[u])
            {
                int v = it.fi, e = it.se;
                if (c[e] - f[e] > 0 and tr[v].fi == INF)
                    tr[v] = make_pair(u, e), q.push(v);
            }
        }
        if (tr[t].fi == INF)
            break;
        int delta = INF;
        for (int u = tr[t].fi, v = t; u != -1; v = u, u = tr[u].fi)
            delta = min(delta, c[tr[v].se] - f[tr[v].se]);
        for (int u = tr[t].fi, v = t; u != -1; v = u, u = tr[u].fi)
        {
            f[tr[v].se] += delta;
            f[tr[v].se ^ 1] -= delta;
        }
    }
}

void trace()
{
    fill(res, res + m, make_pair(-1, -1));
    for (int i = 0; i < m; ++i)
        for (ii it : g[i])
        {
            int v = it.fi, e = it.se;
            if (f[e] == -1)
                for (ii it2 : g[m + i])
                {
                    int v2 = it2.fi, e2 = it2.se;
                    if (f[e2] == 1)
                        res[i] = make_pair((v - 2 * m) % n, (v2 - 2 * m) % n);
                }
        }
    for (int i = 0; i < m; ++i)
        cout << res[i].fi + 1 << ' ' << res[i].se + 1 << '\n';
}

void not_main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        addEdge(i, m + i, 1);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        stringstream inp(s);
        for (int x; inp >> x; --x, addEdge(2 * m + i, x, 1))
            ;
        addEdge(2 * (m + n), 2 * m + i, 1);
    }
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        stringstream inp(s);
        for (int x; inp >> x; --x, addEdge(m + x, 2 * m + n + i, 1))
            ;
        addEdge(2 * m + n + i, 2 * (m + n) + 1, 1);
    }

    maxflow(2 * (m + n), 2 * (m + n) + 1, 2 * (m + n + 1));
    trace();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
