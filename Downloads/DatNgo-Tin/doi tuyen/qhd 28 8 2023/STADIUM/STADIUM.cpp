#include <bits/stdc++.h>
using namespace std;

pair<int, int> scheme[10001];
map<pair<int, int>, int> dp;
map<pair<int, int>, int> cost;

inline bool byFirst(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("STADIUM.INP", "r", stdin);
    freopen("STADIUM.OUT", "w", stdout);
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        scheme[i] = {a, b};
        cost[{a, b}] = c;
    }
    sort(scheme + 1, scheme + n + 1, byFirst);
    for (int i = 1; i <= n; ++i)
    {
        dp[{scheme[i].first, scheme[i].second}] = cost[{scheme[i].first, scheme[i].second}];
        for (int j = i - 1; j >= 1; --j)
        {
            if (scheme[j].second <= scheme[i].first)
                dp[{scheme[i].first, scheme[i].second}] = max(dp[{scheme[i].first, scheme[i].second}], dp[{scheme[j].first, scheme[j].second}] + cost[{scheme[i].first, scheme[i].second}]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, dp[{scheme[i].first, scheme[i].second}]);
    cout << res;
    return 0;
}