#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 5e5 + 5;

int n;
int grid1[5][nmax], grid2[nmax][5];
ll cnt[3];

int mex(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a and b)
        return 0;
    if (!a and (!b or b == 2))
        return 1;
    if (!a and (b == 1))
        return 2;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> grid1[1][i];
        cnt[grid1[1][i]]++;
    }
    for (int i = 2; i <= n; ++i)
    {
        cin >> grid2[i][1];
        cnt[grid2[i][1]]++;
    }

    for (int i = 1; i <= min(4, n); ++i)
        grid2[1][i] = grid1[1][i];
    for (int i = 2; i <= min(4, n); ++i)
        grid1[i][1] = grid2[i][1];

    for (int i = 2; i <= min(4, n); ++i)
        for (int j = 2; j <= n; ++j)
        {
            grid1[i][j] = mex(grid1[i - 1][j], grid1[i][j - 1]);
            cnt[grid1[i][j]]++;
        }

    if (n <= 4)
    {
        cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2];
        exit(0);
    }

    for (int j = 2; j <= min(4, n); ++j)
        grid2[4][j] = grid1[4][j];

    for (int i = 5; i <= n; ++i)
        for (int j = 2; j <= min(4, n); ++j)
        {
            grid2[i][j] = mex(grid2[i - 1][j], grid2[i][j - 1]);
            cnt[grid2[i][j]]++;
        }

    for (int i = 4; i < n; ++i)
        cnt[grid1[4][i]] += (ll)min(n - 4, n - i);
    for (int i = 5; i < n; ++i)
        cnt[grid2[i][4]] += (ll)min(n - 4, n - i);

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}