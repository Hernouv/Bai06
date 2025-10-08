#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second

int digitSum(int x)
{
    int num = 0;
    while (x > 0)
    {
        num += x % 10;
        x /= 10;
    }
    return num;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int K;
    cin >> K;

    const int INF = 1e9;
    vector<int> dp(K, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int d = 1; d <= 9; ++d)
    {
        int rem = d % K;
        if (dp[rem] > d)
        {
            dp[rem] = d;
            pq.emplace(d, rem);
        }
    }

    while (!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();

        if (curr.fi > dp[curr.se])
            continue;

        for (int d = 0; d <= 9; ++d)
        {
            int new_rem = (curr.se * 10 + d) % K;
            int new_sum = curr.fi + d;
            if (new_sum < dp[new_rem])
            {
                dp[new_rem] = new_sum;
                pq.emplace(new_sum, new_rem);
            }
        }
    }
    cout << dp[0];

    return 0;
}