#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int nmax = 1e5 + 10;
vector<int> tour, st(nmax, 0), en(nmax, 0);
vector<int> graph[nmax];
int segTree[nmax << 2];
int arr[nmax];
int n, m, q;

int dfs(int u, int par)
{
    tour.pb(u);
    for (int v : graph[u])
    {
        if (v != par)
            tour.pb(dfs(v, u));
    }
    return u;
}

void create_tour()
{
    dfs(1, 0);
    tour.pb(1);
}

void construct(int id, int l, int r)
{
    if (l == r)
    {
        segTree[id] = arr[tour[l]];
        return;
    }
    int mid = (l + r) >> 1;
    construct(id << 1, l, mid);
    construct(id << 1 | 1, mid + 1, r);
    segTree[id] = segTree[id << 1] + segTree[id << 1 | 1];
}

void update(int id, int l, int r, int pos, int val)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    segTree[id] = segTree[id << 1] + segTree[id << 1 | 1];
}

int getSum(int id, int l, int r, int L, int R)
{
    if (l > R or r < L)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) >> 1;
    return getSum(id << 1, l, mid, L, R) + getSum(id << 1 | 1, mid + 1, r, L, R);
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    int u, v;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    create_tour();
    construct(1, 0, tour.size() - 1);
    for (int i = 0; i < tour.size(); ++i)
    {
        if (!st[tour[i]])
            st[tour[i]] = i + 1;
        else
            en[tour[i]] = i + 1;
    }

    for (int x : tour)
        cout << x << ' ';
    cout << "\n\n";

    for (int i = 1; i <= n; ++i)
        cout << st[i] << ' ' << en[i] << '\n';
    cout << '\n';

    cin >> q;
    int query_type, pos, val, idx;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> pos >> val;
            update(1, 1, tour.size(), st[pos], val);
            update(1, 1, tour.size(), en[pos], val);
        }
        else
        {
            cin >> idx;
            cout << getSum(1, 1, tour.size(), st[idx], en[idx]) / 2 << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}