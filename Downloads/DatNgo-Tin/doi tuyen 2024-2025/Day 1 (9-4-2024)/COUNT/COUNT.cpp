#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;

long long arr[nmax], accum_sum[nmax], arr_sum_bythird, temp_sum;
long long res;
int n;
vector<int> res_i, res_j;

int res_i_sz, prev_val;
int search(int val)
{
    if (prev_val == res_i_sz)
        return prev_val;
    if (res_i[0] > val)
        return 0;
    while (res_i[prev_val] < val and prev_val < res_i_sz)
        ++prev_val;
    return prev_val;
}

void not_main()
{
    cin >> n;
    bool all_zero = true;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        accum_sum[i] = accum_sum[i - 1] + arr[i];
        arr_sum_bythird += arr[i];
        if (arr[i])
            all_zero = false;
    }

    if (n <= 2 or arr_sum_bythird % 3)
    {
        cout << 0;
        return;
    }

    if (all_zero)
    {
        n -= 2;
        cout << n * (n - 1) / 2;
        return;
    }

    arr_sum_bythird /= 3;

    for (int i = 1; i < n - 1; ++i)
        if (accum_sum[i] == arr_sum_bythird)
            res_i.push_back(i);
    res_i_sz = res_i.size();

    arr_sum_bythird *= 2;
    for (int i = 2; i < n; ++i)
        if (accum_sum[i] == arr_sum_bythird)
            res_j.push_back(i);

    for (int x : res_j)
        res += search(x);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("COUNT.INP", "r"))
    {
        freopen("COUNT.INP", "r", stdin);
        freopen("COUNT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}