#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;

int n, m, k;
vector<int> graph[nmax];

void not_main()
{
    cin >> n >> m >> k;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRAFFIC.INP", "r"))
    {
        freopen("TRAFFIC.INP", "r", stdin);
        freopen("TRAFFIC.OUT", "w", stdout);
    }
    not_main();
    return 0;
}