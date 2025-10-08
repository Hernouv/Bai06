/**
 *  Created at 23:01, Thursday October 12, 2023
 *  By ms24 <3
 */
#include <bits/stdc++.h>
using namespace std;

#define task "NCREC"
#define ll long long
// #define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define ms24

template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 5e5 + 7;
const int oo = 1e9 + 7;

struct rect
{
    int x, y, u, v, idx, col;
    rect() = default;
    rect(int x, int y, int u, int v, int idx, int col = -1) : x(x), y(y), u(u), v(v), idx(idx), col(col) {}

    friend ostream &operator<<(ostream &cout, const rect &A)
    {
        cout << A.x << ' ' << A.y << ' ' << A.u << ' ' << A.v;
        return cout;
    }
};

struct event
{
    int low, high, col, idx, t;
    event() = default;
    event(int low, int high, int col, int idx, int t) : low(low), high(high), col(col), idx(idx), t(t) {}

    friend ostream &operator<<(ostream &cout, const event &A)
    {
        cout << A.low << " " << A.high << ' ' << A.col << ' ' << A.idx << ' ' << A.t;
        return cout;
    }
};

int n, m;
int s[N];
int ans[N];
bool used[N];
set<int> sav[N];
vector<int> adj[N], nen;
vector<rect> a;
vector<event> ev[N];

struct IT
{
    int st[N << 2], lz[N << 2];

    IT()
    {
        memset(lz, -1, sizeof lz);
    }

    void push(int id, int l, int r)
    {
        if (lz[id] == -1 || l == r)
            return;
        int lChild = id * 2, rChild = id * 2 + 1;
        st[lChild] = st[rChild] = lz[id];
        lz[lChild] = lz[rChild] = lz[id];
        lz[id] = -1;
    }

    void update(int u, int v, int val, int id = 1, int l = 1, int r = N - 1)
    {
        push(id, l, r);
        if (l > v || u > r)
            return;
        if (u <= l && r <= v)
        {
            st[id] = lz[id] = val;
            push(id, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(u, v, val, id * 2, l, mid);
        update(u, v, val, id * 2 + 1, mid + 1, r);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int u, int v, int id = 1, int l = 1, int r = N - 1)
    {
        push(id, l, r);
        if (l > v || u > r)
            return 0;
        if (u <= l && r <= v)
            return st[id];

        int mid = (l + r) >> 1;
        return max(get(u, v, id * 2, l, mid), get(u, v, id * 2 + 1, mid + 1, r));
    }
} st;

bool isIn(const rect &A, const rect &B)
{
    return (A.x <= B.x && B.u <= A.u && A.y <= B.y && B.v <= A.v);
}

void dfs(int u)
{
    used[u] = 1;
    if (a[u].col != -1)
    {
        sav[u].insert(a[u].col);
        return;
    }
    for (int v : adj[u])
    {
        if (used[v])
            continue;
        dfs(v);
        if (sav[u].size() < sav[v].size())
            swap(sav[u], sav[v]);
        if (u != 0)
            sav[u].insert(sav[v].begin(), sav[v].end());
    }
    if (a[u].col == -1)
        ans[a[u].idx] = sav[u].size();
}

void compress()
{
    sort(nen.begin(), nen.end());
    nen.resize(unique(nen.begin(), nen.end()) - nen.begin());
    for (rect &A : a)
    {
        A.x = lower_bound(nen.begin(), nen.end(), A.x) - nen.begin();
        A.u = lower_bound(nen.begin(), nen.end(), A.u) - nen.begin();
        A.y = lower_bound(nen.begin(), nen.end(), A.y) - nen.begin();
        A.v = lower_bound(nen.begin(), nen.end(), A.v) - nen.begin();
    }
}

void ttk32()
{
    cin >> n >> m;
    a.pb(rect(0, 0, oo, oo, 0));
    nen.pb(0);
    nen.pb(oo);
    nen.pb(0);
    nen.pb(oo);
    For(i, 1, n)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        nen.pb(x), nen.pb(u);
        nen.pb(y), nen.pb(v);
        a.pb(rect(x, y, u, v, i));
    }
    For(i, n + 1, n + m)
    {
        int x, y, c;
        cin >> x >> y >> c;
        nen.pb(x), nen.pb(y);
        a.pb(rect(x, y, x, y, i, c));
    }
    swap(n, m);
    n += m;
    compress();
    sort(a.begin(), a.end(), [](const rect &A, const rect &B)
         {
        if (A.x == B.x && A.y == B.y) 
            return make_pair(A.u, A.v) < make_pair(B.u, B.v);
        return make_pair(A.x, A.y) < make_pair(B.x, B.y); });

    For(i, 1, n)
    {
        ev[a[i].x].pb(event(a[i].y, a[i].v, a[i].col, i, 2 - (a[i].col != -1)));
        if (a[i].col == -1)
            ev[a[i].u].pb(event(a[i].y, a[i].v, a[i].col, i, -1));
    }

    For(i, 1, N - 1)
    {
        sort(ev[i].begin(), ev[i].end(), [](const event &A, const event &B)
             {
            if (A.t == B.t) return make_pair(A.low, A.high) < make_pair(B.low, B.high);
            return A.t > B.t; });

        for (event &e : ev[i])
        {
            if (e.t == -1)
                st.update(e.low, e.high, s[e.idx]);
            else
            {
                int idx = st.get(e.low, e.high);
                if (e.t == 2)
                {
                    st.update(e.low, e.high, e.idx);
                    s[e.idx] = idx;
                }
                adj[idx].pb(e.idx);
            }
        }
    }

    dfs(0);
    For(i, 1, m) cout << ans[i] << '\n';
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