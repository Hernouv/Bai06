#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 5e5 + 5;
int n;
int a[N], minv[N], maxv[N];
int res[N];
vector<int> g[N];

void dfs(int u, int p)
{
    minv[u] = 1e9 + 7, maxv[u] = -1;
    int cnt = 0;
    for (int v : g[u])
        if (v != p)
        {
            cnt++;
            dfs(v, u);
            maxv[u] = max(maxv[u], maxv[v]);
            minv[u] = min(minv[u], minv[v]);
        }

    maxv[u] = max(maxv[u], a[u]);
    minv[u] = min(minv[u], a[u]);
    if (!cnt)
    {
        res[u] = -1;
        return;
    }
    res[u] = maxv[u] - minv[u];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
}
