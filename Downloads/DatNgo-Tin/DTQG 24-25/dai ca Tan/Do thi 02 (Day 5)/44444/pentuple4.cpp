#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 44444 + 5;
const int MAX_K = 5;
const int MAX_SUM_W = 180;
const ll INF = 1e18;

struct State
{
    ll cost;
    int node;
    int pos;
    int sum_w;
    bool operator<(const State &other) const { return cost > other.cost; }
};

int n, m, k;
vector<pair<int, int>> adj[MAX_N];
ll dist[MAX_N][MAX_K][MAX_SUM_W + 1];
ll move_cost_powers[MAX_SUM_W + 1];

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        adj[ui].emplace_back(vi, wi);
        adj[vi].emplace_back(ui, wi);
    }

    move_cost_powers[0] = 0;
    for (int c = 1; c <= MAX_SUM_W; ++c)
    {
        ll power = 1;
        for (int i = 0; i < k; ++i)
        {
            power *= c;
        }
        move_cost_powers[c] = power;
    }
    for (int i = 1; i <= n; ++i)
        for (int s = 0; s < k; ++s)
            for (int c = 0; c <= MAX_SUM_W; ++c)
                dist[i][s][c] = INF;

    priority_queue<State> pq;
    dist[1][0][0] = 0;
    pq.push({0, 1, 0, 0});
    while (!pq.empty())
    {
        State state = pq.top();
        pq.pop();
        ll cost = state.cost;
        int node = state.node;
        int pos = state.pos;
        int sum_w = state.sum_w;

        if (cost > dist[node][pos][sum_w])
            continue;

        for (auto [v, w] : adj[node])
        {
            if (pos + 1 < k)
            {
                int next_pos = pos + 1;
                int next_sum_w = sum_w + w;
                if (next_sum_w > 44 * 4)
                    continue;
                if (dist[v][next_pos][next_sum_w] > cost)
                {
                    dist[v][next_pos][next_sum_w] = cost;
                    pq.push(State{cost, v, next_pos, next_sum_w});
                }
            }
            else
            {
                int total_w = sum_w + w;
                if (total_w > MAX_SUM_W)
                    continue;

                ll next_cost = cost + move_cost_powers[total_w];
                if (dist[v][0][0] > next_cost)
                {
                    dist[v][0][0] = next_cost;
                    pq.push(State{next_cost, v, 0, 0});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        ll ans = dist[i][0][0];
        if (ans >= INF)
            cout << "-1 ";
        else
            cout << ans << " ";
    }
}