#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second

int s, t, k, p;

struct mat
{
    int x, y;
    ll a[30][30];
};

mat operator*(mat a, mat b)
{
    mat c{a.x, b.y};
    for (int i = 1; i <= c.x; ++i)
        for (int j = 1; j <= c.y; ++j)
            c.a[i][j] = 0ll;
    for (int i = 1; i <= c.x; ++i)
        for (int j = 1; j <= c.y; ++j)
            for (int k = 1; k <= a.y; ++k)
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % p) % p;
    return c;
}

mat power(mat a, int x)
{
    if (x == 1)
        return a;
    mat b = power(a, x / 2);
    return x % 2 ? b * b * a : b * b;
}

mat a, x;
int adj[9][3] = {
    0, 0, 0, 2, 4, 5, 1, 3, 6,
    2, 4, 7, 1, 3, 8, 1, 6, 8,
    2, 5, 7, 3, 6, 8, 4, 5, 7};

int row[9][9];
ii info[30];
ll F[9][9][3];

void not_main()
{
    char c;
    cin >> c;
    s = c - 'A' + 1;
    cin >> c;
    t = c - 'A' + 1;
    cin >> k >> p;

    for (int u = 1; u <= 8; ++u)
        for (int i = 0; i <= 2; ++i)
        {
            int v = adj[u][i];
            row[u][v] = ++row[0][0];
            info[row[0][0]] = {u, v};
        }

    for (int i = 0; i <= 2; ++i)
    {
        int v = adj[s][i];
        F[s][v][1] = 1;
    }

    if (k == 1)
    {
        cout << F[s][t][1];
        return;
    }

    a.x = 24;
    a.y = 1;
    for (int i = 1; i <= a.x; ++i)
    {
        int u = info[i].fi, v = info[i].se;
        a.a[i][1] = F[u][v][1];
    }

    x.x = x.y = 24;
    for (int i = 1; i <= x.x; ++i)
    {
        int v = info[i].fi, g = info[i].se;
        for (int j = 0; j <= 2; ++j)
        {
            int u = adj[v][j];
            if (u == g)
                continue;
            x.a[i][row[u][v]] = 1;
        }
    }

    a = power(x, k - 1) * a;

    ll ans = 0ll;
    for (int i = 0; i <= 2; ++i)
    {
        int u = adj[t][i];
        ans = (ans + a.a[row[u][t]][1]) % p;
    }
    cout << ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}