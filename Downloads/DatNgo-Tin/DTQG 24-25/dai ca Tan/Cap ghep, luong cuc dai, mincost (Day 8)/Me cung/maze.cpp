#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 2e18;
const int nmax = 1e3 + 5;

int n, m, s, t;
struct Edge
{
    int from, to, cap;
    ll flow;
    Edge(int a, int b, ll c, int d)
    {
        from = a;
        to = b;
        flow = c;
        cap = d;
    }
};

vector<Edge> edges;
vector<int> g[nmax];
bool vis[nmax];
ll d[nmax];
int a[nmax];
int cur[nmax];

int gcd(int x, int y)
{
    while (x and y)
    {
        if (x < y)
            swap(x, y);
        x %= y;
    }
    return max(x, y);
}

void add_edge(int from, int to, ll flow, int cap)
{
    edges.push_back(Edge(from, to, flow, cap));
    edges.push_back(Edge(to, from, -flow, 0));
    int sz = edges.size();
    g[from].push_back(sz - 2);
    g[to].push_back(sz - 1);
}

ll dfs(int u, ll a)
{
    if (u == t or a == 0)
        return a;
    ll flow = 0, f;
    for (int &i = cur[u]; i < g[u].size(); i++)
    {
        Edge &e = edges[g[u][i]];
        if (d[e.to] == d[u] + 1)
        {
            f = dfs(e.to, min(a, e.cap - e.flow));
            if (f > 0)
            {
                e.flow += f;
                edges[g[u][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
    }
    return flow;
}

bool bfs()
{
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            Edge &e = edges[g[u][i]];
            if (!vis[e.to] and e.cap > e.flow)
            {
                vis[e.to] = 1;
                d[e.to] = d[u] + 1;
                q.push(e.to);
            }
        }
    }
    return vis[t];
}

ll dinic(int s, int t)
{
    ll flow = 0;
    while (bfs())
    {
        memset(cur, 0, sizeof cur);
        flow += dfs(s, INF);
    }
    return flow;
}

void not_main()
{
    int n;
    cin >> n;

    s = INF;
    t = -INF;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s = min(s, a[i]);
        t = max(t, a[i]);
    }

    for (int i = 0; i < n; i++)
        if (a[i] == s)
        {
            s = i;
            break;
        }

    for (int i = 0; i < n; i++)
        if (a[i] == t)
        {
            t = i;
            break;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            m = gcd(a[i], a[j]);
            if (m != 1 and i != j)
                add_edge(i, j, 0, m);
        }

    ll ans = dinic(s, t);
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}