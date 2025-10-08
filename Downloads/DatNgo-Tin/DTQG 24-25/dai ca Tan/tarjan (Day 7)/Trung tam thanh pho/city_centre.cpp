#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 3e5 + 10;

struct Frame
{
    int node;
    int parent;
    int next_child_idx;
};

bool visited[nmax];
int disc[nmax];
int low[nmax];
int parent_node[nmax];
int ap_count[nmax];
int t_v[nmax];

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent_node, -1, sizeof parent_node);
    for (int i = 0; i <= n + 1; ++i)
        t_v[i] = 1;

    int time_counter = 0;
    int c = 0;

    vector<Frame> stack_dfs;
    for (int v = 1; v <= n; v++)
    {
        if (!visited[v])
        {
            c += 1;
            if (adj[v].empty())
            {
                t_v[v] = 0;
                visited[v] = true;
                continue;
            }

            Frame start = {v, -1, 0};
            stack_dfs.push_back(start);
            disc[v] = low[v] = ++time_counter;
            visited[v] = true;
            int children = 0;
            while (!stack_dfs.empty())
            {
                Frame &current = stack_dfs.back();
                int node = current.node;
                int parent_n = current.parent;
                if (current.next_child_idx < adj[node].size())
                {
                    int neighbor = adj[node][current.next_child_idx];
                    current.next_child_idx += 1;
                    if (neighbor == parent_n)
                    {
                        continue;
                    }
                    if (!visited[neighbor])
                    {
                        parent_node[neighbor] = node;
                        disc[neighbor] = low[neighbor] = ++time_counter;
                        visited[neighbor] = true;
                        Frame child = {neighbor, node, 0};
                        stack_dfs.push_back(child);
                        if (parent_n == -1)
                        {
                            children += 1;
                        }
                    }
                    else
                    {
                        low[node] = min(low[node], disc[neighbor]);
                    }
                }
                else
                {

                    stack_dfs.pop_back();
                    if (parent_n != -1)
                    {
                        low[parent_n] = min(low[parent_n], low[node]);
                        if (low[node] >= disc[parent_n])
                        {
                            ap_count[parent_n] += 1;
                            t_v[parent_n] = ap_count[parent_n] + 1;
                        }
                    }
                    else
                    {
                        if (children > 1)
                        {
                            t_v[node] = children;
                        }
                    }
                }
            }
        }
    }

    int max_t = -1;
    int best_node = n + 1;
    for (int v = 1; v <= n; v++)
    {
        if (t_v[v] > max_t)
        {
            max_t = t_v[v];
            best_node = v;
        }
        else if (t_v[v] == max_t and v < best_node)
            best_node = v;
    }

    ll Cmax = 1LL * (ll)(c - 1) + (ll)(max_t);
    cout << Cmax << " " << best_node;
}
