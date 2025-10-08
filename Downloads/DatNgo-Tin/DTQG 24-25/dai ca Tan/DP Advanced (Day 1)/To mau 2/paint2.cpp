#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 1510;
const ll outbound = 1e18;

int m, n;
ll c[nmax][nmax];
ll dp[nmax][nmax];
ll res = outbound;

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    ll v1, v2;
    int p1, p2;
    vector<ill> s;
    for (int j = 1; j <= n; ++j)
        s.emplace_back(j, c[1][j]);
    sort(whole(s), [](ill &a, ill &b)
         { return (a.se < b.se); });
    v1 = s[0].se, p1 = s[0].fi;
    v2 = s[1].se, p2 = s[0].fi;

    for (int i = 1; i <= n; ++i)
        dp[1][i] = c[1][i];
    for (int i = 2; i <= m; ++i)
    {
        vector<ill> s;
        for (int j = 1; j <= n; ++j)
        {
            if (j != p1)
                dp[i][j] = v1 + c[i][j];
            else
                dp[i][j] = v2 + c[i][j];
            s.emplace_back(j, dp[i][j]);
        }
        sort(whole(s), [](ill &a, ill &b)
             { return (a.se < b.se); });
        v1 = s[0].se, p1 = s[0].fi;
        v2 = s[1].se, p2 = s[0].fi;
    }

    for (int i = 1; i <= n; ++i)
        res = min(res, dp[m][i]);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}