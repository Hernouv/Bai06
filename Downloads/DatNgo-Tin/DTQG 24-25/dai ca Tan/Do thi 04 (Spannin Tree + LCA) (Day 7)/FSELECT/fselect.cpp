#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int LOG = 20;

int N, K;
int x[MAXN];
int y[MAXN];
vector<vector<int>> adj;
int up[MAXN][LOG];
int depth_node[MAXN];
int root;

void dfs(int v, int parent_v)
{
    up[v][0] = parent_v;
    for (int k = 1; k < LOG; k++)
    {
        if (up[v][k - 1] != -1)
        {
            up[v][k] = up[up[v][k - 1]][k - 1];
        }
        else
        {
            up[v][k] = -1;
        }
    }
    for (auto &u : adj[v])
    {
        if (u != parent_v)
        {
            depth_node[u] = depth_node[v] + 1;
            dfs(u, v);
        }
    }
}

int lca_func(int u, int v)
{
    if (depth_node[u] < depth_node[v])
    {
        swap(u, v);
    }
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (up[u][k] != -1 && depth_node[up[u][k]] >= depth_node[v])
        {
            u = up[u][k];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (up[u][k] != -1 && up[u][k] != up[v][k])
        {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int distance_func(int u, int v)
{
    int lca = lca_func(u, v);
    return depth_node[u] + depth_node[v] - 2 * depth_node[lca];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> K;
    adj.assign(N + 1, vector<int>());
    for (int i = 1; i <= N; i++)
    {
        cin >> x[i] >> y[i];
        if (y[i] != 0)
        {
            adj[y[i]].push_back(i);
            adj[i].push_back(y[i]);
        }
        else
        {
            root = i;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int k = 0; k < LOG; k++)
            up[i][k] = -1;
    }
    depth_node[root] = 0;
    dfs(root, -1);
    vector<vector<int>> S(K + 1, vector<int>());
    for (int i = 1; i <= N; i++)
    {
        S[x[i]].push_back(i);
    }
    for (int app = 1; app <= K; app++)
    {
        vector<int> &nodes = S[app];
        if (nodes.empty())
        {
            cout << "0\n";
            continue;
        }
        int u = nodes[0];
        int max_dist = -1;
        int v = u;
        for (auto &s : nodes)
        {
            int dist = distance_func(u, s);
            if (dist > max_dist)
            {
                max_dist = dist;
                v = s;
            }
        }
        max_dist = -1;
        for (auto &s : nodes)
        {
            int dist = distance_func(v, s);
            if (dist > max_dist)
            {
                max_dist = dist;
            }
        }
        cout << max_dist << "\n";
    }
}
