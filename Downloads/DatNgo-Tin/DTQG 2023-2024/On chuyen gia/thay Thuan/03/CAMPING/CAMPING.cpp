#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define l2 pair<ll, ll>
#define fi first
#define se second
const int nmax = 1e5 + 10;

long long m, n, k;
l2 bad_ground[nmax];
map<l2, bool> bad_gr;
ll res;

void not_main()
{
    cin >> m >> n >> k;
    res = 1LL * ((m - 1) * n) + (m * (n - 1)) - 4 * k;

    for (int i = 1; i <= k; ++i)
    {
        cin >> bad_ground[i].fi >> bad_ground[i].se;
        bad_gr[bad_ground[i]] = true;
        if (bad_ground[i].fi == 1)
            ++res;
        if (bad_ground[i].fi == m)
            ++res;
        if (bad_ground[i].se == 1)
            ++res;
        if (bad_ground[i].se == n)
            ++res;
        if (bad_gr[{bad_ground[i].fi, bad_ground[i].se - 1}])
            ++res;
        if (bad_gr[{bad_ground[i].fi - 1, bad_ground[i].se}])
            ++res;
    }
    std::cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("camping.inp", "r"))
    {
        freopen("camping.inp", "r", stdin);
        freopen("camping.out", "w", stdout);
    }
    not_main();
    return 0;
}