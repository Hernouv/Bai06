#include <bits/stdc++.h>
using namespace std;

long long grid[102][102];
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("Taydong.inp", "r", stdin);
    // freopen("Taydong.out", "w", stdout);
    //  setVal
    for (int j = 1; j < 102; ++j)
        grid[0][j] = 1e5;
    for (int i = 0; i < 102; ++i)
        grid[i][0] = 0;

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    for (int j = 1; j < 102; ++j)
        grid[m + 1][j] = 1e5;

    // mincost trace
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= m; ++i)
            grid[i][j] = min({grid[i + 1][j - 1], grid[i][j - 1], grid[i - 1][j - 1]}) + grid[i][j];

    long long res = 1e18;
    int par;
    for (int i = 1; i <= m; ++i)
        if (res > grid[i][n])
        {
            res = grid[i][n];
            par = i;
        }
    cout << res << '\n';

    // trace path
    stack<int> seq;
    int j = n;
    while (j)
    {
        seq.push(par);
        pair<int, int> trace = {par, grid[par - 1][j - 1]};
        par--;
        for (int t = par; t <= par + 1; ++t)
            if (trace.second > grid[t][j - 1])
            {
                par = t;
                trace.second = grid[t][j - 1];
            }
        j--;
    }
    while (!seq.empty())
    {
        int t = seq.top();
        cout << t << '\n';
        seq.pop();
    }
    return 0;
}
/*
5 5
9  7  3  8  5
2  11 1  4  10
5  15 8  2  1
9  8  3  2  9
12 16 7  8  2

*/