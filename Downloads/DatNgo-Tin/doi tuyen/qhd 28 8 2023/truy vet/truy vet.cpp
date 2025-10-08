#include <bits/stdc++.h>
using namespace std;

int dp[1002], trace[1002];
int arr[1002];
stack<int> seq;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("LIQ.INP", "r", stdin);
    // freopen("LIQ.OUT", "w", stdout);
    int n;
    cin >> n;
    arr[0] = -1, arr[n + 1] = 1e9;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n + 1; ++i)
    {
        dp[i] = 2, trace[i] = 0;
        for (int j = i - 1; j >= 1; --j)
            if (arr[i] > arr[j] and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1, trace[i] = j;
    }
    cout << dp[n + 1] - 2 << '\n';
    int tr = trace[n + 1];
    while (tr > 0)
    {
        seq.push(tr);
        tr = trace[tr];
    }
    while (!seq.empty())
    {
        cout << arr[seq.top()] << ' ';
        seq.pop();
    }
    return 0;
}
// 13205