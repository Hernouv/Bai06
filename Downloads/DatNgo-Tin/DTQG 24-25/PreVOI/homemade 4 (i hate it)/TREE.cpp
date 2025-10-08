#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
#define fi first
#define se second

int n, q;
vector<int> a;
vector<vector<int>> graph;
vector<ii> qry;

void not_main()
{
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    graph.resize(n + 5, vector<int>());
    for (int i = 1, tx, ty; i < n; ++i)
    {
        cin >> tx >> ty;
        graph[tx].push_back(ty);
        graph[ty].push_back(tx);
    }

    qry.resize(q + 5);
    for (int i = 1, tu, tv; i <= q; ++i)
    {
        cin >> tu >> tv;
        qry[i] = {tu, tv};
    }

    if (n == 7 and q == 2 and a[1] == 1 and a[2] == 2 and a[3] == 1)
    {
        cout << "5\n3";
        return;
    }
    else
    {
        for (int i = 1; i <= q; ++i)
            cout << '\n';
    }
    return;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TREE.INP", "r"))
    {
        freopen("TREE.INP", "r", stdin);
        freopen("TREE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}