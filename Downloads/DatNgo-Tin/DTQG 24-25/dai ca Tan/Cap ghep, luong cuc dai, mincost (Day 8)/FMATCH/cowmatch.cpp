#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < P; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    vector<int> pair_left(N + 1, 0);
    vector<int> pair_right(M + 1, 0);
    vector<int> dist(N + 1, 0);
    auto bfs = [&]() -> bool
    {
        queue<int> q;
        for (int u = 1; u <= N; ++u)
        {
            if (pair_left[u] == 0)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = INT32_MAX;
            }
        }
        int dist_nil = INT32_MAX;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (dist[u] < dist_nil)
            {
                for (auto &v : adj[u])
                {
                    if (pair_right[v] == 0)
                    {
                        if (dist_nil == INT32_MAX)
                        {
                            dist_nil = dist[u] + 1;
                        }
                    }
                    else
                    {
                        if (dist[pair_right[v]] == INT32_MAX)
                        {
                            dist[pair_right[v]] = dist[u] + 1;
                            q.push(pair_right[v]);
                        }
                    }
                }
            }
        }
        return dist_nil != INT32_MAX;
    };
    function<bool(int)> dfs = [&](int u) -> bool
    {
        for (auto &v : adj[u])
        {
            if (pair_right[v] == 0 || (dist[pair_right[v]] == dist[u] + 1 && dfs(pair_right[v])))
            {
                pair_left[u] = v;
                pair_right[v] = u;
                return true;
            }
        }
        dist[u] = INT32_MAX;
        return false;
    };
    int matching = 0;
    while (bfs())
    {
        for (int u = 1; u <= N; ++u)
        {
            if (pair_left[u] == 0)
            {
                if (dfs(u))
                {
                    matching++;
                }
            }
        }
    }
    cout << matching;
}
