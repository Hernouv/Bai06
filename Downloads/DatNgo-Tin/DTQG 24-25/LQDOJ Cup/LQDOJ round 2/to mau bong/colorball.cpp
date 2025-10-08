#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
#define fi first
#define se second

const int nmax = 2e5 + 10;

vector<ii> baals;
bool blue[nmax], red[nmax], blue2[nmax], red2[nmax];
ll maxR, maxB, minR, minB, minR2, minB2;
int n;
int sz;

inline bool cmp(const ii &a, const ii &b)
{
    if (a.se == b.se)
        return a.fi < b.fi;
    return (a.se > b.se);
}

inline bool cmp2(const ii &a, const ii &b)
{
    if (a.se == b.se)
        return a.fi < b.fi;
    return (a.se < b.se);
}

ll out1()
{
    maxR = baals[0].se;
    int separator, cntR = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (!red[baals[i].fi])
        {
            red[baals[i].fi] = true;
            red2[baals[i].fi] = true;
            ++cntR;
        }
        else
        {
            maxB = baals[i].se;
            blue[baals[i].fi] = true;
            blue2[baals[i].fi] = true;
            separator = i;
            break;
        }
    }

    if (cntR == n)
    {
        minR = baals[n - 1].se;
        minB = baals[sz - 1].se;
        ll res = 1LL * (maxR - minR) * (maxB - minB);
        return res;
    }

    for (int i = sz - 1; i > separator; --i)
    {
        if (!blue[baals[i].fi])
        {
            blue[baals[i].fi] = true;
            if (!minB)
                minB = baals[i].se;
        }
        else if (!red[baals[i].fi])
        {
            red[baals[i].fi] = true;
            if (!minR)
                minR = baals[i].se;
        }
        if (minR and minB)
            break;
    }
    for (int i = sz - 1; i > separator; --i)
    {
        if (!red2[baals[i].fi])
        {
            red2[baals[i].fi] = true;
            if (!minR2)
                minR2 = baals[i].se;
        }
        else if (!blue2[baals[i].fi])
        {
            blue2[baals[i].fi] = true;
            if (!minB2)
                minB2 = baals[i].se;
        }
        if (minR2 and minB2)
            break;
    }
    ll res = 1LL * (maxR - minR) * (maxB - minB);
    res = min(res, 1LL * (maxR - minR2) * (maxB - minB2));
    return res;
}

void not_main()
{
    cin >> n;
    int t1, t2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t1 >> t2;
        baals.emplace_back(i, t1);
        baals.emplace_back(i, t2);
    }
    sort(baals.begin(), baals.end(), cmp);
    sz = baals.size();
    ll ret = out1();
    sort(baals.begin(), baals.end(), cmp2);
    memset(blue, 0, sizeof blue);
    memset(blue2, 0, sizeof blue2);
    memset(red, 0, sizeof red);
    memset(red2, 0, sizeof red2);
    maxR = 0, maxB = 0, minR = 0, minB = 0, minR2 = 0, minB2 = 0;
    ret = min(ret, out1());
    cout << ret;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("colorball.inp", "r"))
    {
        freopen("colorball.inp", "r", stdin);
        freopen("colorball.out", "w", stdout);
    }
    not_main();
    return 0;
}
