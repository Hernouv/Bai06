#include <bits/stdc++.h>
using namespace std;

#define loop(_id, a, b) for (int _id = a; _id <= b; ++_id)
const int nmax = 2e5 + 5;

int n, q;
int a[nmax];
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

int segTree[8 * nmax];
int lzy[8 * nmax];
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

void down(int id, int l, int r)
{
    if (!lzy[id] or l == r)
        return;

    int mid = (l + r) / 2;
    segTree[id * 2] = (mid - l + 1) - segTree[id * 2];
    lzy[id * 2] = 1 - lzy[id * 2];
    segTree[id * 2 + 1] = (r - mid) - segTree[id * 2 + 1];
    lzy[id * 2 + 1] = 1 - lzy[id * 2 + 1];
    lzy[id] = 0;
}

void update(int L, int R, int id = 1, int l = 1, int r = 2 * n)
{
    if (l > R or r < L)
        return;
    down(id, l, r);
    if (L <= l and r <= R)
    {
        segTree[id] = (r - l + 1) - segTree[id];
        lzy[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    update(L, R, id * 2, l, mid);
    update(L, R, id * 2 + 1, mid + 1, r);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int getSum(int L, int R, int id = 1, int l = 1, int r = 2 * n)
{
    if (l > R or r < L)
        return 0;
    down(id, l, r);
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return getSum(L, R, id * 2, l, mid) + getSum(L, R, id * 2 + 1, mid + 1, r);
}

void not_main()
{
    cin >> n;

    int tu;
    loop(i, 2, n)
    {
        cin >> tu;
        graph[tu].push_back(i);
    }
    loop(i, 1, n)
    {
        cin >> a[i];
    }

    tour.push_back(-1);
    dfs_euler(0, 1);
    construct();

    cin >> q;
    string qtype;
    int s;
    loop(i, 1, q)
    {
        cin >> qtype >> s;
        if (qtype == "pow")
            update(pos1[s], pos2[s]);
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