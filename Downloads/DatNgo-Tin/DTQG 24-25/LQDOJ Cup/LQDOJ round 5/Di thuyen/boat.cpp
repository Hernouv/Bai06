#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define pb push_back

const int nmax = 5e5 + 10;

int n, m, t;
vector<int> adj[nmax];
int boat[nmax], res = 0;

void not_main()
{
    cin >> n >> m >> t;
    int tu, tv;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv;
        adj[tu].push_back(tv);
        adj[tv].push_back(tu);
    }
    for (int i = 1; i <= t; ++i)
    {
        cin >> tu >> tv;
        boat[tu]++;
        for (int v : adj[tv])
            maximize(boat[v], boat[tu]);
    }
    for (int i = 1; i <= n; ++i)
        maximize(res, boat[i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("boat.inp", "r"))
    {
        freopen("boat.inp", "r", stdin);
        freopen("boat.out", "w", stdout);
    }
    not_main();
    return 0;
}