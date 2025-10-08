#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
int const N = 2e5 + 5, oo = 1e9;
int mod = oo + 7;
ll const OO = 1e18;
int n, q;
vector<vector<int>> from_root, dp;
vector<int> dep;
vector<vector<pair<int, pp>>> adj;

void dfs(int u, int p = 0, ll cs1 = 0, ll cs2 = 0)
{
    from_root[0][u] = cs1;
    from_root[1][u] = cs2;
    dp[u][0] = p;
    for (auto v : adj[u])
    {
        if (v.first == p)
            continue;
        int a = v.second.first, b = v.second.second;
        dep[v.first] = dep[u] + 1;
        dfs(v.first, u, cs1 + a, cs2 + b);
    }
}

int lca(int a, int b)
{
    if (dep[a] > dep[b])
        swap(a, b);
    for (int i = 18; i > -1; i--)
        if (dep[b] - (1 << i) >= dep[a])
            b = dp[b][i];
    if (b == a)
        return a;
    for (int i = 18; i > -1; i--)
    {
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main()
{
    if (fopen("PIRATE.INP", "r"))
    {
        freopen("PIRATE.INP", "r", stdin);
        freopen("PIRATE.OUT", "w", stdout);
    }
    scanf("%d", &n);
    dp = vector<vector<int>>(n + 1, vector<int>(19));
    from_root = vector<vector<int>>(2, vector<int>(n + 1));
    dep = vector<int>(n + 1);
    adj = vector<vector<pair<int, pp>>>(n + 1);
    ll sumAll = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, a, b;
        scanf("%d%d%d%d", &u, &v, &a, &b);
        adj[u].push_back({v, {a, b}});
        adj[v].push_back({u, {b, a}});
        sumAll += a + b;
    }
    dfs(1);
    scanf("%d", &q);
    for (int j = 1; j < 19; j++)
        for (int i = 1; i <= n; i++)
            if (dp[i][j - 1])
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
    while (q--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int lc = lca(u, v);
        printf("%lld\n", sumAll - from_root[1][v] + from_root[1][lc] - from_root[0][u] + from_root[0][lc]);
    }
    return 0;
}