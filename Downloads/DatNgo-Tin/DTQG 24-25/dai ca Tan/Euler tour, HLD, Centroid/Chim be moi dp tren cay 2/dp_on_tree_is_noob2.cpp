#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
vector<vector<int>> edge, weight;
vector<ll> dp, subtree, sum, sqsum;
vector<bool> flag;
ll ans = 0;

ll modpow(ll x, ll y)
{
    ll ret = 1;
    while (y)
    {
        if (y & 1)
        {
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return ret;
}

void dfs(int now)
{
    flag[now] = 1;
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        ll w = weight[now][i];
        if (flag[next])
            continue;

        dfs(next);
        subtree[now] += subtree[next];
        dp[now] += dp[next] + subtree[next] * w % mod * w % mod + sum[next] * w % mod * 2 % mod;
        dp[now] %= mod;
        sum[now] += sum[next] + w * subtree[next] % mod;
        sum[now] %= mod;
    }
}

void reroot(int now)
{
    flag[now] = 0;
    ans += dp[now];
    sqsum[now] += dp[now];
    ans %= mod;
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        ll w = weight[now][i];
        if (!flag[next])
            continue;

        ll dp2 = dp[now] - dp[next] - subtree[next] * w % mod * w % mod - sum[next] * w % mod * 2 % mod;
        dp2 %= mod;
        if (dp2 < 0)
            dp2 += mod;

        ll sum2 = sum[now] - sum[next] - w * subtree[next] % mod;
        sum2 %= mod;
        if (sum2 < 0)
            sum2 += mod;

        ll subtree2 = subtree[now] - subtree[next];

        dp[next] += dp2 + subtree2 * w % mod * w % mod + sum2 * w % mod * 2 % mod;
        dp[next] %= mod;
        sum[next] += sum2 + w * subtree2 % mod;
        sum[next] %= mod;
        subtree[next] += subtree2;
        reroot(next);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;
    edge.resize(N);
    weight.resize(N);
    dp.resize(N);
    subtree.resize(N, 1);
    sum.resize(N);
    sqsum.resize(N);
    flag.resize(N);
    for (int i = 1; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
        weight[x - 1].push_back(z);
        weight[y - 1].push_back(z);
    }

    dfs(0);
    reroot(0);

    for (int i = 0; i < N; ++i)
        cout << sqsum[i] << '\n';
    // ans *= modpow(2, mod - 2);
    // ans %= mod;
    // cout << ans << '\n';
}