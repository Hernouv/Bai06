#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define loop(_id, a, b) for (int _id = a; _id <= b; ++_id)
const int nmax = 2e5 + 5;

int n, q;
ll a[nmax];
vector<int> graph[nmax];

vector<int> tour;
int pos1[nmax], pos2[nmax], it = 0;
void dfs_euler(int p, int u)
{
    tour.push_back(u);
    pos1[u] = ++it;
    for (int v : graph[u])
    {
        if (v == p)
            continue;
        dfs_euler(u, v);
    }
    tour.push_back(u);
    pos2[u] = ++it;
}

ll segTree[8 * nmax];
void construct(int id = 1, int l = 1, int r = 2 * n)
{
    if (l == r)
    {
        segTree[id] = a[tour[l]];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

void update(int pos, ll val, int id = 1, int l = 1, int r = 2 * n)
{
    if (l > pos or r < pos)
        return;

    if (l == r)
    {
        segTree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(pos, val, id * 2, l, mid);
    update(pos, val, id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

ll getSum(int L, int R, int id = 1, int l = 1, int r = 2 * n)
{
    if (l > R or r < L)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(L, R, id * 2, l, mid) + getSum(L, R, id * 2 + 1, mid + 1, r);
}

void not_main()
{
    cin >> n >> q;
    loop(i, 1, n)
    {
        cin >> a[i];
    }

    int tu, tv;
    loop(i, 1, n - 1)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    tour.push_back(-1);
    dfs_euler(0, 1);
    construct();

    int qtype, s;
    ll x;
    loop(i, 1, q)
    {
        cin >> qtype >> s;
        if (qtype == 1)
        {
            cin >> x;
            update(pos1[s], x);
            update(pos2[s], x);
        }
        else
            cout << getSum(pos1[s], pos2[s]) / 2 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}