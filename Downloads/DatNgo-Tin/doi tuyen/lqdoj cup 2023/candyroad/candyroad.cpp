#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long type[200010];
set<long long> distinct_type;
long long n, m;
long long res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("candyroad.inp", "r", stdin);
    freopen("candyroad.out", "w", stdout);
    cin >> n >> m;
    long long sugar_depriv = m * (m + 1) / 2;
    for (int i = 1; i <= n; ++i)
        cin >> type[i];
    for (int l = 1; l <= n; ++l)
    {
        long long sugar_lvl = 0;
        int prev_sz = 0;
        distinct_type.clear();
        for (int m = l; m <= n; ++m)
        {
            distinct_type.insert(type[m]);
            if (distinct_type.size() != prev_sz)
            {
                sugar_lvl += type[m];
                prev_sz = distinct_type.size();
            }
            res += (sugar_depriv - sugar_lvl);
            res %= mod;
        }
    }
    cout << res;
    return 0;
}