#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 1e5 + 10;
int n, m;
vector<ill> graph[2 * nmax];
ll dist[2 * nmax];

struct node
{
    int u;
    ll d;
    bool operator<(const node &other) const
    {
        return (d > other.d);
    }
};

priority_queue<node> pq;
void dijkstra(int st)
{
    memset(dist, 0x3f3f, sizeof dist);
    dist[1] = 0;
    pq.push({1, 0});
    while (!pq.empty())
    {
        node V = pq.top();
        pq.pop();

        if (dist[V.u] < V.d)
            continue;

        for (ill v : graph[V.u])
            if (minimize(dist[v.fi], dist[V.u] + v.se))
                pq.push({v.fi, dist[v.fi]});
    }
}

void not_main()
{
    cin >> n >> m;
    int tu, tv;
    ll tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].emplace_back(tv, tw);
        graph[tv + n].emplace_back(tu + n, tw);
    }
    for (int i = 1; i <= n; ++i)
        graph[i].emplace_back(i + n, 0);
    dijkstra(1);
    for (int i = 2; i <= n; ++i)
    {
        if (dist[i + n] > 1e16)
            cout << "-1 ";
        else
            cout << dist[i + n] << ' ';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}