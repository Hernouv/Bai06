#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, q, vst[N], par[N];
int dx[] = {0, 1, 1, 0};
int dy[] = {1, 1, 0, 0};
vector<int> k[N];
int64_t dp[N][2][2][2][2];
pair<int, int> D;
void dfs(int u, int p)
{
    vst[u] = 1;
    for (auto v : k[u])
    {
        if (v == p)
            continue;
        if (!vst[v])
        {
            dfs(v, u);
        }
        else
        {
            D = {u, v};
        }
    }
}
int64_t calc(int u, int c, int p, int rt, int sp)
{
    if (u == D.second && c != sp)
        return 1e9;
    if (u == D.second && rt && p)
        return 1e9;
    if (dp[u][c][p][rt][sp] != -1)
        return dp[u][c][p][rt][sp];
    int64_t temp = c;
    for (auto v : k[u])
    {
        if (v == par[u])
            continue;
        par[v] = u;
        temp += calc(v, 0, c, rt, sp);
    }
    if (p || (D.second == u && rt))
    {
        return dp[u][c][p][rt][sp] = temp;
    }
    else
    {
        int64_t K = 1e9;
        for (auto v : k[u])
        {
            if (v == par[u])
                continue;
            K = min(K, temp + calc(v, 1, c, rt, sp) - calc(v, 0, c, rt, sp));
        }
        return dp[u][c][p][rt][sp] = K;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    dfs(1, 1);
    memset(dp, -1, sizeof(dp));
    int64_t res = 1e9;
    par[D.first] = D.second;
    for (auto it = k[D.second].begin(); it != k[D.second].end();)
    {
        if (*it == D.first)
        {
            it = k[D.second].erase(it);
        }
        else
            it++;
    }
    for (int i = 0; i <= 3; i++)
    {
        res = min(res, calc(D.first, dx[i], dy[i], dx[i], dy[i]));
    }
    if (res < 1e9)
        cout << res << " ";
    else
        cout << -1;
}