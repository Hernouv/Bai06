#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int cc_count = 0;
set<int> cc[100010];
bool visited[100010];
int n, m;

void dfs(int start)
{
    visited[start] = true;
    cc[cc_count].insert(start);
    for (auto v : graph[start])
    {
        if (!visited[v])
            dfs(v);
    }
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
        if (!visited[i])
        {
            cc_count++;
            dfs(i);
        }
    }

    cout << cc_count << '\n';
    for (int i = 1; i <= cc_count; ++i)
    {
        for (auto x : cc[i])
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}