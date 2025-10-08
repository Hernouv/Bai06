#include <bits/stdc++.h>
using namespace std;

const int nmax = 810;

int n, m, k, x, res = 0;
int flowers[nmax][nmax];

set<int> segTree[4 * nmax][4 * nmax];

void construct_singleLine(int c_id, int pos, int id = 1, int l = 1, int r = m)
{
    if (l == r)
    {
        segTree[c_id][id].insert(flowers[pos][l]);
        return;
    }
    int mid = (l + r) / 2;
    construct_singleLine(c_id, pos, id * 2, l, mid);
    construct_singleLine(c_id, pos, id * 2 + 1, mid + 1, r);
    segTree[c_id][id].insert(segTree[c_id][id * 2].begin(), segTree[c_id][id * 2].end());
    segTree[c_id][id].insert(segTree[c_id][id * 2 + 1].begin(), segTree[c_id][id * 2 + 1].end());
}

void construct_row(int c_id, int id = 1, int l = 1, int r = m)
{
    segTree[c_id][id].insert(segTree[c_id * 2][id].begin(), segTree[c_id * 2][id].end());
    segTree[c_id][id].insert(segTree[c_id * 2 + 1][id].begin(), segTree[c_id * 2 + 1][id].end());
    if (l == r)
        return;
    int mid = (l + r) / 2;
    construct_row(c_id, id * 2, l, mid);
    construct_row(c_id, id * 2 + 1, mid + 1, r);
}

void construct(int c_id = 1, int down = 1, int up = n)
{
    if (down == up)
    {
        construct_singleLine(c_id, down);
        return;
    }
    int mid = (down + up) / 2;
    construct(c_id * 2, down, mid);
    construct(c_id * 2 + 1, mid + 1, up);
    construct_row(c_id);
}

set<int> ret;
void getVal(int xd, int yd, int xu, int yu, int c_id = 1, int down = 1, int up = n, int id = 1, int l = 1, int r = m)
{
    if (xd <= down and up <= xu and yd <= l and r <= yu)
    {
        ret.insert(segTree[c_id][id].begin(), segTree[c_id][id].end());
        return;
    }
    if ((xd > up or xu < down) or (yd > r or yu < l))
        return;
    int midx = (down + up) / 2;
    int midy = (l + r) / 2;
    getVal(xd, yd, xu, yu, c_id * 2, down, midx, id * 2, l, midy);
    getVal(xd, yd, xu, yu, c_id * 2, down, midx, id * 2 + 1, midy + 1, r);
    getVal(xd, yd, xu, yu, c_id * 2 + 1, midx + 1, up, id * 2, l, midy);
    getVal(xd, yd, xu, yu, c_id * 2 + 1, midx + 1, up, id * 2 + 1, midy + 1, r);
}

void not_main()
{
    cin >> n >> m >> k >> x;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> flowers[i][j];

    if (x == n * m)
    {
        int t1 = n - k + 1;
        int t2 = m - k + 1;
        cout << t1 * t2;
        return;
    }

    construct();

    for (int i = 1; i <= n - k + 1; ++i)
        for (int j = 1; j <= m - k + 1; ++j)
        {
            ret.clear();
            getVal(i, j, i + k - 1, j + k - 1);
            res += (ret.size() <= x);
        }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PHOTO.INP", "r"))
    {
        freopen("PHOTO.INP", "r", stdin);
        freopen("PHOTO.OUT", "w", stdout);
    }
    not_main();
    return 0;
}