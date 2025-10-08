#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int parent[200001];
int distcenter[200001];
int n, k;

void dfs(int id)
{
    for (auto v : graph[id])
    {
        distcenter[v] = distcenter[id] + 1;
        dfs(v);
    }
}

void par(int id)
{
    for (auto v : graph[id])
    {
        parent[v] = id;
        if (parent[id] != 1) parent[v] = parent[id];
        par(v);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    parent[1] = 1;
    cin >> n >> k;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    distcenter[1] = 0;
    dfs(1);
    par(1);


}
