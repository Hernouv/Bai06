#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n;
ll b;
ill galaxies[nmax];
ll res = 0;

void not_main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
        cin >> galaxies[i].fi >> galaxies[i].se;
    sort(galaxies + 1, galaxies + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ll tmp = min(galaxies[i].se, 1LL * b / galaxies[i].fi);
        b -= 1LL * galaxies[i].fi * tmp;
        res += tmp;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("VISIT.INP", "r"))
    {
        freopen("VISIT.INP", "r", stdin);
        freopen("VISIT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}