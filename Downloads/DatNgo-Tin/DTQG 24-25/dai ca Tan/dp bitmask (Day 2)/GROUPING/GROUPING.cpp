#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define int long long
const int nmax = 17;
const int outbound = 1e9 + 10;

int n;
int val[nmax][nmax];
vector<int> premsk[nmax];
int dp[(1 << nmax)], c[(1 << nmax)];

void initial_set()
{
    for (int i = 1; i < (1 << n); ++i)
    {
        premsk[__builtin_popcount(i)].push_back(i);
        dp[i] = -outbound;
    }

    premsk[0].push_back(0);
    for (int i = 0; i < n; ++i)
        dp[(1 << i)] = 0;

    for (int i = 2; i <= n; ++i)
        for (int m : premsk[i])
        {
            vector<int> bit1;
            for (int it = 0; it < n; ++it)
                if ((m >> it) & 1)
                    bit1.push_back(it);

            c[m] = c[m - (1 << bit1[0])];
            for (int x : bit1)
                c[m] += val[x][bit1[0]];
        }
}

void not_main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> val[i][j];

    initial_set();

    for (int i = 2; i <= n; ++i)
    {
        for (int m : premsk[i])
        {
            dp[m] = -outbound;
            for (int sm = m; sm; sm = (sm - 1) & m)
                maximize(dp[m], dp[m - sm] + c[sm]);
        }
    }
    cout << dp[(1 << n) - 1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}