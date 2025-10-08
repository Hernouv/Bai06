#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e4 + 10;
int n;
long long p, a[nmax];
long long dp[nmax];
int prev_hotel[nmax];

void not_main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1LL * (a[i] - p) * (a[i] - p);
        for (int j = i - 1; j >= 1; --j)
            if (minimize(dp[i], dp[j] + 1LL * (a[i] - a[j] - p) * (a[i] - a[j] - p)))
                prev_hotel[i] = j;
    }

    cout << dp[n] << '\n';
    stack<int> journey;

    int backtrack = n;
    while (backtrack)
    {
        journey.push(backtrack);
        backtrack = prev_hotel[backtrack];
    }

    cout << journey.size() << '\n';
    while (!journey.empty())
    {
        cout << journey.top() << ' ';
        journey.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TOURISM.INP", "r"))
    {
        freopen("TOURISM.INP", "r", stdin);
        freopen("TOURISM.OUT", "w", stdout);
    }
    not_main();
    return 0;
}