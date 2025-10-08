#include <bits/stdc++.h>
using namespace std;

bool dp[40001];
int arr[201];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    //   freopen("SEQ.INP", "r", stdin);
    //   freopen("SEQ.OUT", "w", stdout);
    int n, rq_sum;
    cin >> n >> rq_sum;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    dp[0] = true;
    for (int i = 0; i <= n; ++i)
        for (int j = rq_sum; j >= arr[i]; --j)
            if (dp[j - arr[i]])
                dp[j] = true;
    if (dp[rq_sum])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}