#include <bits/stdc++.h>
using namespace std;

#define N 101
#define FOR(i, l, r) for (int i = l; i < r; i++)

bool a[N][N];
int m, n, deg[N], connect[N], res = 0, odd = 0, even = 0, cnt = 0;

void dfs(int u)
{
    connect[u] = cnt;
    FOR(v, 0, m + 1)
    if (!connect[v] and a[u][v])
        dfs(v);
}

void not_main()
{
    cin >> m >> n;
    memset(a, 1, sizeof a);
    fill_n(deg, m + 1, m + 2);
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 0;
        deg[u]--, deg[v]--;
    }

    memset(connect, 0, sizeof connect);
    for (int u = 0; u <= m; ++u)
    {
        if (!connect[u])
        {
            ++cnt;
            dfs(u);
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        odd = even = 0;
        for (int u = 0; u <= m; ++u)
        {
            if (connect[u] == i)
            {
                odd += deg[u] & 1;
                even += (!(deg[u] & 1) and deg[u] > 0);
            }
        }
        if (!odd)
            res += even > 0;
        else
            res += odd >> 1;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}