#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;
const int outbound = 1e9 + 7;

int n, k, m;
queue<int> vlist;
bool visited[nmax];
int mindist[nmax];
vector<int> graph[nmax];

void bfs()
{
    while (!vlist.empty())
    {
        int t = vlist.front();
        vlist.pop();
        visited[t] = true;
        for (int v : graph[t])
        {
            if (minimize(mindist[v], mindist[t] + 1))
                vlist.push(v);
        }
    }
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        mindist[i] = outbound;
    int tmp_k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> tmp_k;
        mindist[tmp_k] = 0;
        vlist.push(tmp_k);
    }
    cin >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    for (int i = 1; i <= n; ++i)
        cout << mindist[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("evacuate.inp", "r"))
    {
        freopen("evacuate.inp", "r", stdin);
        freopen("evacuate.out", "w", stdout);
    }
    not_main();
    return 0;
}