#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> f(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int root = 1;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &[v, w] : adj[u])
        {
            if (!visited[v])
            {
                f[v] = f[u] ^ w;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    int max_f = 1 << 21;
    vector<int> first_occurrence(max_f, -1);
    bool found = false;
    int node_a, node_b;
    for (int u = 1; u <= n; u++)
    {
        if (first_occurrence[f[u]] == -1)
        {
            first_occurrence[f[u]] = u;
        }
        else
        {
            node_a = first_occurrence[f[u]];
            node_b = u;
            cout << root << " " << node_a << " " << root << " " << node_b;
            return 0;
        }
    }

    vector<pair<int, int>> first_pair(max_f, {-1, -1});
    int k = min(n, 3000);
    bool found_step2 = false;
    int x1, y1, x2, y2;
    for (int u = 1; u <= k; u++)
    {
        for (int v = u + 1; v <= k; v++)
        {
            int c = f[u] ^ f[v];
            if (first_pair[c].first == -1)
            {
                first_pair[c] = {u, v};
            }
            else
            {
                x1 = first_pair[c].first;
                y1 = first_pair[c].second;
                x2 = u;
                y2 = v;
                cout << x1 << " " << y1 << " " << x2 << " " << y2;
                return 0;
            }
        }
    }
    cout << "-1";
}
