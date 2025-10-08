#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 2e5 + 10;

vector<int> graph[nmax];
int dp1[nmax], dp2[nmax];

int n;

void dfs(int u, int par)
{
    for (int v : graph[u])
    {
        if (v != par)
        {
            dfs(v, u);
            dp2[u] += max(dp1[v], dp2[v]);
        }
    }
    for (int v : graph[u])
    {
        if (v != par)
            maximize(dp1[u], dp2[v] + 1 + dp2[u] - max(dp1[v], dp2[v]));
    }
}

void not_main()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}