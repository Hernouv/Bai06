#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

#define ill pair<int, long long>
const long long inf = 1e18;
int n, m, q;
long long dist[1010][1010];
long long mid[1010][1010];
int parent[1010];

void floyd()
{
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (minimize(dist[i][j], dist[i][k] + dist[k][j]))
                    mid[i][j] = k;
}

void printPath(int st, int en)
{
    if (!mid[st][en])
    {
        cout << st << ' ';
        return;
    }
    printPath(st, mid[st][en]);
    printPath(mid[st][en], en);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(dist, inf, sizeof dist);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = inf;

    long long a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    floyd();

    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        if (dist[a][b] >= inf)
            cout << -1 << '\n';
        else
        {
            cout << dist[a][b] << '\n';
            printPath(a, b);
            cout << b << '\n';
        }
    }
    return 0;
}
