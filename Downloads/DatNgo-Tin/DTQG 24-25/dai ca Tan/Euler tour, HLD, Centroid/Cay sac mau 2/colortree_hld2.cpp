#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 2e5 + 5;

struct seg
{
    int val[1200001];
    int def = 0;
    int x, tl, tr;
    int t;
    void init(int c, int l, int r)
    {
        val[c] = 0;
        if (l < r)
        {
            int mid = (l + r) / 2;
            init((c << 1), l, mid);
            init((c << 1) + 1, mid + 1, r);
        }
    }
    void upd(int c, int l, int r)
    {
        if (tl > tr)
            return;
        if (r < tl or tr < l)
            return;
        else if (l >= tl and r <= tr)
            val[c] += x;
        else
        {
            int mid = (l + r) / 2;
            if (mid >= tl)
                upd((c << 1), l, mid);
            if (mid + 1 <= tr)
                upd((c << 1) | 1, mid + 1, r);
        }
    }
    int get(int c, int l, int r)
    {
        if (l <= t and t <= r)
        {
            if (l == r)
                return val[c];
            else
            {
                int mid = (l + r) / 2;
                int a = get((c << 1), l, mid);
                int b = get((c << 1) | 1, mid + 1, r);
                return val[c] + a + b;
            }
        }
        else
            return 0;
    }
};
seg stl, str;

vector<int> adj[nmax];
int n, m, i, j, t, t1, u, v, a, b;
int st[nmax], en[nmax], ldd[nmax];
int ances[nmax][20];
int col[nmax];

set<int> buc[nmax];

void dfs(int x)
{
    for (int i = 1; i < 20; i++)
        ances[x][i] = ances[ances[x][i - 1]][i - 1];

    a++;
    st[x] = a;
    ldd[a] = x;
    for (int g : adj[x])
        if (g != ances[x][0])
        {
            ances[g][0] = x;
            dfs(g);
        }
    en[x] = a;
}

int lca(int u, int v)
{
    if (st[u] <= st[v] and en[u] >= st[v])
        return u;
    int x = u;
    for (int i = 19; i >= 0; i--)
    {
        if (!(st[ances[x][i]] <= st[v] and en[ances[x][i]] >= st[v]))
            x = ances[x][i];
    }
    return ances[x][0];
}

void pAdd(int x, int v)
{
    stl.x = v;
    str.x = -v;
    stl.tl = 1;
    str.tl = 1;
    stl.tr = st[x];
    str.tr = st[x] - 1;
    stl.upd(1, 1, n);
    str.upd(1, 1, n);
}

void pAdd2(int x, int px, int v)
{
    stl.x = v;
    str.x = -v;
    stl.tl = st[px] + 1;
    str.tl = st[px];
    stl.tr = st[x];
    str.tr = st[x] - 1;
    stl.upd(1, 1, n);
    str.upd(1, 1, n);
}

int query(int x)
{
    stl.t = st[x];
    str.t = en[x];
    return stl.get(1, 1, n) + str.get(1, 1, n);
}

void cAdd(int x, int c)
{
    if (!buc[c].size())
    {
        buc[c].insert(st[x]);
        pAdd(x, 1);
    }
    else
    {
        buc[c].insert(st[x]);
        int nl, nr;
        set<int>::iterator it = buc[c].lower_bound(st[x]);
        if (it != buc[c].begin())
        {
            it--;
            nl = ldd[(*it)];
            it++;
        }
        else
            nl = 1;

        it++;
        if (it != buc[c].end())
            nr = ldd[(*it)];
        else
            nr = 1;

        it--;
        nl = lca(nl, x);
        nr = lca(nr, x);
        if (st[nr] <= st[nl] and st[nl] <= en[nr])
            pAdd2(x, nl, 1);
        else
            pAdd2(x, nr, 1);
    }
}

void cDel(int x, int c)
{
    if (buc[c].size() == 1)
    {
        buc[c].erase(st[x]);
        pAdd(x, -1);
    }
    else
    {
        int nl, nr;
        set<int>::iterator it = buc[c].lower_bound(st[x]);
        if (it != buc[c].begin())
        {
            it--;
            nl = ldd[(*it)];
            it++;
        }
        else
            nl = 1;

        it++;
        if (it != buc[c].end())
            nr = ldd[(*it)];
        else
            nr = 1;

        it--;
        nl = lca(nl, x);
        nr = lca(nr, x);
        if (st[nr] <= st[nl] and st[nl] <= en[nr])
            pAdd2(x, nl, -1);
        else
            pAdd2(x, nr, -1);
        buc[c].erase(it);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> col[i];
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ances[1][0] = 1;
    a = 0;
    dfs(1);

    stl.init(1, 1, n);
    str.init(1, 1, n);
    for (i = 1; i <= n; i++)
        cAdd(i, col[i]);

    for (i = 1; i <= m; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b;
            cDel(a, col[a]);
            col[a] = b;
            cAdd(a, col[a]);
        }
        else
        {
            cin >> a;
            cout << query(a) << '\n';
        }
    }
}
