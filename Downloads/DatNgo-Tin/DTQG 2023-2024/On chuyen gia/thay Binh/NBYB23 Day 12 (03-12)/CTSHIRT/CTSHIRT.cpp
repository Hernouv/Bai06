#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int color[100010];
int n, m;

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    return 0;
}