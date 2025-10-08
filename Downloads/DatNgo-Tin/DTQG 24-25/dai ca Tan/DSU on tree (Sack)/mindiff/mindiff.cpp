#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 5;
int n;
int a[nmax];
vector<int> adj[nmax];

int ans[nmax + 1];

struct node
{
    multiset<int> vals;
    int min_diff = -1;
};

node dfsData[nmax];
bool visited[nmax];

void merge_proc(node &big, node &small)
{
    for (int val : small.vals)
    {
        multiset<int>::iterator it = big.vals.lower_bound(val);

        int left_neighbor = -1, right_neighbor = -1;
        if (it != big.vals.begin())
        {
            multiset<int>::iterator prev_it = prev(it);
            left_neighbor = *prev_it;
        }
        if (it != big.vals.end())
            right_neighbor = *it;

        if (left_neighbor != -1)
        {
            int diff = abs(val - left_neighbor);
            if (big.min_diff == -1 or diff < big.min_diff)
                big.min_diff = diff;
        }
        if (right_neighbor != -1)
        {
            int diff = abs(right_neighbor - val);
            if (big.min_diff == -1 or diff < big.min_diff)
                big.min_diff = diff;
        }

        big.vals.insert(it, val);
    }
}

void dfs(int p, int u)
{
    visited[u] = true;
    dfsData[u].vals.insert(a[u]);
    dfsData[u].min_diff = -1;

    for (int &v : adj[u])
    {
        if (v == p)
            continue;
        if (!visited[v])
        {
            dfs(u, v);
            if (dfsData[v].vals.size() > dfsData[u].vals.size())
                swap(dfsData[u], dfsData[v]);

            merge_proc(dfsData[u], dfsData[v]);
        }
    }

    ans[u] = dfsData[u].min_diff;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(-1, 1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";

    return 0;
}
