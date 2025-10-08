#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n, t;
vector<ll> lim[nmax];

ll res = 0;

struct cond
{
    bool operator()(lli &a, lli &b)
    {
        if (a.fi == b.fi)
            return a.se < b.se;
        return (a.fi < b.fi);
    }
};

void not_main()
{
    cin >> n >> t;
    ll tv;
    int lt;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tv >> lt;
        lim[lt].push_back(tv);
    }

    priority_queue<lli, vector<lli>, cond> pq;
    for (int i = t; i >= 0; --i)
    {
        for (ll v : lim[i])
            pq.emplace(v, i);
        if (pq.empty())
            continue;
        lli P = pq.top();
        pq.pop();
        res += P.fi;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}