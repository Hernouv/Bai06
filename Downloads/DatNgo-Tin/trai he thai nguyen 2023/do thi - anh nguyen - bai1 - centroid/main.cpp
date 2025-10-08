#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200010];
bool vis[200010];
int descend[200010];
int n, res;

void dfs(int s)
{
    vis[s] = true;
    for (auto v: graph[s]) if (!vis[v])
    {
        dfs(v);
        descend[s] += descend[v];
    }
    descend[s]++;
}

void centroid_search(int s)
{
    vis[s] = true;
    int rmax = 0;
    for(auto v : graph[s]) if(!vis[v]) rmax = max(rmax, descend[v]);
    rmax = max(rmax, n - descend[s]);
    if(rmax <= n / 2)
    {
        res = s;
        return;
    }
    for(auto v : graph[s]) if(!vis[v]) centroid_search(v);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        sort(graph[i].begin(), graph[i].end());
    dfs(1);
    memset(vis, false, sizeof(vis));
    centroid_search(1);
    cout << res;
    return 0;
}
