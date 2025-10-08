#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e6 + 5;
const int inf = 2e9 + 5;

int n, m;
int a[nmax], dist[nmax];

priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra()
{
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        ii V = pq.top();
        pq.pop();

        if (V.fi > dist[V.se])
            continue;

        for (int i = 1; i < n; ++i)
        {
            int v = (V.se + a[i]) % a[0];

            if (minimize(dist[v], V.fi + a[i]))
                pq.emplace(dist[v], v);
        }
    }
}

void not_main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < a[0]; ++i)
        dist[i] = inf;
    dijkstra();

    cin >> m;
    int tnum;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tnum;
        if (dist[tnum % a[0]] <= tnum)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}