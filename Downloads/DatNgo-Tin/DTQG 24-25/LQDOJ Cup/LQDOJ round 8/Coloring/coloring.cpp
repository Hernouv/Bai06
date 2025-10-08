#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
int n, m, k;
vector<vector<int>> tree;
vector<ii> queries;
vector<vector<ll>> dp;

void dfs(int node, int parent)
{
    dp[node].assign(k, 1);
    for (int child : tree[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        vector<ll> temp(k, 0);
        for (int c1 = 0; c1 < k; ++c1)
        {
            for (int c2 = 0; c2 < k; ++c2)
            {
                if (c1 != c2)
                {
                    temp[c1] = (temp[c1] + dp[child][c2]) % MOD;
                }
            }
        }
        for (int c = 0; c < k; ++c)
        {
            dp[node][c] = (dp[node][c] * temp[c]) % MOD;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("coloring.inp", "r"))
    {
        freopen("coloring.inp", "r", stdin);
        freopen("coloring.out", "w", stdout);
    }
    cin >> n >> m >> k;
    tree.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<ll>(k, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        queries.push_back({u, v});
    }
    dfs(1, -1);
    ll result = 0;
    for (int c = 0; c < k; ++c)
    {
        result = (result + dp[1][c]) % MOD;
    }
    cout << result / 2 << endl;
    return 0;
}
