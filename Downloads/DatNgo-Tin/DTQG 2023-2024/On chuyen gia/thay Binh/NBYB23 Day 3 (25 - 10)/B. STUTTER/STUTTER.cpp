/**
 *  Created at 09:35, Wednesday October 25, 2023
 *  By ms24 <3
 */
#include <bits/stdc++.h>
using namespace std;

#define task "STUTTER"
#define ll long long
#define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;

int n, res = 0;
bool ck[N];
int a[N], b[N], c[N];
int cnt[30], cnt1[30];
vector<int> adj[30];

struct BIT
{
    int bit[N];

    void reset()
    {
        memset(bit, 0, sizeof bit);
    }

    void update(int x, int val)
    {
        for (; x < N; x += (x & -x))
            bit[x] += val;
    }

    int get(int x)
    {
        int ans = 0;
        for (; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
} bit;

int cal(int *a, int *b)
{
    // cerr << '\n';
    // For (i, 1, n) cerr << a[i] << " \n"[i == n];
    // For (i, 1, n) cerr << b[i] << " \n"[i == n];
    int ans = 0;
    For(i, 0, 29) adj[i].clear();
    Fod(i, n, 1) adj[b[i]].pb(i);
    bit.reset();
    For(i, 1, n) bit.update(i, 1);
    For(i, 1, n)
    {
        int idx = adj[a[i]].back();
        adj[a[i]].pop_back();
        ans += bit.get(idx) - i;
        int idx1 = i;
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (bit.get(mid) >= i)
            {
                idx1 = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        // cerr << i << ": " << idx << ' ' << idx1 << '\n';
        bit.update(idx, -1);
        bit.update(idx1, 1);
    }
    return ans;
}

void ttk32()
{
    cin >> n;
    For(i, 1, 2 * n)
    {
        char x;
        cin >> x;
        a[i] = x - 'a';
        ++cnt[a[i]];
    }

    int ans = LLONG_MAX;
    For(i, 1, 2 * n) ck[i] = (++cnt1[a[i]] <= cnt[a[i]] / 2);
    int idx = 1, idx1 = 0;
    For(i, 1, 2 * n) if (ck[i])
    {
        res += i - idx;
        b[idx++] = a[i];
    }
    else c[++idx1] = a[i];
    minimize(ans, res + min(cal(b, c), cal(c, b)));

    memset(cnt1, 0, sizeof cnt1);
    Fod(i, 2 * n, 1) ck[i] = (++cnt1[a[i]] <= cnt[a[i]] / 2);
    idx = 1, idx1 = 0;
    For(i, 1, 2 * n) if (ck[i])
    {
        res += i - idx;
        b[idx++] = a[i];
    }
    else c[++idx1] = a[i];
    minimize(ans, res + min(cal(b, c), cal(c, b)));
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ld = long double;
// #define int long long

// #define all(v) v.begin(), v.end()
// #define create_unique(vec) \
//     sort(all(vec));        \
//     vec.resize(unique(all(vec)) - vec.begin());

// #define endl '\n'
// #define db(val) "[" #val " = " << (val) << "] "
// #ifdef LOCAL_DEBUG
// #define clog cerr
// #else
// #define clog \
//     if (0)   \
//     cerr
// #endif

// template <class T>
// bool ckmin(T &a, const T &b)
// {
//     return b < a ? a = b, 1 : 0;
// }
// template <class T>
// bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

// // 1-based
// struct SegTree
// {
//     typedef ll T;
//     static constexpr T unit = 0;

//     int _n;
//     vector<T> st;

//     SegTree(int _n) : _n(_n), st(_n * 4 + 1, unit) {}

//     T op(T a, T b) { return a + b; }

//     void update(int p, T x, int id, int lx, int rx)
//     {
//         if (p > rx || p < lx)
//             return;
//         if (lx == rx)
//         {
//             st[id] += x;
//             return;
//         }

//         int mid = (lx + rx) / 2;
//         update(p, x, id * 2, lx, mid);
//         update(p, x, id * 2 + 1, mid + 1, rx);

//         st[id] = op(st[id * 2], st[id * 2 + 1]);
//     }

//     T query(int u, int v, int id, int lx, int rx)
//     {
//         if (u > rx || v < lx)
//             return unit;
//         if (u <= lx && v >= rx)
//             return st[id];

//         int mid = (lx + rx) / 2;
//         return op(query(u, v, id * 2, lx, mid), query(u, v, id * 2 + 1, mid + 1, rx));
//     }

//     void update(int p, T x)
//     {
//         update(p, x, 1, 1, _n);
//     }

//     T query(int u, int v)
//     {
//         return query(u, v, 1, 1, _n);
//     }
// };

// const int MAXN = 1e5 * 27 + 10;

// int n;
// int cnt[MAXN], cur[MAXN];
// int nxt[MAXN];

// bool mark[MAXN];

// int inv[MAXN];

// void solve()
// {
//     cin >> n;

//     string s;
//     cin >> s;
//     for (int i = 1; i <= 2 * n; i++)
//     {
//         cnt[s[i - 1]]++;
//     }

//     string t;
//     for (int i = 1; i <= 2 * n; i++)
//     {
//         mark[i] = (++cur[s[i - 1]] <= cnt[s[i - 1]] / 2);
//         if (mark[i])
//             t.push_back(s[i - 1]);
//     }

//     t += t;

//     for (char ch = 'a'; ch <= 'z'; ch++)
//     {
//         int val = ch - 'a' + 1;
//         nxt[val] = val;
//     }

//     vector<int> a;
//     for (char ch : s)
//     {
//         int val = ch - 'a' + 1;

//         nxt[val] += 27;
//         val = nxt[val];

//         a.push_back(val);
//     }

//     memset(nxt, 0, sizeof nxt);
//     for (char ch = 'a'; ch <= 'z'; ch++)
//     {
//         int val = ch - 'a' + 1;
//         nxt[val] = val;
//     }
//     vector<int> b;
//     for (char ch : t)
//     {
//         int val = ch - 'a' + 1;

//         nxt[val] += 27;
//         val = nxt[val];

//         b.push_back(val);
//     }

//     for (int i = 0; i < 2 * n; i++)
//     {
//         inv[b[i]] = i + 1;
//     }

//     SegTree tree(MAXN + 1);

//     int ans = 0;
//     for (int i : a)
//     {
//         int x = inv[i];
//         ans += tree.query(x + 1, MAXN + 1);
//         tree.update(x, 1);
//     }

//     cout << ans;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     while (t--)
//         solve();
// }