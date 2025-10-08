#include <bits/stdc++.h>
using namespace std;

int grid[510][510];
int temp_arr[550];
int n, m;

void reset()
{
    for (int i = 1; i <= n; ++i)
        temp_arr[i] = 0;
}

int kadane()
{
    int ret = INT_MIN;
    int temp_s = 0;
    for (int i = 1; i <= n; ++i)
    {
        temp_s = max(temp_s + temp_arr[i], temp_arr[i]);
        ret = max(ret, temp_s);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> grid[i][j];

    int res = INT_MIN;
    for (int l = 1; l <= m; ++l)
    {
        reset();
        for (int r = l; r <= m; ++r)
        {
            for (int i = 1; i <= n; ++i)
                temp_arr[i] += grid[i][r];
            res = max(res, kadane());
        }
    }
    cout << res;
    return 0;
}