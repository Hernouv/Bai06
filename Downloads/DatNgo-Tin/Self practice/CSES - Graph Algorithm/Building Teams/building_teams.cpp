#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
int team[nmax];
vector<int> graph[nmax];
int n, m;
bool invalid_sol;

void dfs(int u, int tag)
{
    team[u] = tag;
    for (int v : graph[u])
    {
        if (!team[v])
            dfs(v, 3 - tag);
        else if (team[v] == team[u])
        {
            invalid_sol = true;
            return;
        }
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

    for (int i = 1; i <= n; ++i)
    {
        if (!team[i])
            dfs(i, 1);
    }

    if (invalid_sol)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 1; i <= n; ++i)
        cout << team[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}