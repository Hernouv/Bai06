#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

template <class T1, class T2>
bool minimize(T1 &a, T2 b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
bool maximize(T1 &a, T2 b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const int N = 2e5 + 5;
const int oo = 1e9;
const int mod = 998244353;

ii operator+(ii a, ii b)
{
    ii res;
    res.fi = (ll)a.fi * b.fi % mod;
    res.se = ((ll)a.fi * b.se + a.se) % mod;
    return res;
}

struct segtree
{
    int n;
    vector<ii> st;

    segtree(int _n = 0)
    {
        n = _n;
        st.assign((n << 2) + 5, mp(0, 0));
    }

    void update(int id, int l, int r, int pos, ii val)
    {
        if (l > pos or r < pos)
            return;
        if (l == r)
            return (void)(st[id] = val);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int pos, ii val)
    {
        update(1, 1, n, pos, val);
    }

    ii getsum(int id, int l, int r, int u, int v)
    {
        if (l > v or r < u)
            return mp(1, 0);
        if (l >= u and r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        ii lnode = getsum(id * 2, l, mid, u, v);
        ii rnode = getsum(id * 2 + 1, mid + 1, r, u, v);
        return lnode + rnode;
    }

    ii getsum(int l, int r)
    {
        if (l > r)
            swap(l, r);
        return getsum(1, 1, n, l, r);
    }
};

segtree st, rev;

vector<int> adj[N];

ii a[N];

int revpos[N];
int par[N];
int pos[N];
int sz[N];
int d[N];
int r[N];
int n, q, timer;

void dfs(int u, int p = -1)
{
    par[u] = p;
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p)
        {
            d[v] = d[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
}

void build(int u, int root, int p = -1)
{
    pos[u] = ++timer;
    r[u] = root;
    int hv = 0;
    for (int v : adj[u])
        if (v != p and sz[hv] < sz[v])
            hv = v;
    if (hv == 0)
        return;
    build(hv, root, u);
    for (int v : adj[u])
        if (v != p and v != hv)
            build(v, v, u);
}

int getlca(int u, int v)
{
    while (r[u] != r[v])
    {
        if (d[r[u]] < d[r[v]])
            swap(u, v);
        u = par[r[u]];
    }
    if (d[u] > d[v])
        swap(u, v);
    return u;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    build(1, 1);
    st = rev = segtree(n);

    for (int i = 1; i <= n; i++)
    {
        revpos[i] = n - pos[i] + 1;
        st.update(pos[i], a[i]);
        rev.update(revpos[i], a[i]);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int u, x, y;
            cin >> u >> x >> y;
            st.update(pos[u], mp(x, y));
            rev.update(revpos[u], mp(x, y));
        }
        else
        {
            int u, v, x;
            cin >> u >> v >> x;
            int p = getlca(u, v);
            vector<ii> f, g;
            while (d[r[u]] > d[r[p]])
            {
                g.push_back(st.getsum(pos[r[u]], pos[u]));
                u = par[r[u]];
            }
            g.push_back(st.getsum(pos[p], pos[u]));
            reverse(g.begin(), g.end());

            while (d[r[v]] > d[r[p]])
            {
                f.push_back(rev.getsum(revpos[r[v]], revpos[v]));
                v = par[r[v]];
            }

            if (v != p)
                f.push_back(rev.getsum(revpos[p] - 1, revpos[v]));

            ii res = mp(1, 0);
            for (ii x : f)
                res = res + x;

            for (ii x : g)
                res = res + x;

            cout << ((ll)res.fi * x + res.se) % mod << "\n";
        }
    }
    return 0;
}
