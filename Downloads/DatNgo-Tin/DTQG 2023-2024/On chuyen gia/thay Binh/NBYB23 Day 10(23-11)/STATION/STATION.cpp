#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

const int MAXN = 3000 + 10;

int n;
bitset<MAXN> a[MAXN];

void not_main()
{
    cin >> n;
    REP(i, n)
    cin >> a[i];

    auto nC2 = [](int x)
    {
        return x * (x - 1) / 2;
    };

    int ans = 0;
    REP(i, n)
    FOR(j, i + 1, n)
    {
        auto cur = a[i] & a[j];
        int cnt = cur.count();
        ans += nC2(cnt);
    }

    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}