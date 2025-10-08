#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 5;
bool done[nmax];
vector<int> g[nmax];
char ans[nmax];
int sz[nmax], maxson[nmax];

int dfs(int u, int fa)
{
    sz[u] = 1;
    maxson[u] = 0;
    for (int i = g[u].size() - 1; i >= 0; --i)
    {
        if (g[u][i] == fa or done[g[u][i]])
            continue;
        dfs(g[u][i], u);
        sz[u] += sz[g[u][i]];
        maxson[u] = max(maxson[u], sz[g[u][i]]);
    }
    return sz[u];
}

int find_root(const int sum, int u, int fa)
{
    int ret = u;
    maxson[u] = max(maxson[u], sum - sz[u]);
    for (int i = g[u].size() - 1; i >= 0; --i)
    {
        if (g[u][i] == fa or done[g[u][i]])
            continue;
        int x = find_root(sum, g[u][i], u);
        if (maxson[x] < maxson[ret])
            ret = x;
    }
    return ret;
}

bool solve(int u, char ch)
{
    int root = find_root(dfs(u, 0), u, 0);
    done[root] = true;
    ans[root] = ch;
    if (ch > 'Z')
        return false;
    for (int i = g[root].size() - 1; i >= 0; --i)
    {
        if (done[g[root][i]])
            continue;
        if (!solve(g[root][i], ch + 1))
            return false;
    }
    return true;
}

void not_main()
{
    int n, u, v;
    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (solve(1, 'A'))
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
    else
        cout << "tandeptraikhoaito";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}