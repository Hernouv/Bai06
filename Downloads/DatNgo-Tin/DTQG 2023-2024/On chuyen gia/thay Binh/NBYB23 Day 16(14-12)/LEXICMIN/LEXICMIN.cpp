#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int N = 1e6 + 7;
const int outbound = 1e9 + 7;

int n, k;
int a[N];
vector<int> sav[N];
set<int> ind;

struct IT
{
    ii segTree[N << 2];

    ii func(ii x, ii y)
    {
        return {max(x.fi, y.fi), min(x.se, y.se)};
    }

    void update(int pos, ii val, bool change = 0, int id = 1, int l = 1, int r = n)
    {
        if (l > pos or pos > r)
            return;
        if (l == r)
        {
            if (change)
                segTree[id] = func(segTree[id], val);
            else
                segTree[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(pos, val, change, id * 2, l, mid);
        update(pos, val, change, id * 2 + 1, mid + 1, r);
        segTree[id] = func(segTree[id * 2], segTree[id * 2 + 1]);
    }

    ii get(int id, int l, int r, int L, int R)
    {
        if (l > R or L > r)
            return {-1, outbound};
        if (L <= l and r <= R)
            return segTree[id];
        int mid = (l + r) >> 1;
        return func(get(id * 2, l, mid, L, R), get(id * 2 + 1, mid + 1, r, L, R));
    }
} segTree;

int binarySearch(int i)
{
    int x = a[i];
    int ans = i;
    int l = 1, r = i;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        ii tmp = segTree.get(1, 1, n, mid, i);
        if (tmp.se + k >= x and x + k >= tmp.fi)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        segTree.update(i, {a[i], a[i]});
    }

    for (int i = 1; i <= n; ++i)
    {
        int idx = binarySearch(i);
        ind.insert(idx);
        segTree.update(i, {0, outbound});
        segTree.update(idx, {a[i], a[i]}, 1);
        sav[idx].push_back(a[i]);
    }

    for (int x : ind)
    {
        sort(sav[x].begin(), sav[x].end());
        for (int i : sav[x])
            cout << i << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}