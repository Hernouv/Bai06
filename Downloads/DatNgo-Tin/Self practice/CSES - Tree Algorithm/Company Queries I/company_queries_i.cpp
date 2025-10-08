#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
int ancestor[18][nmax];
int n, q;

void binaryAncestor()
{
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
}

int find_ancestor(int x, int k)
{
    for (int i = 0; (1 << i) <= k; ++i)
    {
        if ((k >> i) & 1)
            x = ancestor[i][x];
    }
    return x;
}

void not_main()
{
    cin >> n >> q;
    int e;
    for (int i = 2; i <= n; ++i)
    {
        cin >> e;
        ancestor[0][i] = e;
    }
    binaryAncestor();

    int x, k;
    for (int i = 1; i <= q; ++i)
    {
        cin >> x >> k;
        int query_par = find_ancestor(x, k);
        cout << (query_par == 0 ? -1 : query_par) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}