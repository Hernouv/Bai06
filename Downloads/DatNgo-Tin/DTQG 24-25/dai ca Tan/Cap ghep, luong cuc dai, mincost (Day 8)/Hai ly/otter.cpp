#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int INF = 1e9;

class HopcroftKarp
{
public:
    int n, m;
    vector<vector<int>> adj;
    vector<int> pair_U, pair_V, dist;

    HopcroftKarp(int size_U, int size_V)
    {
        n = size_U;
        m = size_V;
        adj.assign(n, vector<int>());
        pair_U.assign(n, -1);
        pair_V.assign(m, -1);
        dist.assign(n, 0);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool bfs()
    {
        queue<int> q;
        for (int u = 0; u < n; u++)
        {
            if (pair_U[u] == -1)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = INF;
            }
        }
        bool found_augmenting_path = false;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u])
            {
                if (pair_V[v] != -1 && dist[pair_V[v]] == INF)
                {
                    dist[pair_V[v]] = dist[u] + 1;
                    q.push(pair_V[v]);
                }
                else if (pair_V[v] == -1)
                {
                    found_augmenting_path = true;
                }
            }
        }
        return found_augmenting_path;
    }

    bool dfs(int u)
    {
        for (auto &v : adj[u])
        {
            if (pair_V[v] == -1 || (dist[pair_V[v]] == dist[u] + 1 && dfs(pair_V[v])))
            {
                pair_U[u] = v;
                pair_V[v] = u;
                return true;
            }
        }
        dist[u] = INF;
        return false;
    }

    int max_matching()
    {
        int matching = 0;
        while (bfs())
        {
            for (int u = 0; u < n; u++)
            {
                if (pair_U[u] == -1)
                {
                    if (dfs(u))
                    {
                        matching++;
                    }
                }
            }
        }
        return matching;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, s, v;
    cin >> n >> m >> s >> v;
    vector<ii> seagulls(n);
    for (int i = 0; i < n; i++)
        cin >> seagulls[i].fi >> seagulls[i].se;
    vector<ii> holes(m);
    for (int i = 0; i < m; i++)
        cin >> holes[i].fi >> holes[i].se;
    ll limit_sq = (ll)s * v;
    limit_sq *= limit_sq;
    HopcroftKarp hk(n, m);
    for (int i = 0; i < n; i++)
    {
        int xi = seagulls[i].fi;
        int yi = seagulls[i].se;
        for (int j = 0; j < m; j++)
        {
            int xj = holes[j].fi;
            int yj = holes[j].se;
            ll dx = (ll)(xi - xj);
            ll dy = (ll)(yi - yj);
            ll dist_sq = dx * dx + dy * dy;
            if (dist_sq <= limit_sq)
            {
                hk.add_edge(i, j);
            }
        }
    }
    int matching = hk.max_matching();
    cout << (n - matching);
}
