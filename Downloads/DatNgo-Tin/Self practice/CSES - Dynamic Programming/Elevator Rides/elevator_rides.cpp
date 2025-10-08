#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const long long outbound = 1e9;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

int n, x;

void not_main()
{
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    vector<ii> dp(1 << n, {outbound, outbound});
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        for (int bit = 0; bit < n; ++bit)
            if ((1 << bit) & mask)
            {
                int space_taken = dp[mask ^ (1 << bit)].se;
                if (space_taken + w[bit] <= x)
                    minimize(dp[mask], {dp[mask ^ (1 << bit)].fi, space_taken + w[bit]});
                else
                    minimize(dp[mask], {dp[mask ^ (1 << bit)].fi + 1, w[bit]});
            }
    }
    cout << dp[(1 << n) - 1].fi;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}