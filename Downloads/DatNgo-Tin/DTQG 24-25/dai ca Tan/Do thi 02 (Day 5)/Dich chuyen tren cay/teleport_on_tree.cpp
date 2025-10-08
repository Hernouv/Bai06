#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

#define fi first
#define se second
#define pb push_back
#define int int

#define FOR(i, x, n) for (int i = x; i <= n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, x, n) for (int i = x; i >= n; --i)

#define oo 1e18

const int N = 2e5 + 250;
int n, m, q, res;
int h[N], f[N];
int ances[N][50], Max[N][50], dist[30][N];
vector<ii> graph1[N];
vector<ii> graph2[N];

void DFS(int i, int j)
{
    for (ii s : graph1[i])
    {
        int u = s.fi;
        int val = s.se;
        if (u != j)
        {
            h[u] = h[i] + 1;
            f[u] = f[i] + 2;
            ances[u][0] = i;
            for (int j = 1; j <= n; j++)
                if (ances[j][i - 1] != 0)
                    ances[j][i] = ances[ances[j][i - 1]][i - 1];
            DFS(u, i);
        }
    }
}

int LCA(int x, int y)
{
    int sum = 0;
    if (h[x] < h[y])
        swap(x, y);
    int z = log2(h[x]);
    for (int i = z; i >= 0; i--)
        if (h[x] - (1 << i) >= h[y])
            x = ances[x][i];
    if (x == y)
        return x;
    for (int i = z; i >= 0; i--)
        if (ances[x][i] != ances[y][i] && ances[x][i] != 0)
        {
            x = ances[x][i];
            y = ances[y][i];
        }
    return ances[x][0];
}

void dijk(int i, int j)
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    FOR(k, 1, n + 'z')
    dist[i][k] = 1e9;
    dist[i][j] = 0;
    q.push(ii(dist[i][j], j));
    while (!q.empty())
    {
        int u = q.top().se;
        int cost = q.top().fi;
        q.pop();
        if (cost > dist[i][u])
            continue;
        REP(s, graph2[u].size())
        {
            int v = graph2[u][s].fi;
            int w = graph2[u][s].se;
            if (dist[i][v] > dist[i][u] + w)
                q.push(ii(dist[i][v] = dist[i][u] + w, v));
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char f;
        cin >> f;
        graph2[i].pb(ii(f + n, 1));
        graph2[f + n].pb(ii(i, 1));
    }
    FOR(i, 1, n - 1)
    {
        int x, y, z;
        cin >> x >> y;
        z = 1;
        graph1[x].pb(ii(y, 2));
        graph1[y].pb(ii(x, 2));
        graph2[x].pb(ii(y, 2));
        graph2[y].pb(ii(x, 2));
    }
    FOR(i, 'a', 'z')
    dijk(i - 'a' + 1, n + i);
    DFS(1, -1);
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int u, v;
        cin >> u >> v;
        int temp = f[u] + f[v] - 2 * f[LCA(u, v)];
        FOR(i, 'a', 'z')
        temp = min(temp, dist[i - 'a' + 1][u] + dist[i - 'a' + 1][v]);
        cout << temp / 2 << "\n";
    }
}