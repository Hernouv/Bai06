#include <bits/stdc++.h>
using namespace std;

#define int long long

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*lazy_e)()>

struct LazySegTree
{
    LazySegTree(int _n) : _n(_n)
    {
        segTree = vector<S>(_n * 4 + 1, e());
        lazy = vector<F>(_n * 4 + 1, lazy_e());
    }

    void construct(vector<S> &a, int id, int l, int r)
    {
        if (l == r)
        {
            segTree[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        construct(a, id * 2, l, mid);
        construct(a, id * 2 + 1, mid + 1, r);

        segTree[id] = op(segTree[id * 2], segTree[id * 2 + 1]);
    }

    void apply(int u, int v, F f, int id, int l, int r)
    {
        if (u > r || v < l)
            return;
        if (u <= l && v >= r)
        {
            all_apply(id, f);
            return;
        }
        push(id);

        int mid = (l + r) / 2;
        apply(u, v, f, id * 2, l, mid);
        apply(u, v, f, id * 2 + 1, mid + 1, r);

        segTree[id] = op(segTree[id * 2], segTree[id * 2 + 1]);
    }

    void apply(int u, int v, F f)
    {
        apply(u, v, f, 1, 1, _n);
    }

    S query(int u, int v, int id, int l, int r)
    {
        if (u > r || v < l)
            return e();
        if (u <= l && v >= r)
            return segTree[id];
        push(id);

        int mid = (l + r) / 2;
        return op(query(u, v, id * 2, l, mid), query(u, v, id * 2 + 1, mid + 1, r));
    }

    S query(int u, int v)
    {
        return query(u, v, 1, 1, _n);
    }

private:
    int _n;
    vector<S> segTree;
    vector<F> lazy;

    void all_apply(int id, F f)
    {
        segTree[id] = mapping(f, segTree[id]);
        lazy[id] = composition(f, lazy[id]);
    }
    void push(int id)
    {
        all_apply(2 * id, lazy[id]);
        all_apply(2 * id + 1, lazy[id]);
        lazy[id] = lazy_e();
    }
};

int op(int l, int r)
{
    return gcd(l, r);
}

int e()
{
    return 0;
}

int mapping(int f, int s)
{
    if (s == 0)
        return f;
    return lcm(f, s);
}

int composition(int f, int g)
{
    return lcm(f, g);
}

int lazy_e()
{
    return 1;
}

struct Query
{
    int u, v, k;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    LazySegTree<int, op, e, int, mapping, composition, lazy_e> tree(n);

    vector<Query> queries;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, k;
        cin >> u >> v >> k;

        queries.push_back({u, v, k});
        tree.apply(u, v, k);
    }

    bool ok = true;
    for (auto &[u, v, k] : queries)
    {
        if (tree.query(u, v) != k)
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << "Impossible";
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        int ans = tree.query(i, i);
        cout << ans << " ";
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    while (t--)
        solve();
}