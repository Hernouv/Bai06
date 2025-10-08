#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const ll mod = 1e9 + 7;
unordered_map<ll, int> val;
vector<lli> query;
vector<lli> ans;

ll tnum;
ll cal(ll num)
{
    if (val[num])
        return val[num];
    if (num == 1)
        return 1;
    if (num % 2)
        return cal(num - 1);
    return val[num] = 1LL * (cal(num - 1) + cal(num / 2)) % mod;
}

void not_main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> tnum;
        query.push_back({tnum, T});
    }
    sort(whole(query), [](lli &a, lli &b)
         { return a.fi < b.fi; });
    for (lli x : query)
        ans.push_back({cal(x.fi), x.se});
    sort(whole(ans), [](lli &a, lli &b)
         { return a.se > b.se; });
    for (lli x : ans)
        cout << x.fi << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BINPAR.INP", "r"))
    {
        freopen("BINPAR.INP", "r", stdin);
        freopen("BINPAR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}