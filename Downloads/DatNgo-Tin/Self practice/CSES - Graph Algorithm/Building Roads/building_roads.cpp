#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n, m;
vector<int> graph[nmax];
bool visited[nmax];

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ii> bridges;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            bridges.emplace_back(i - 1, i);
            dfs(i);
        }
    }

    bridges.erase(bridges.begin());
    cout << bridges.size() << '\n';
    for (ii b : bridges)
        cout << b.fi << ' ' << b.se << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}