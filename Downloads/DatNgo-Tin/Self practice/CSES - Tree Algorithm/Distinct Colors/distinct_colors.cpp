#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
set<int> colors[nmax];
int distinct_colors[nmax];
int n;

void dfs(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
            dfs(v, u);
            if (colors[v].size() > colors[u].size())
                colors[u].swap(colors[v]);
            for (int color : colors[v])
                colors[u].insert(color);
        }
    }
    distinct_colors[u] = colors[u].size();
}

void not_main()
{
    cin >> n;
    int color_node;
    for (int i = 1; i <= n; ++i)
    {
        cin >> color_node;
        colors[i].insert(color_node);
    }
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << distinct_colors[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}