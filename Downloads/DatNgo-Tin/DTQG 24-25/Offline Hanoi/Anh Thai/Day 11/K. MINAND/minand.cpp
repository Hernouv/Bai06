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
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define gqt "b1"

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

const int INF = 2e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 100005;
const int MOD = 1e9 + 7;

using namespace std;
int n, q, a[MAX], st[MAX * 4 + 5], stor[MAX * 4 + 5];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        stor[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
    stor[id] = stor[id * 2] | stor[id * 2 + 1];
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u)
        return;
    if ((stor[id] & val) == 0)
    {
        // cout << l << " " << r << " " << stor[id] << endl;
        // cout << (stor[id] & val) << '\n';
        return;
    }
    if (l == r)
    {
        st[id] &= ~val;
        stor[id] = st[id];
        // cout << l << " " << st[id] << endl;
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
    stor[id] = stor[id * 2] | stor[id * 2 + 1];
}
int query(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return INF;
    if (u <= l && r <= v)
        return st[id];
    int mid = (l + r) >> 1;
    return min(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}
void process()
{
    cin >> n >> q;
    For(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int mask = ~x;
            update(1, 1, n, l, r, mask);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

signed main()
{
    fastio if (fopen(gqt ".inp", "r"))
    {
        freopen(gqt ".inp", "r", stdin);
        freopen(gqt ".out", "w", stdout);
    }
    int Test = 1;
    while (Test--)
    {
        process();
    }
    return 0;
}