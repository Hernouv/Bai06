#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 1e5 + 10;

int n;
ll accum[nmax];
int a[nmax];
ll w[nmax];
ll segg[4 * nmax];
ll res = 0;

void update(int pos, ll val, int id = 1, int l = 1, int r = nmax - 9)
{
    if (l > pos or r < pos)
        return;

    if (l == r)
    {
        maximize(segg[id], val);
        return;
    }
    int mid = (l + r) / 2;
    update(pos, val, id * 2, l, mid);
    update(pos, val, id * 2 + 1, mid + 1, r);
    segg[id] = max(segg[id * 2], segg[id * 2 + 1]);
}

ll getMax(int L, int R, int id = 1, int l = 1, int r = nmax - 9)
{
    if (r < L or l > R)
        return 0;
    if (L <= l and r <= R)
        return segg[id];
    int mid = (l + r) / 2;
    ll t1 = getMax(L, R, id * 2, l, mid);
    ll t2 = getMax(L, R, id * 2 + 1, mid + 1, r);
    return max(t1, t2);
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    for (int i = 1; i <= n; ++i)
    {
        ll tmp = getMax(1, a[i] - 1) + w[i];
        maximize(res, tmp);
        update(a[i], tmp);
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ISS.INP", "r"))
    {
        freopen("ISS.INP", "r", stdin);
        freopen("ISS.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
