#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nmax = 50005;
const int MAXK = 7;
const int LOGN = 17;

int N, Q, K;
int depth[nmax];
int parent[nmax];
int anc[nmax][LOGN];
int g[nmax];
int c[nmax];
int up[nmax][LOGN][MAXK];

vector<pair<int, int>> adj[nmax];

void dfs(int u, int p)
{
    for (auto &edge : adj[u])
    {
        int v = edge.first;
        int idx = edge.second;
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            parent[v] = u;
            dfs(v, u);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int l = LOGN - 1; l >= 0; --l)
    {
        if (depth[u] - (1 << l) >= depth[v])
        {
            u = anc[u][l];
        }
    }
    if (u == v)
        return u;
    for (int l = LOGN - 1; l >= 0; --l)
    {
        if (anc[u][l] != anc[v][l])
        {
            u = anc[u][l];
            v = anc[v][l];
        }
    }
    return parent[u];
}

void not_main()
{
    cin >> N >> Q >> K;
    for (int i = 2; i <= N; ++i)
    {
        int tp, tg, tc;
        cin >> tp >> tg >> tc;
        parent[i] = tp;
        g[i] = tg;
        c[i] = tc;
        adj[tp].emplace_back(i, i);
        adj[i].emplace_back(tp, i);
    }

    depth[1] = 0;
    parent[1] = 0;
    dfs(1, 0);

    for (int u = 1; u <= N; ++u)
    {
        anc[u][0] = parent[u];
    }
    for (int l = 1; l < LOGN; ++l)
    {
        for (int u = 1; u <= N; ++u)
        {
            int mid = anc[u][l - 1];
            anc[u][l] = anc[mid][l - 1];
        }
    }

    for (int u = 1; u <= N; ++u)
    {
        if (u == 1)
            continue;
        for (int t = 0; t < K; ++t)
        {
            int arrival_time_at_u = t;
            int time_mod_K = arrival_time_at_u % K;
            int waiting_time;
            if (time_mod_K < g[u])
            {
                waiting_time = 0;
            }
            else
            {
                waiting_time = K - time_mod_K;
            }
            up[u][0][t] = waiting_time + c[u];
        }
    }

    for (int l = 1; l < LOGN; ++l)
    {
        for (int u = 1; u <= N; ++u)
        {
            int anc_u = anc[u][l - 1];
            if (anc_u == 0)
                continue;
            for (int t = 0; t < K; ++t)
            {
                int time1 = up[u][l - 1][t];
                int new_t = (t + time1) % K;
                int time2 = up[anc_u][l - 1][new_t];
                up[u][l][t] = time1 + time2;
            }
        }
    }

        while (Q--)
    {
        int x, y;
        cin >> x >> y;
        int LCA = lca(x, y);

        int t = 0;
        int total_time = 0;

        auto compute_time = [&](int u, int ancestor_node) -> int
        {
            int t_local = t;
            int total = 0;
            for (int l = LOGN - 1; l >= 0; --l)
            {
                if (depth[u] - (1 << l) >= depth[ancestor_node])
                {
                    int time = up[u][l][t_local % K];
                    total += time;
                    t_local += time;
                    u = anc[u][l];
                }
            }
            t = t_local;
            return total;
        };

        t = 0;
        total_time += compute_time(x, LCA);

        t = (total_time) % K;
        total_time += compute_time(y, LCA);

        cout << total_time << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("LIGHT.INP", "r"))
    {
        freopen("LIGHT.INP", "r", stdin);
        freopen("LIGHT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
