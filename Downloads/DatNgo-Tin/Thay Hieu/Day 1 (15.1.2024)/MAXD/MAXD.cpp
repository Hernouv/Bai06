#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n, m;
ii segments[nmax];

bool check(int inp)
{
    ll pos = segments[1].fi;
    int cnt = 1;
    for (int i = 1; i <= m; ++i)
    {
        while (pos + inp <= segments[i].se)
        {
            pos = max(pos + inp, (ll)segments[i].fi);
            ++cnt;
            if (cnt >= n)
                return 1;
        }
    }
    return 0;
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> segments[i].fi >> segments[i].se;
    sort(segments + 1, segments + m + 1);

    int l = 0;
    int r = 2e9;

    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}