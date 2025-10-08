#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 1e5 + 10;
int x[nmax], y[nmax];
vector<ii> timeline;

inline bool cond(ii &a, ii &b)
{
    if (a.fi == b.fi)
        return a.se > b.se;
    return (a.fi < b.fi);
}

int n, k;
long long res = 0;

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= k; ++i)
        cin >> y[i];

    sort(x + 1, x + n + 1);
    sort(y + 1, y + k + 1);
    for (int i = 1; i <= n; ++i)
        timeline.emplace_back(x[i], 1);
    for (int i = 1; i < k; ++i)
    {
        int mid = (y[i] + y[i + 1]) / 2 + 1;
        timeline.emplace_back(mid, 2);
    }
    sort(whole(timeline), cond);
    int it = 1;
    for (ii t : timeline)
    {
        if (t.se == 1)
            res += abs(t.fi - y[it]);
        else if (t.se == 2)
            ++it;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MEOBOX.INP", "r"))
    {
        freopen("MEOBOX.INP", "r", stdin);
        freopen("MEOBOX.OUT", "w", stdout);
    }
    not_main();
    return 0;
}