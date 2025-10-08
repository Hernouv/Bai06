#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2][1000];
int n, e;

void not_main()
{
    cin >> e >> n;
    int s = 1, d = 0;
    while (true)
    {
        for (int i = 1; i <= e; ++i)
        {
            dp[d][i] = dp[1 - d][i - 1] + dp[1 - d][i] + 1;
            if (dp[d][i] >= n)
            {
                cout << s;
                exit(0);
            }
        }
        ++s;
        d = 1 - d;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}