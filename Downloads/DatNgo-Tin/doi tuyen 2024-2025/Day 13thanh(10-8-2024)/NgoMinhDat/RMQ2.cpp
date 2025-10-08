#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 510;
const ll POSMAX = 1e18;

ll arr[nmax][nmax];
ll m, n, q;
int tmax_id = 0;

ll iniSeg[2000][2000], segTree[2000][2000];

void ini_construct(int row, int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        iniSeg[row][id] = arr[row][l];
        tmax_id = max(tmax_id, id);
        return;
    }
    int mid = (l + r) / 2;
    ini_construct(row, id * 2, l, mid);
    ini_construct(row, id * 2 + 1, mid + 1, r);

    iniSeg[row][id] = min(iniSeg[row][id * 2], iniSeg[row][id * 2 + 1]);
}

void construct(int pos, int id = 1, int l = 1, int r = m)
{
    if (l == r)
    {
        segTree[id][pos] = iniSeg[l][pos];
        return;
    }
    int mid = (l + r) / 2;
    construct(pos, id * 2, l, mid);
    construct(pos, id * 2 + 1, mid + 1, r);
    segTree[id][pos] = min(segTree[id * 2][pos], segTree[id * 2 + 1][pos]);
}

ll final_query(int qlow, int qhigh, int pos, int id = 1, int low = 1, int high = m)
{
    if (high < qlow or low > qhigh)
        return POSMAX;
    if (low <= qlow and high <= qhigh)
        return segTree[id][pos];
    int mid = (low + high) / 2;
    ll tl = final_query(qlow, qhigh, pos, id * 2, low, mid);
    ll tr = final_query(qlow, qhigh, pos, id * 2 + 1, mid + 1, high);
    return min(tl, tr);
}

ll query(int xa, int ya, int xb, int yb, int id = 1, int l = 1, int r = n)
{
    if (r < xa or l > xb)
        return POSMAX;
    if (xa <= l and r <= xb)
    {
        return final_query(ya, yb, id);
    }
    int mid = (l + r) / 2;
    ll tl = query(xa, ya, xb, yb, id * 2, l, mid);
    ll tr = query(xa, ya, xb, yb, id * 2 + 1, mid + 1, r);
    return min(tl, tr);
}

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];

    for (int i = 1; i <= m; ++i)
        ini_construct(i);
    for (int i = 1; i <= tmax_id; ++i)
        construct(i);

    cin >> q;
    int x1, y1, x2, y2;
    for (int i = 1; i <= q; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(y1, x1, y2, x2) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RMQ2.INP", "r"))
    {
        freopen("RMQ2.INP", "r", stdin);
        freopen("RMQ2.OUT", "w", stdout);
    }
    not_main();
    return 0;
}