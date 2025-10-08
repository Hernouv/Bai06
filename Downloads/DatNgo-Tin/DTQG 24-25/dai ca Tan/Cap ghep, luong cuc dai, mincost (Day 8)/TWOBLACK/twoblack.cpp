#include <bits/stdc++.h>
using namespace std;

#define inf 1000000

string a[111];
int m, n, c[222][222], f[222][222], S, T, d[222], v[222];

int augment()
{
    queue<int> q;
    for (int i = 1; i <= T; i++)
        d[i] = 0;
    d[S] = S;
    v[S] = inf;
    q.push(S);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= T; i++)
            if (!d[i])
            {
                if (f[x][i] < c[x][i])
                {
                    v[i] = min(v[x], c[x][i] - f[x][i]);
                    q.push(i);
                    d[i] = x;
                    if (i == T)
                        return 1;
                }
                else if (f[i][x])
                {
                    v[i] = min(v[x], f[i][x]);
                    q.push(i);
                    d[i] = -x;
                    if (i == T)
                        return 1;
                }
            }
    }
    return 0;
}

void incFlow()
{
    int delta = v[T], y, x = T;
    while (x != S)
    {
        y = x;
        x = d[y];
        if (x > 0)
            f[x][y] += delta;
        else
            x = -x, f[y][x] -= delta;
    }
}

int maxFlow(int val)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c[i + 1][j + m + 1] = (a[i][j] == '1');
    S = n + m + 1;
    T = S + 1;
    for (int i = 1; i <= m; i++)
        c[S][i] = 2;
    for (int i = 1; i <= n; i++)
        c[m + i][T] = val;
    memset(f, 0, sizeof(f));

    while (augment())
        incFlow();

    int res = 0;
    for (int i = 1; i <= m; i++)
        res += f[S][i];
    return res;
}

void not_main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    int lo = 1, hi = m, ans;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (maxFlow(mid) == m * 2)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }

    cout << ans << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
