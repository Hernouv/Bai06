#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
const int mmax = 5e5 + 10;

int n, m;
int population[nmax];
vector<int> graph[mmax];

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> population[i];
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("order.inp", "r"))
    {
        freopen("order.inp", "r", stdin);
        freopen("order.out", "w", stdout);
    }
    not_main();
    return 0;
}