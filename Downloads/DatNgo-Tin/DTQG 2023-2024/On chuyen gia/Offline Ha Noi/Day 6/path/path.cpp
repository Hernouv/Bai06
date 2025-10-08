#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 50010;
const int outbound = 1e9 + 7;

int n, m, s;
bitset<N> T[N], L[N];
vector<int> dist_source;
vector<int> f[N], k[N], graph[N];

void dijkstra(vector<int> &dist_source, int s)
{
    if (dist_source.size())
        return;
    dist_source.resize(n + 3, outbound);
    priority_queue<ii, vector<ii>, greater<ii>> scanlist;
    scanlist.push({0, s});
    dist_source[s] = 0;
    L[0][s] = 1;
    For(i, 1, n) T[i][i] = 1;
    while (scanlist.size())
    {
        int dist_u = scanlist.top().first;
        int u = scanlist.top().second;
        scanlist.pop();
        if (dist_u != dist_source[u])
            continue;

        for (int v : graph[u])
        {
            if (minimize(dist_source[v], dist_u + 1))
            {
                T[v] |= T[u];
                L[dist_source[v]][v] = 1;
                scanlist.emplace(dist_source[v], v);
            }
            else if (dist_source[v] == dist_u + 1)
                T[v] |= T[u];
        }
    }
}

int solve(int t, int di)
{
    if (dist_source[t] < di or dist_source[t] >= outbound)
        return 0;
    bitset<N> tmp(L[di] & T[t]);

    int cnt = tmp.count();
    if (cnt > 1)
        return -1;
    return tmp._Find_first();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> s;
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    For(i, 1, n) uni(graph[i]);
    dijkstra(dist_source, s);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
    return 0;
}