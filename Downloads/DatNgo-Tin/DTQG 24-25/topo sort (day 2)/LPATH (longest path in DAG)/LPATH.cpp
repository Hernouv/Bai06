#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;

int n, m;
vector<int> graph[nmax];
int degIn[nmax];
queue<int> proc;
vector<int> topolist;
int dist[nmax];

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        ++degIn[b];
    }

    for (int i = 1; i <= n; ++i)
        if (!degIn[i])
        {
            proc.push(i);
            dist[i] = 0;
        }
    while (!proc.empty())
    {
        int u = proc.front();
        proc.pop();
        topolist.push_back(u);
        for (int v : graph[u])
        {
            --degIn[v];
            dist[v] = dist[u] + 1;
            if (!degIn[v])
                proc.push(v);
        }
    }

    int res = 0;
    for (int i = n; i >= 1; --i)
        maximize(res, dist[i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("IOI.INP", "r"))
    {
        freopen("IOI.INP", "r", stdin);
        freopen("IOI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}