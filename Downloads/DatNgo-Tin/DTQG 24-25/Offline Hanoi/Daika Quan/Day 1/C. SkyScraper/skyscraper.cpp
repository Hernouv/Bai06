#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e6 + 10;

bool afloat[nmax];
ii tower[nmax];
int n, d;
int t;

inline bool cond(ii &a, ii &b)
{
    if (a.fi == b.fi)
        return a.se < b.se;
    return (a.fi < b.fi);
}

void not_main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tower[i].fi;
        tower[i].se = i;
        afloat[i] = true;
    }
    afloat[0] = afloat[n + 1] = false;
    sort(tower + 1, tower + n + 1, cond);
    int del_id = 1;
    int cnt = 1;
    for (int i = 1; i <= d; ++i)
    {
        cin >> t;
        while (del_id <= n and tower[del_id].fi <= t)
        {
            if (afloat[tower[del_id].se - 1] and afloat[tower[del_id].se + 1])
                ++cnt;
            else if (!afloat[tower[del_id].se - 1] and !afloat[tower[del_id].se + 1])
                --cnt;
            afloat[tower[del_id].se] = false;
            ++del_id;
        }
        cout << cnt << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        not_main();
    return 0;
}