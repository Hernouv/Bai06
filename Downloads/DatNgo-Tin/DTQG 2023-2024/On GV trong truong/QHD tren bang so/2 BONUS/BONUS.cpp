#include <bits/stdc++.h>
using namespace std;

int proc[510][510];
int grid[510][510];
int n, r, k;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("BONUS.INP", "r", stdin);
    // freopen("BONUS.OUT", "w", stdout);
    cin >> n >> r >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> grid[i][j];

    int x, y;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x >> y;
        proc[x][y]++;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            proc[i][j] += proc[i - 1][j] + proc[i][j - 1] - proc[i - 1][j - 1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << proc[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';

    long long res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int u = max(i - r + 1, 1), v = max(j - r + 1, 1);
            int cnt = proc[i][j] - proc[i][v - 1] - proc[u - 1][j] + proc[u - 1][v - 1];
            if (cnt > 0)
                res += grid[i][j];
        }
    }
    cout << res;
    return 0;
}