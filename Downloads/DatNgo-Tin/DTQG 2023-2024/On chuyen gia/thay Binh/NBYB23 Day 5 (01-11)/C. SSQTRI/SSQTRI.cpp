#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SSQTRI.INP", "r"))
    {
        freopen("SSQTRI.INP", "r", stdin);
        freopen("SSQTRI.OUT", "w", stdout);
    }
    int n, res = 0;
    cin >> n;
    vector<pair<int, int>> vpos(n);
    map<int, vector<int>> x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> vpos[i].first >> vpos[i].second;
        y[vpos[i].first].push_back(vpos[i].second);
        x[vpos[i].second].push_back(vpos[i].first);
    }
    for (int i = 0; i < n; i++)
    {
        if (y[vpos[i].first].size() > 1 and x[vpos[i].second].size() > 1)
        {
            int sum1 = 0, sum2 = 0;
            for (auto iter : y[vpos[i].first])
                sum1 = sum1 + abs(vpos[i].second - iter);
            for (auto iter : x[vpos[i].second])
                sum2 = sum2 + abs(vpos[i].first - iter);
            res = (res + sum1 * sum2) % mod;
        }
    }
    cout << res;
    return 0;
}