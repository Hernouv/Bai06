// if //tagged, then have to study the function of that code line
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pt;
#define fi first
#define se second

const int maxn = 4e5 + 10;
int n, m;
ll D;
int src, dest;

struct edge
{
    int u, v;
    ll w;

    void read()
    {
        cin >> u >> v >> w;
    }

    int other(int x)
    {
        return u ^ v ^ x;
    }

} e[maxn];

struct state
{
    int id;
    int u;

    state(int _id, int _u)
    {
        id = _id;
        u = _u;
    }

    int ia()
    {
        if (this->u != e[id].u)
            return id * 2;
        return id * 2 + 1;
    }
};

vector<pair<int, ll>> new_g[maxn];
vector<int> e_conn[maxn];

bool cmpId(const int a, const int b)
{
    return e[a].w < e[b].w;
}

void buildNewGraph()
{
    for (int id = 1; id <= m; id++)
    {
        int tmp[2] = {e[id].u, e[id].v};
        for (int dir = 0; dir < 2; ++dir)
        {
            int u = tmp[dir];
            int v = tmp[1 - dir];
            e[0].w = e[id].w + D;
            int nxt = lower_bound(e_conn[v].begin(), e_conn[v].end(), 0, cmpId) - e_conn[v].begin();

            if (nxt < (int)e_conn[v].size())
            {
                nxt = e_conn[v][nxt];
                int newU = state(id, v).ia();
                int newV = state(nxt, e[nxt].other(v)).ia();
                cerr << newU << ' ' << newV << '\n';
                ll newW = e[nxt].w;
                new_g[newU].emplace_back(newV, newW);
            }
        }
    }
    cerr << '\n';
    for (int v = 1; v <= n; v++)
    {
        for (int i = 0; i < (int)e_conn[v].size() - 1; ++i)
        {
            int p = e_conn[v][i], q = e_conn[v][i + 1];
            int newU = state(p, e[p].other(v)).ia();
            int newV = state(q, e[q].other(v)).ia();
            cerr << newU << ' ' << newV << '\n';
            ll newW = e[q].w - e[p].w;
            new_g[newU].emplace_back(newV, newW);
        }
    }
}

priority_queue<pair<ll, int>> pq;
ll d[maxn * 3];
const ll outbound = 1e18;

void dijkstra()
{
    for (int i = 2; i <= 2 * m + 1; ++i)
        d[i] = outbound;
    while (!pq.empty())
        pq.pop();
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].u == src)
        {
            int newId = state(i, e[i].v).ia();
            d[newId] = e[i].w;
            pq.emplace(-d[newId], newId);
        }
        else if (e[i].v == src)
        {
            int newId = state(i, e[i].u).ia();
            d[newId] = e[i].w;
            pq.emplace(-d[newId], newId);
        }
    }

    while (!pq.empty())
    {
        pair<ll, int> cur = pq.top();
        pq.pop();
        int u = cur.se;
        if (d[u] != -cur.fi)
            continue;
        for (int i = 0; i < (int)new_g[u].size(); ++i)
        {
            int v = new_g[u][i].fi;
            ll w = new_g[u][i].se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.emplace(-d[v], v);
            }
        }
    }

    ll result = outbound;
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].u == dest)
        {
            int newId = state(i, e[i].u).ia();
            result = min(result, d[newId]);
        }
        else if (e[i].v == dest)
        {
            int newId = state(i, e[i].v).ia();
            result = min(result, d[newId]);
        }
    }

    if (result == outbound)
        result = -1;
    cout << result << '\n';
}

void not_main()
{
    cin >> n >> m >> D;
    src = 1, dest = n;
    for (int i = 1; i <= m; ++i)
        e[i].read();
    for (int i = 1; i <= m; ++i)
    {
        e_conn[e[i].u].push_back(i);
        e_conn[e[i].v].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        sort(e_conn[i].begin(), e_conn[i].end(), cmpId);

    buildNewGraph();
    dijkstra();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DANANG.INP", "r"))
    {
        freopen("DANANG.INP", "r", stdin);
        freopen("DANANG.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
