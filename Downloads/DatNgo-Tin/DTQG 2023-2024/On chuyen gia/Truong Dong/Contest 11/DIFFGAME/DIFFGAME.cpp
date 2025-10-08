#include <bits/stdc++.h>
using namespace std;

#define int long long

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, true : false; }

int arr[100010], n, m;
int dp[100010];
// set<int> scan;

void not_main()
{
    cin >> n >> m;
    int it = 0, num;
    arr[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        if (num != arr[it])
            arr[++it] = num;
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= it; ++i)
    {
        set<int> scan;
        dp[i] = 1e9;
        for (int j = i; j >= 1; --j)
        {
            scan.insert(arr[j]);
            int sz = scan.size();
            minimize(dp[i], dp[j - 1] + sz * sz);
        }
    }
    cout << dp[it];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}