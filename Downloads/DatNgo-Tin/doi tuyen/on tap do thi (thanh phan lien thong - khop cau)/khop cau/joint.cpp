#include <bits/stdc++.h>
using namespace std;

const int lim = 1e5 + 10;
vector<int> graph[lim];
int n, m;
int descendant_cnt[lim];
int parent[lim];
bool joint[lim], bridge[lim];
int ia = 0;
int num[lim], low_id[lim];

void dfs(int idx)
{
    num[idx] = low_id[idx] = ++ia;
    for (auto v : graph[idx])
    {
        if (v == parent[idx])
            continue;
        if (num[v])
            low_id[idx] = min(low_id[idx], num[v]);
        else
        {
            parent[v] = idx;
            dfs(v);
            low_id[idx] = min(low_id[idx], low_id[v]);
        }
    }
}

int find_joint()
{
    for (int v = 1; v <= n; ++v)
    {
        int pa_v = parent[v];
        if (pa_v)
            descendant_cnt[pa_v]++;
    }
    for (int v = 1; v <= n; ++v)
    {
        int pa_v = parent[v];
        if (pa_v and parent[pa_v] and low_id[v] >= num[pa_v])
            joint[pa_v] = true;
    }
    for (int v = 1; v <= n; ++v)
        if (!parent[v] and descendant_cnt[v] >= 2)
            joint[v] = true;
    int ret = 0;
    for (int v = 1; v <= n; ++v)
        ret += joint[v];
    return ret;
}

int find_bridge()
{
    int ret = 0;
    for (int v = 1; v <= n; ++v)
        if (parent[v] and low_id[v] >= num[v])
            ret++;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
        {
            dfs(i);
        }
    }
    cout << find_joint() << ' ' << find_bridge();
    return 0;
}