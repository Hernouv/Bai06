#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 4e5 + 5;
const ll INF = 1e18;

struct edge
{
    int u, v, w;
    int cap, flow;
    edge() { flow = 0; }
    edge(int _u, int _v, int _w, int _cap)
    {
        u = _u;
        v = _v;
        w = _w;
        cap = _cap;
        flow = 0;
    }
    int getAdj(int _u)
    {
        return u ^ v ^ _u;
    }
    int getCost()
    {
        return flow < 0 ? -w : w;
    }
    int getResidualFlow()
    {
        return flow < 0 ? -flow : (cap - flow);
    }
} edges[nmax];

int nEdge;
int n, m, source, sink;
bool inQ[nmax];
ll d[nmax];
int maxFlow;
ll minCost;
bool was[nmax];
int T[nmax];
vector<int> a[nmax];

void addEdge(int u, int v, int w)
{
    if ((nEdge & 1))
        return;
    edges[nEdge] = edge(u, v, w, 1);
    edges[nEdge | 1] = edge(v, u, w, 1);
    a[u].push_back(nEdge);
    a[v].push_back(nEdge | 1);
    nEdge += 2;
}

bool findPath()
{
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        d[i] = INF;
    d[source] = 0;
    Q.push(source);
    inQ[source] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQ[u] = 0;
        for (int it : a[u])
        {
            if (edges[it].cap > edges[it].flow)
            {
                int cost = edges[it].getCost();
                int v = edges[it].getAdj(u);
                if (d[v] > d[u] + cost)
                {
                    T[v] = it;
                    d[v] = d[u] + cost;
                    if (!inQ[v])
                    {
                        inQ[v] = 1;
                        Q.push(v);
                    }
                }
            }
        }
    }
    return d[sink] < INF;
}

void incFlow()
{
    for (int v = sink; v != source; v = edges[T[v]].getAdj(v))
        ++edges[T[v]].flow, --edges[T[v] ^ 1].flow;
    ++maxFlow;
    minCost += d[sink];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int s, f;
    cin >> n >> m >> s >> f;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    source = n + 1;
    sink = f;
    addEdge(source, s, 0);
    addEdge(source, s, 0);
    ++n;
    for (int i = 1; i <= n; ++i)
        random_shuffle(a[i].begin(), a[i].end());
    while (maxFlow < 2 and findPath())
        incFlow();
    if (maxFlow < 2)
        cout << -1;
    else
        cout << minCost;
    return 0;
}
