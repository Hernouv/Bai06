#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
int n;
int a[nmax];
vector<int> pos[nmax];
vector<int> tour;

void dfs(int par, int u)
{
    tour.push_back(u);
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        dfs(u, v);
    }
    tour.push_back(u);
}

void not_main()
{
    cin >> n;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    dfs(0, 1);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}