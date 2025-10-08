/**
 *  Created at 09:40, Tuesday November 21, 2023
 *  By ms24 <3
 */
#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define task ""
#define ll long long
// #define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }
// #define cerr if (0) cerr
// #define CTIME

const int N = 51;

struct Event
{
    int col, x, val;

    Event() = default;
    Event(int x, int col, int val) : x(x), col(col), val(val) {}

    bool operator<(const Event &other)
    {
        return (x != other.x ? x < other.x : val < other.val);
    }
};

int n, m, nowj, nows;
int q, ans = 0;
ll A, B, C, D;
vector<Event> ev;

struct BIT
{
    int bit[N];

    void update(int x, int val)
    {
        for (; x <= m; x += -x & x)
            bit[x] += val;
    }

    int get(int x)
    {
        int ans = 0;
        for (; x; x -= -x & x)
            ans += bit[x];
        return ans;
    }

    int get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
} bit;

void ttk32()
{
    cin >> n >> m >> q;
    cin >> A >> B >> C >> D;
    cin >> nowj >> nows;
    For(i, 1, q)
    {
        int c, r, l;
        cin >> c >> r >> l;
        ev.pb(Event(r, c, 1));
        ev.pb(Event(r + l, c, -1));
    }
    sort(all(ev));

    int k = 0;
    int lastj = nowj, lasts = nows;
    For(i, 1, n)
    {
        if (i != 1)
        {
            nowj = 1 + (lastj * A + B) % m;
            nows = 1 + (lasts * C + D) % (m - nowj + 1);
        }
        lastj = nowj, lasts = nows;
        int l = nowj, r = nowj + nows - 1;
        for (; k < ev.size() && ev[k].x <= i; ++k)
            bit.update(ev[k].col, ev[k].val);
        ans += bit.get(l, r);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
#ifdef CTIME
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}