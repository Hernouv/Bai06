#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 5e5 + 5;
int n;
int c[N], a[N], res[N], cnt[N], sum[N], mx;
int tin[N], tout[N], sz[N], now;
vector<int> g[N];

void pre_dfs(int u, int p)
{
    tin[u] = ++now;
    a[now] = c[u];
    sz[u] = 1;
    for (int v : g[u])
        if (v != p)
        {
            pre_dfs(v, u);
            sz[u] += sz[v];
        }
    tout[u] = now;
}

void add(int x)
{
    cnt[x]++;
    if (sum[cnt[x]] == 0)
        mx++;
    sum[cnt[x]] += x;
}

void dec(int x)
{
    sum[cnt[x]] -= x;
    if (sum[cnt[x]] == 0)
        mx--;
    cnt[x]--;
}

void dfs(int u, int p, bool keep)
{
    int mxChild = -1, bigChild = -1;

    for (int v : g[u])
        if (v != p and sz[v] > mxChild)
        {
            mxChild = sz[v];
            bigChild = v;
        }

    for (int v : g[u])
        if (v != p and v != bigChild)
            dfs(v, u, 0);
    if (bigChild != -1)
        dfs(bigChild, u, 1);

    add(c[u]);
    for (int v : g[u])
        if (v != p and v != bigChild)
        {
            for (int i = tin[v]; i <= tout[v]; i++)
                add(a[i]);
        }
    res[u] = sum[mx];

    if (!keep)
    {
        for (int i = tin[u]; i <= tout[u]; i++)
            dec(a[i]);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    pre_dfs(1, 0);
    dfs(1, 0, 0);

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}
