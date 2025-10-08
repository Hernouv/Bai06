#include <bits/stdc++.h>
using namespace std;

int t, n, m, l, r;
long long arr[200000];
long long dp[200000];
int cnt[200000];
set<long long> distinct;

void reset()
{
    for (int i = 1; i <= m; ++i)
        cnt[i] = 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n >> m >> l >> r;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        if (l == r and (l == 1 or l == m))
            cout << 1 << '\n';
        else
        {
            if (i >= 2)
                reset();
            int st = 1;
            while (distinct.size() < l)
            {
                dp[st] = 0;
                distinct.insert(arr[st++]);
            }
            st--;
            dp[st] = 1;
            int st2 = st + 1;
            while (true)
            {
                distinct.insert(arr[st2]);
                if (distinct.size() > r)
                    break;
                dp[st2] = 1;
                st2++;
            }
            for (int j = st + 1; j <= n; ++j)
            {
                int backtrace = j;
                set<long long> temp_distinct;
                while (temp_distinct.size() < l)
                    temp_distinct.insert(arr[backtrace--]);
                while (backtrace >= st)
                {
                    dp[j] += dp[backtrace];
                    temp_distinct.insert(arr[backtrace]);
                    if (temp_distinct.size() > r)
                        break;
                    backtrace--;
                }
            }
            cout << dp[n] % 918052004;
            cout << '\n';
        }
    }
    return 0;
}