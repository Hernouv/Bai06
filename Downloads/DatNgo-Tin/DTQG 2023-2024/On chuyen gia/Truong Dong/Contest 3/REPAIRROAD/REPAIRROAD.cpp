#include <bits/stdc++.h>
using namespace std;

int n;
const long long mod = 1e9 + 7;
vector<int> graph[200010];
int parent[200010];
long long dp[200010];
long long ans[200010];

void dfs(int start)
{
    for (auto v : graph[start])
    {
        if (v != parent[start])
        {
            parent[v] = start;
            dfs(v);
            dp[start] = (dp[start] * (dp[v] + 1)) % mod;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;

    int frm;
    for (int i = 2; i <= n; ++i)
    {
        cin >> frm;
        graph[i].push_back(frm);
        graph[frm].push_back(i);
    }

    parent[1] = 0;
    dfs(1);

    ans[1] = dp[1];
    for (int i = 2; i <= n; ++i)
    {
        int par = parent[i];
        long long t = dp[parent[par]] + 1;
        for (auto v : graph[par])
        {
            if (v != i and v != parent[par])
                t = t * (dp[v] + 1) % mod;
        }
        dp[par] = t;
        ans[i] = dp[i] * (t + 1) % mod;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}