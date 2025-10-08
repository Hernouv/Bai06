#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;
const int LOG = 20;

vector<vector<int>> adj(MAX);
int parent_table[LOG][MAX];
int depth_node[MAX];
long long count_node[MAX];
int N, M;

void dfs(int u, int parent)
{
    parent_table[0][u] = parent;
    for (auto &v : adj[u])
    {
        if (v != parent)
        {
            depth_node[v] = depth_node[u] + 1;
            dfs(v, u);
        }
    }
}

void preprocess()
{
    for (int k = 1; k < LOG; k++)
    {
        for (int v = 1; v <= N; v++)
        {
            if (parent_table[k - 1][v] != -1)
            {
                parent_table[k][v] = parent_table[k - 1][parent_table[k - 1][v]];
            }
            else
            {
                parent_table[k][v] = -1;
            }
        }
    }
}

int lca_query(int u, int v)
{
    if (depth_node[u] < depth_node[v])
    {
        swap(u, v);
    }
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (parent_table[k][u] != -1 && depth_node[parent_table[k][u]] >= depth_node[v])
        {
            u = parent_table[k][u];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (parent_table[k][u] != -1 && parent_table[k][u] != parent_table[k][v])
        {
            u = parent_table[k][u];
            v = parent_table[k][v];
        }
    }
    return parent_table[0][u];
}

vector<pair<int, int>> edges;

long long dfs_accumulate(int u, int parent)
{
    long long total = count_node[u];
    for (auto &v : adj[u])
    {
        if (v != parent)
        {
            long long child_sum = dfs_accumulate(v, u);
            total += child_sum;
        }
    }
    count_node[u] = total;
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }

    for (int k = 0; k < LOG; k++)
    {
        for (int v = 1; v <= N; v++)
        {
            parent_table[k][v] = -1;
        }
    }

    depth_node[1] = 0;
    dfs(1, -1);

    preprocess();

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int c = lca_query(a, b);
        count_node[a] += 1;
        count_node[b] += 1;
        count_node[c] -= 2;
    }

    dfs_accumulate(1, -1);

    int unvisited = 0;
    for (auto &[u, v] : edges)
    {
        if (parent_table[0][u] == v)
        {
            if (count_node[u] <= 0)
            {
                unvisited++;
            }
        }
        else
        {
            if (count_node[v] <= 0)
            {
                unvisited++;
            }
        }
    }

    cout << unvisited;

    return 0;
}
