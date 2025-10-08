#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
using pii = pair<int, int>;

#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define REPD(i, n) for (int i = (n); i >= 1; i--)

#define endl '\n'

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

using point = complex<ll>;
ll f(point L, ll x) { return L.real() * x + L.imag(); }

const ll inf = 2e18 + 10;

const int sz = 1e9 + 10;
struct LichaoTree
{
    struct Node
    {
        point line;
        Node *l, *r;

        Node() : line(point(0LL, inf)), l(NULL), r(NULL) {}
    };

    Node *root = new Node();

    void expand(Node *me)
    {
        if (!me->l)
            me->l = new Node();
        if (!me->r)
            me->r = new Node();
    }

    void add_line(Node *me, int lo, int hi, point nw)
    {
        int mid = (lo + hi) >> 1;
        bool c1 = f(nw, lo) < f(me->line, lo);
        bool c2 = f(nw, mid) < f(me->line, mid);
        if (c2)
            swap(me->line, nw);
        if (lo == hi)
            return;

        expand(me);
        if (c1 != c2)
            add_line(me->l, lo, mid, nw);
        else
            add_line(me->r, mid + 1, hi, nw);
    }

    ll query(Node *me, int lo, int hi, int x)
    {
        int mid = (lo + hi) >> 1;
        if (lo == hi)
            return f(me->line, x);

        expand(me);
        if (x < mid)
            return min(f(me->line, x), query(me->l, lo, mid, x));
        else
            return min(f(me->line, x), query(me->r, mid + 1, hi, x));
    }

    void add_line(point nw) { add_line(root, 0, sz, nw); }
    ll query(int x) { return query(root, 0, sz, x); }

} lt;

const int MAXN = 1e5 + 10;

int n, S;
int T[MAXN], F[MAXN];

int dp[MAXN];

void solve()
{
    cin >> n >> S;
    REP(i, n)
    {
        cin >> T[i] >> F[i];
        T[i] += T[i - 1];
        F[i] += F[i - 1];
    }

    REPD(i, n + 1)
    {
        if (i == n + 1)
            dp[i] = 0;
        else
            dp[i] = (S - T[i - 1]) * (F[n] - F[i - 1]) + lt.query(F[n] - F[i - 1]);

        lt.add_line({T[i - 1], dp[i]});
    }

    cout << dp[1];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}