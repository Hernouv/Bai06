#include <bits/stdc++.h>
#define MASK(k) (1LL << (k))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define int long long
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
int n, a[MAX];
template <
    class S,                // node data type
    S (*op)(S, S),          // combine 2 nodes
    S (*e)(),               // identity element
    class F,                // lazy propagation tag
    S (*mapping)(F, S),     // apply tag F on a node
    F (*composition)(F, F), // combine 2 tags
    F (*lz_e)()             // identity tag
    >
struct LazySegTree
{
    LazySegTree(int _n, vector<S> &a) : _n(_n)
    {
        st = vector<S>(_n * 4 + 1, e());
        lz = vector<F>(_n * 4 + 1, lz_e());
        if (a.size())
            build(a, 1, 1, _n);
    }

    void build(vector<S> &a, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            st[id] = a[lx];
            return;
        }

        int mid = (lx + rx) / 2;
        build(a, id * 2, lx, mid);
        build(a, id * 2 + 1, mid + 1, rx);

        update(id);
    }

    void apply(int u, int v, F f, int id, int lx, int rx)
    {
        if (u > rx || v < lx)
            return;
        if (u <= lx && v >= rx)
        {
            all_apply(id, f);
            return;
        }
        push(id);

        int mid = (lx + rx) / 2;
        apply(u, v, f, id * 2, lx, mid);
        apply(u, v, f, id * 2 + 1, mid + 1, rx);

        update(id);
    }

    void apply(int u, int v, F f)
    {
        apply(u, v, f, 1, 1, _n);
    }

    S query(int u, int v, int id, int lx, int rx)
    {
        if (u > rx || v < lx)
            return e();
        if (u <= lx && v >= rx)
            return st[id];
        push(id);
        int mid = (lx + rx) / 2;
        return op(query(u, v, id * 2, lx, mid), query(u, v, id * 2 + 1, mid + 1, rx));
    }

    S query(int u, int v)
    {
        return query(u, v, 1, 1, _n);
    }

private:
    int _n;
    vector<S> st;
    vector<F> lz;

    void update(int id)
    {
        st[id] = op(st[2 * id], st[2 * id + 1]);
    }
    void all_apply(int id, F f)
    {
        st[id] = mapping(f, st[id]);
        lz[id] = composition(f, lz[id]);
    }
    void push(int id)
    {
        all_apply(2 * id, lz[id]);
        all_apply(2 * id + 1, lz[id]);
        lz[id] = lz_e();
    }
};
using S = int;
using F = int;

S op(S l, S r) { return S{l + r}; }

S e() { return S{0}; }

S mapping(F f, S s)
{
    return (f + s);
}

F composition(F f, F g) { return F{f + g}; }

F lz_e() { return F{0}; }
void process()
{
    cin >> n;
    For(i, 1, n) cin >> a[i];
    vector<int> tmp(n + 5, 0);
    LazySegTree<S, op, e, F, mapping, composition, lz_e> tree(n, tmp);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll hit = tree.query(i, i);
        if (hit <= a[i] - 1)
        {
            ans += a[i] - hit - 1;
            int r = i + a[i];
            if (r > n)
                r = n;
            tree.apply(i + 2, r, 1);
        }
        else
        {
            int push = hit - (a[i] - 1);
            int r = i + a[i];
            if (r > n)
                r = n;
            tree.apply(i + 2, r, 1);
            tree.apply(i + 1, min(i + 1, n), push);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("trampoline.inp", "r"))
    {
        freopen("trampoline.inp", "r", stdin);
        freopen("trampoline.out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        process();
    }
    return 0;
}