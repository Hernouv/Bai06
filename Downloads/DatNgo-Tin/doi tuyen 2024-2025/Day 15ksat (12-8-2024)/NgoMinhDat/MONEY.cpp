#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ll> ill;
typedef priority_queue<ill, vector<ill>, greater<ill>> pq;
#define fi first
#define se second

const int nmax = 5e3 + 10;
const ll outbound = 1e18;

vector<ill> graph[nmax];
ll dsource_a[nmax];
ll dsource_b[nmax];
int n, m, k;
int dest_a, dest_b;
vector<ii> coin;
ll res = outbound;

pq proc_a;
void dijkstra_a(int st)
{
    for (int i = 1; i <= n; ++i)
        dsource_a[i] = outbound;

    dsource_a[st] = 0;
    proc_a.emplace(st, 0);

    while (!proc_a.empty())
    {
        int id = proc_a.top().fi;
        ll immd_dist = proc_a.top().se;
        proc_a.pop();

        if (dsource_a[id] < immd_dist)
            continue;

        for (ill v : graph[id])
        {
            if (dsource_a[v.fi] > dsource_a[id] + v.se)
            {
                dsource_a[v.fi] = dsource_a[id] + v.se;
                proc_a.emplace(v.fi, dsource_a[v.fi]);
            }
        }
    }
}

pq proc_b;
void dijkstra_b(int st)
{
    for (int i = 1; i <= n; ++i)
        dsource_b[i] = outbound;

    dsource_b[st] = 0;
    proc_b.emplace(st, 0);

    while (!proc_b.empty())
    {
        int id = proc_b.top().fi;
        ll immd_dist = proc_b.top().se;
        proc_b.pop();

        if (dsource_b[id] < immd_dist)
            continue;

        for (ill v : graph[id])
        {
            if (dsource_b[v.fi] > dsource_b[id] + v.se)
            {
                dsource_b[v.fi] = dsource_b[id] + v.se;
                proc_b.emplace(v.fi, dsource_b[v.fi]);
            }
        }
    }
}

void not_main()
{
    cin >> n >> m >> k;
    cin >> dest_a >> dest_b;

    int t_id, t_val;
    for (int i = 1; i <= k; ++i)
    {
        cin >> t_id >> t_val;
        coin.emplace_back(t_id, t_val);
    }

    int t_u, t_v, t_w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> t_u >> t_v >> t_w;
        graph[t_u].emplace_back(t_v, t_w);
        graph[t_v].emplace_back(t_u, t_w);
    }

    dijkstra_a(dest_a);
    dijkstra_b(dest_b);

    for (ii x : coin)
        res = min(res, dsource_a[x.fi] + dsource_b[x.fi] + x.se);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MONEY.INP", "r"))
    {
        freopen("MONEY.INP", "r", stdin);
        freopen("MONEY.OUT", "w", stdout);
    }
    not_main();
    return 0;
}