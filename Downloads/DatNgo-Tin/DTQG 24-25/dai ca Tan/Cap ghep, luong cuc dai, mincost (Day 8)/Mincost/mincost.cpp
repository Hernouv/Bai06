#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i <= (b); ++i)

#define int long long

const int nmax = 222;
const int INF = INT_MAX;

int d[nmax];
int T[nmax];
bool inQ[nmax];
int cap[nmax][nmax], cost[nmax][nmax], flow[nmax][nmax];
int n, m, source, sink;
int minCost, maxFlow;

bool findPath()
{
    queue<int> Q;
    loop(i, 1, n)
    {
        d[i] = INF;
        T[i] = 0;
        inQ[i] = 0;
    }
    Q.push(source);
    inQ[source] = 1;
    d[source] = 0LL;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQ[u] = 0;
        loop(v, 1, n) if (flow[u][v] < cap[u][v])
        {
            int uv = (flow[u][v] < 0 ? -1 : 1) * cost[u][v];
            if (d[v] > d[u] + uv)
            {
                d[v] = d[u] + uv;
                T[v] = u;
                if (!inQ[v])
                {
                    inQ[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    return T[sink] != 0;
}

void incFlow()
{
    int delta = INF;
    for (int v = sink; v != source; v = T[v])
        delta = min(delta, flow[T[v]][v] >= 0 ? (cap[T[v]][v] - flow[T[v]][v]) : -flow[T[v]][v]);
    for (int v = sink; v != source; v = T[v])
        flow[T[v]][v] += delta, flow[v][T[v]] -= delta;
    maxFlow += delta;
    minCost += d[sink] * delta;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> maxFlow >> source >> sink;
    int u, v;
    loop(i, 0, m - 1)
    {
        cin >> u >> v;
        cin >> cost[u][v] >> cap[u][v];
        cost[v][u] = cost[u][v];
        cap[v][u] = cap[u][v];
    }
    ++n;
    cost[n][source] = 0;
    cap[n][source] = maxFlow;
    int S = maxFlow;
    source = n;
    maxFlow = 0;
    while (findPath())
        incFlow();
    if (maxFlow < S)
        cout << -1 << '\n';
    else
    {
        cout << minCost << '\n';
        loop(u, 1, n - 1)
        {
            loop(v, 1, n - 1)
            {
                if (flow[u][v] > 0)
                    cout << u << ' ' << v << ' ' << flow[u][v] << '\n';
            }
        }
        cout << "0 0 0\n";
    }
    return 0;
}
