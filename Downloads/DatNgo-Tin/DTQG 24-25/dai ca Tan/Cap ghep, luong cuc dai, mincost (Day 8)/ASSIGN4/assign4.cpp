#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
const ll INF = 1e18;

const int nmax = 402;

ll cap_matrix[nmax][nmax];
ll cost_matrix[nmax][nmax];

void addEdge(int from, int to, ll cap, ll cost)
{
    cap_matrix[from][to] = cap;
    cost_matrix[from][to] = cost;
    if (cost_matrix[to][from] == 0 and to != from)
    {
        cost_matrix[to][from] = -cost;
    }
}

ll minCostFlow(int N, int source, int sink, ll required_flow)
{
    ll total_cost = 0;
    ll pot[nmax];
    memset(pot, 0, sizeof(pot));

    while (required_flow > 0)
    {
        ll dist[nmax];
        int prevv[nmax];
        memset(prevv, -1, sizeof(prevv));
        for (int i = 0; i < N; i++)
            dist[i] = INF;
        dist[source] = 0;

        bool used[nmax];
        memset(used, 0, sizeof(used));

        for (int i = 0; i < N; i++)
        {
            int u = -1;
            for (int v = 0; v < N; v++)
            {
                if (!used[v] and (u == -1 or dist[v] < dist[u]))
                {
                    u = v;
                }
            }
            if (u == -1 or dist[u] == INF)
                break;
            used[u] = true;

            for (int v = 0; v < N; v++)
            {
                if (cap_matrix[u][v] > 0)
                {
                    ll new_dist = dist[u] + cost_matrix[u][v] + pot[u] - pot[v];
                    if (new_dist < dist[v])
                    {
                        dist[v] = new_dist;
                        prevv[v] = u;
                    }
                }
            }
        }

        if (dist[sink] == INF)
        {
            break;
        }

        for (int v = 0; v < N; v++)
        {
            if (dist[v] < INF)
                pot[v] += dist[v];
        }

        ll add_flow = required_flow;
        int v = sink;
        while (v != source)
        {
            int u = prevv[v];
            if (u == -1)
            {
                add_flow = 0;
                break;
            }
            add_flow = min(add_flow, cap_matrix[u][v]);
            v = u;
        }

        if (add_flow == 0)
            break;

        required_flow -= add_flow;
        total_cost += add_flow * pot[sink];

        v = sink;
        while (v != source)
        {
            int u = prevv[v];
            cap_matrix[u][v] -= add_flow;
            cap_matrix[v][u] += add_flow;
            v = u;
        }
    }

    return total_cost;
}

ll a[nmax];
ll b[nmax];
ll C[nmax][nmax];

void not_main()
{
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> C[i][j];
        }
    }

    int N_nodes = m + n + 2;
    int source = 0;
    int sink = m + n + 1;

    for (int i = 0; i < N_nodes; i++)
    {
        for (int j = 0; j < N_nodes; j++)
        {
            cap_matrix[i][j] = 0;
            cost_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        addEdge(source, 1 + i, a[i], 0);
    }

    for (int j = 0; j < n; j++)
    {
        addEdge(1 + m + j, sink, b[j], 0);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            addEdge(1 + i, 1 + m + j, INF, C[i][j]);
        }
    }

    ll total_required_flow = 0;
    for (int i = 0; i < m; i++)
        total_required_flow += a[i];

    ll min_cost = minCostFlow(N_nodes, source, sink, total_required_flow);

    cout << min_cost << "\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        not_main();
    return 0;
}
