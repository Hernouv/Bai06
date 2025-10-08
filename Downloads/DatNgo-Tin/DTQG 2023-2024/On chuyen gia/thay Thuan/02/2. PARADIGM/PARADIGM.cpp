#include <bits/stdc++.h>
using namespace std;

#define task "TREECUT"
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

int n;
ii a[N];
vector<int> adj[N];
map<ii, bool> mp;
stack<ii> st;

int root[N], mx[N];

int find(int u)
{
    return root[u] ? root[u] = find(root[u]) : u;
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (mx[a] < mx[b])
            swap(a, b);
        root[b] = a;
        maximize(mx[a], mx[b]);
    }
}

void add(int u, int v)
{
    if (u > v)
        swap(u, v);
    mp[make_pair(u, v)] = 1;
}

void remove(int u, int v)
{
    if (u > v)
        swap(u, v);
    mp[make_pair(u, v)] = 0;
}

bool check(int u, int v)
{
    if (u > v)
        swap(u, v);
    return mp[make_pair(u, v)];
}

void ttk32()
{
    cin >> n;
    For(i, 1, n) cin >> a[i].F, a[i].S = i, mx[i] = a[i].F;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        add(u, v);
    }
    For(i, 1, n)
    {
        sort(all(adj[i]), [](const int &x, const int &y)
             { return a[x].F > a[y].F; });
    }
    sort(a + 1, a + n + 1, [](const ii &x, const ii &y)
         { return x.F > y.F; });
    For(i, 1, n)
    {
        int u = a[i].S;
        for (int v : adj[u])
        {
            if (check(u, v))
            {
                st.push({u, v});
                remove(u, v);
            }
        }
    }
    int res = 0;
    for (; st.size(); st.pop())
    {
        int u = st.top().F, v = st.top().S;
        int mxu = mx[find(u)], mxv = mx[find(v)];
        res += mxu + mxv;
        join(u, v);
    }
    cout << res;
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