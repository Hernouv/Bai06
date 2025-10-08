#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
const int nmax = 2e5 + 10;

int n, c, t, sz;
ll a[nmax];
vector<pair<ll, int>> cost_compress;
#define fi first
#define se second

bool valid()
{
    ll tsum = 0;
    for (int i = 1; i <= n; ++i)
        tsum += a[i];
    if (tsum < 0)
        return false;
    return true;
}

int spTable[18][nmax];
void construct()
{
    for (int i = 1; i <= sz; ++i)
        cost_compress[i].fi += cost_compress[i - 1].fi;

    for (int i = 1; i <= sz; ++i)
        spTable[0][i] = cost_compress[i].fi;
    for (int i = 1; (1 << i) <= sz; ++i)
        for (int j = 1; j <= n - (1 << i) + 1; ++j)
            spTable[i][j] = min(spTable[i - 1][j], spTable[i - 1][j + (1 << (i - 1))]);
}

ll val(int pos)
{
    return cost_compress[pos].fi - cost_compress[pos - 1].fi;
}

ll getMin(int l, int r)
{
    int t = __lg(r - l + 1);
    return min(spTable[t][l], spTable[t][r - (1 << t) + 1]);
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c >> t;
        a[i] = t - c;
    }
    a[n + 1] = a[n] * (-1);

    if (!valid())
    {
        cout << -1;
        return;
    }

    cost_compress.emplace_back(0, 0);
    ll tmp = 0, pos = 1;
    for (int i = 1; i <= n; ++i)
    {
        ll mul = a[i] * a[i + 1];
        tmp += a[i];
        if (mul < 0 or (mul == 0 and a[i] + a[i + 1] < 0))
        {
            cost_compress.emplace_back(tmp, pos);
            tmp = 0;
            pos = i + 1;
        }
    }
    sz = cost_compress.size() - 1;
    construct();

    for (int i = 1; i <= sz; ++i)
        if (val(i) > 0)
        {
            ll MinVal;
            if (i == 1)
                MinVal = getMin(1, sz);
            else
                MinVal = min(getMin(1, i - 1) + cost_compress[sz].fi - cost_compress[i - 1].fi, getMin(i, sz) - cost_compress[i - 1].fi);
            if (MinVal >= 0)
            {
                cout << cost_compress[i].se;
                return;
            }
        }
    cout << -1;
}

int32_t main()
{
    if (fopen("TRAVEL.INP", "r"))
    {
        freopen("TRAVEL.INP", "r", stdin);
        freopen("TRAVEL.OUT", "w", stdout);
    }
    not_main();
    return 0;
}