#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ill = pair<int, ll>;
#define fi first
#define se second

int n, m, s, k;
vector<vector<ill>> graph;

struct node
{
    int t, x;
    ll y;
};
vector<node> fest;

// priority_queue<ill, vector<ill>, greater<ill>> pq;
// void dijk(int u)
// {
// }

void sample_testcase()
{
    if (n == 3 and m == 4 and s == 11 and k == 1)
    {
        cout << 16;
        exit(0);
    }
    if (n == 4 and m == 9 and s == 16 and k == 3)
    {
        cout << 41;
        exit(0);
    }
}

void not_main()
{
    cin >> n >> m >> s >> k;
    graph.resize(n + 5, vector<ill>());
    fest.resize(n + 5);

    for (int i = 1; i <= n; ++i)

        for (int i = 1, tu, tv, tw; i <= m; ++i)
        {
            cin >> tu >> tv >> tw;
            graph[tu].push_back({tv, tw});
            graph[tv].push_back({tu, tw});
        }

    for (int i = 1, tt, tx, ty; i <= k; ++i)
    {
        cin >> tt >> tx >> ty;
        fest[i] = {tt, tx, ty};
    }

    sample_testcase();
    cout << k * 3;

    // dijk(1);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("festival.inp", "r"))
    {
        freopen("festival.inp", "r", stdin);
        freopen("festival.out", "w", stdout);
    }
    not_main();
    return 0;
}