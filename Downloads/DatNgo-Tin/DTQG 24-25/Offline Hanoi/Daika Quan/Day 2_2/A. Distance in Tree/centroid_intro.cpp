#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

const int nmax = 5e4 + 10;

int n, k;
map<int, ll> cnt[nmax];
vector<int> graph[nmax];
int h[nmax];
ll res = 0;

void dfs0(int par, int u)
{
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        dfs0(u, v);
    }
}

void dfs(int par, int u)
{
    cnt[u][h[u]] = 1;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        dfs(u, v);
        if (cnt[v].size() > cnt[u].size())
            swap(cnt[v], cnt[u]);
        for (pair<int, int> x : cnt[v])
            res += 1LL * cnt[v][x.first] * cnt[u][k + 2 * h[u] - x.first];
        for (pair<int, int> x : cnt[v])
            cnt[u][x.first] += cnt[v][x.first];
    }
}

void not_main()
{
    cin >> n >> k;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    dfs0(0, 1);
    dfs(0, 1);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}