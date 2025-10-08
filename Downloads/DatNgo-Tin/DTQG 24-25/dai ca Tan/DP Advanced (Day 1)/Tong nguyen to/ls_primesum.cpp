#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

bool nerastos[2000010];
void sieve()
{
    nerastos[0] = true;
    nerastos[1] = true;
    for (int i = 2; i * i <= 2000005; ++i)
        if (!nerastos[i])
            for (int j = i * i; j <= 2000005; j += i)
                nerastos[j] = true;
}

int a[5010], n;
int dp[5010], res;

void not_main()
{
    sieve();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        if (!nerastos[a[i]])
            dp[i] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = i - 1; j >= 1; --j)
        {
            if (j + 1 < dp[i])
                break;
            if (!nerastos[a[i] + a[j]])
                maximize(dp[i], (dp[j] ? dp[j] + 1 : 2));
        }

    for (int i = n; i >= 1; --i)
    {
        maximize(res, dp[i]);
        if (i < res)
            break;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}