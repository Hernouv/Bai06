#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int nmax = 3e5 + 5;

int n, q;
vector<int> adj[nmax];
int h[nmax], id[nmax], head[nmax], par[nmax], s[nmax], pos[nmax], in[nmax], out[nmax], cnt, chain;

namespace segTree
{
    ll st[2 * nmax], d[nmax];
    int h, a[nmax];

    void apply(int pos, ll val)
    {
        st[pos] += val;
        if (pos <= n)
            d[pos] += val;
    }

    void down(int pos)
    {
        for (int s = h; s; s--)
        {
            int i = pos >> s;
            if (d[i] != 0)
            {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }

    void construct(int pos)
    {
        while (pos >>= 1)
            st[pos] = max(st[pos << 1], st[pos << 1 | 1]) + d[pos];
    }

    void update(int l, int r, ll val)
    {
        int l0 = l, r0 = r;
        for (l += n, r += n + 1, down(l), down(r); l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                apply(l++, val);
            if (r & 1)
                apply(--r, val);
        }
        construct(l0 + n);
        construct(r0 + n);
    }

    ll query(int l, int r)
    {
        if (l == 0)
            return 0;
        ll ans = -1e18;
        for (l += n, r += n + 1, down(l), down(r); l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans = max(ans, st[l++]);
            if (r & 1)
                ans = max(ans, st[--r]);
        }
        return ans;
    }

    void initialize()
    {
        st[n << 1 | 1] = -1e18;
        for (int i = 1; i <= n; i++)
            a[i] = 0, st[n + i] = a[i], st[n + i] += st[n + i - 1];
        for (int i = n; i >= 1; i--)
            st[i] = max(st[i << 1], st[i << 1 | 1]);
        h = log2(n);
    }

}

void dfs(int u, int p, int dep)
{
    h[u] = dep;
    par[u] = p;
    s[u] = 1;
    for (int v : adj[u])
        if (v != p)
        {
            dfs(v, u, dep + 1);
            s[u] += s[v];
        }
}

void hld(int u, int p)
{
    if (head[chain] == 0)
        head[chain] = u;
    id[u] = chain;
    pos[u] = in[u] = ++cnt;
    int x = -1;
    for (int v : adj[u])
        if (v != p)
            if (x == -1 or s[x] < s[v])
                x = v;
    if (x != -1)
        hld(x, u);
    for (int v : adj[u])
        if (v != p and v != x)
        {
            chain++;
            hld(v, u);
        }
    out[u] = cnt;
}

void update(int u, int v, int val)
{
    while (id[u] != id[v])
    {
        if (h[head[id[u]]] > h[head[id[v]]])
            swap(u, v);
        segTree::update(pos[head[id[v]]], pos[v], val);
        v = par[head[id[v]]];
    }
    if (h[u] > h[v])
        swap(u, v);
    segTree::update(pos[u], pos[v], val);
}

ll query(int u, int v)
{
    ll ans = 0;
    while (id[u] != id[v])
    {
        if (h[head[id[u]]] > h[head[id[v]]])
            swap(u, v);
        ans = max(ans, segTree::query(pos[head[id[v]]], pos[v]));
        v = par[head[id[v]]];
    }
    if (h[u] > h[v])
        swap(u, v);
    ans = max(ans, segTree::query(pos[u], pos[v]));
    return ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1, 0);
    cnt = 0;
    chain = 1;
    hld(1, 1);
    segTree::initialize();
    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, v, val;
            cin >> u >> v >> val;
            update(u, v, val);
        }
        else if (type == 2)
        {
            int u, val;
            cin >> u >> val;
            segTree::update(in[u], out[u], val);
        }
        else if (type == 3)
        {
            int u, v;
            cin >> u >> v;
            ll ans = query(u, v);
            cout << ans << '\n';
        }
        else if (type == 4)
        {
            int u, v;
            cin >> u;
            ll ans = segTree::query(in[u], out[u]);
            cout << ans << '\n';
        }
    }
}
