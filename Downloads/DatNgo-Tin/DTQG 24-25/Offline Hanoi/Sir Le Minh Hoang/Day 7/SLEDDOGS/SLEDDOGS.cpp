#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 1e5 + 10;

int n;
ll k;
ll w1[nmax], w2[nmax];
ll res = 0;

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w1[i];
        res += (w1[i] / k) + bool(w1[i] % k);
        if (w1[i] % k)
            w1[i] = k - (w1[i] % k);
        else
            w1[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> w2[i];
        res += (w2[i] / k) + bool(w2[i] % k);
        if (w2[i] % k)
            w2[i] = k - (w2[i] % k);
        else
            w2[i] = 0;
    }
    sort(w1 + 1, w1 + n + 1);
    sort(w2 + 1, w2 + n + 1);
    int id = n;
    for (int i = 1; i <= n; ++i)
    {
        if (w1[i] + w2[id] >= k)
        {
            --res;
            --id;
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SLEDDOGS.INP", "r"))
    {
        freopen("SLEDDOGS.INP", "r", stdin);
        freopen("SLEDDOGS.OUT", "w", stdout);
    }
    not_main();
    return 0;
}