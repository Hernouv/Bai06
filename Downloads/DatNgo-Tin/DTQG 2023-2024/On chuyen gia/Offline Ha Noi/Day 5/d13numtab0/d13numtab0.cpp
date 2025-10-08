#include <bits/stdc++.h>
#define pb push_back
#define N 200

using namespace std;

int n, m, dd[N + 2], vet[N + 2], a[N + 2][N + 2], arr[N + 2], oo = (1e9), s, t;
struct cc
{
    int a, b, c;
};
vector<cc> kq;

vector<int> adj[N + 2];
bool BFS()
{
    memset(vet, 0, sizeof(vet));
    memset(dd, 0, sizeof(dd));

    dd[s] = 1;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == t)
            return true;

        for (auto v : adj[u])
        {
            if (!dd[v] && a[u][v] > 0)
            {
                dd[v] = 1;
                vet[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    //    freopen("cow.inp","r",stdin);
    //    freopen("cow.out","w",stdout);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1, x; j <= n; j++)
        {
            cin >> x;
            if (x == 1)
            {
                adj[i].pb(j + n);
                adj[j + n].pb(i);
                a[i][j + n] = oo;
            }
        }
    }

    s = 0;
    for (int i = 1; i <= n; i++)
    {
        adj[s].pb(i);
        adj[i].pb(s);
        a[s][i] += 1;
    }

    t = 2 * n + 1;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        adj[i].pb(t);
        adj[t].pb(i);
        a[i][t] += 1;
    }

    int res = 0;
    while (BFS())
    {
        int c_min = oo;

        for (int v = t; v != s; v = vet[v])
        {
            int u = vet[v];
            c_min = min(c_min, a[u][v]);
        }

        for (int v = t; v != s; v = vet[v])
        {
            int u = vet[v];

            a[u][v] -= c_min;
            a[v][u] += c_min;
        }

        res += c_min;
    }

    if (res != n)
        cout << -1 << "\n";
    else
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = n + 1; v <= 2 * n; v++)
            {
                if (a[v][u] > 0)
                {
                    arr[u] = v;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] != i + n)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (arr[j] == i + n)
                    {
                        swap(arr[i], arr[j]);
                        kq.pb({1, i, j});
                    }
                }
            }
        }
        cout << kq.size() << "\n";
        for (auto x : kq)
        {
            cout << x.a << " " << x.b << " " << x.c << "\n";
        }
    }

    return 0;
}