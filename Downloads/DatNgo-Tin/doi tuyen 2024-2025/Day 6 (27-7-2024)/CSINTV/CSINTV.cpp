#include <bits/stdc++.h>
#define MASK(k) (1LL << (k))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
// #define int long long
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whole(a) a.begin(), a.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define nhl ""

template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 1000005;
const int MOD = 1e9 + 7;

using namespace std;
int n, lis[MAX];
int L[MAX];
pii a[MAX];
int ST[4 * MAX];
int query(int i, int l, int r, int u, int v)
{
    if (r < u || v < l)
        return 0;
    if (u <= l && r <= v)
        return ST[i];
    int mid = (l + r) / 2;
    int lmao1 = query(i * 2, l, mid, u, v);
    int lmao2 = query(i * 2 + 1, mid + 1, r, u, v);
    return max(lmao1, lmao2);
}
void update(int id, int l, int r, int u, int v)
{
    if (r < u || u < l)
        return;
    if (l == r)
        ST[id] = v;
    else
    {
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
    }
}
void process()
{
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1, [](pii x, pii y)
         {
        if(x.fi == y.fi) return x.se > y.se;
        else return x.fi < y.fi; });
    int maxlen = 0;
    int maxa = 0;
    For(i, 1, n) maximize(maxa, a[i].se);
    Fod(i, n, 1)
    {
        L[i] = query(1, 1, maxa, 1, a[i].se);
        maximize(maxlen, L[i] + 1);
        update(1, 1, maxa, a[i].se, L[i] + 1);
    }
    cout << maxlen << '\n';
    int cur = maxlen - 1;
    For(i, 1, n)
    {
        if (L[i] == cur)
        {
            cout << a[i].fi << " " << a[i].se << '\n';
            cur--;
        }
    }
}

signed main()
{
    fastio if (fopen(nhl ".inp", "r"))
    {
        freopen(nhl ".inp", "r", stdin);
        freopen(nhl ".out", "w", stdout);
    }
    int Test = 1;
    while (Test--)
    {
        process();
    }
    return 0;
}