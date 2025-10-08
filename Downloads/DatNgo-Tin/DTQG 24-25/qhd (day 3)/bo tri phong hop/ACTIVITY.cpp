#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e4 + 10;

struct node
{
    int id;
    int s;
    int f;
};

inline bool customSort(node &a, node &b)
{
    if (a.s == b.s)
        return a.f < b.f;
    return (a.s < b.s);
}

node meetings[nmax];
int parent[nmax];
int n;

int binSearch(int val, int l = 1, int r = n)
{
    if (meetings[1].f > val)
        return 0;

    int prev, mid;
    for (;;)
    {
        mid = (l + r) / 2;
        if (prev == mid)
            break;
        if (meetings[mid].f <= val)
            l = mid;
        else
            r = mid - 1;
        prev = mid;
    }
    return mid;
}

ii segTree[4 * nmax];
void update(int idx, int pos, int val, int id = 1, int l = 1, int r = n)
{
    if (l > pos or r < pos)
        return;
    if (l == r)
    {
        segTree[id].fi = idx;
        segTree[id].se = val;
        return;
    }
    int mid = (l + r) / 2;
    update(idx, pos, val, id * 2, l, mid);
    update(idx, pos, val, id * 2 + 1, mid + 1, r);
    if (segTree[id * 2].se > segTree[id * 2 + 1].se)
        segTree[id] = segTree[id * 2];
    else
        segTree[id] = segTree[id * 2 + 1];
}

ii getMax(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (R < l or L > r)
        return {0, -1};
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    ii tmp1 = getMax(L, R, id * 2, l, mid);
    ii tmp2 = getMax(L, R, id * 2 + 1, mid + 1, r);
    if (tmp1.se > tmp2.se)
        return tmp1;
    else
        return tmp2;
}

void not_main()
{
    cin >> n;
    int t1, t2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t1 >> t2;
        meetings[i] = {i, t1, t2};
    }
    sort(meetings + 1, meetings + n + 1, customSort);

    for (int i = 1; i <= n; ++i)
    {
        int lim = binSearch(meetings[i].s);
        if (!lim)
        {
            parent[meetings[i].id] = meetings[i].id;
            update(meetings[i].id, i, 1);
        }
        else
        {
            ii tmp = getMax(1, lim);
            parent[meetings[i].id] = tmp.fi;
            update(meetings[i].id, i, tmp.se + 1);
        }
    }
    ii res = getMax(1, n);
    cout << res.se << '\n';
    stack<int> mlist;
    int tmp = res.fi;
    while (parent[tmp] != tmp)
    {
        mlist.push(tmp);
        tmp = parent[tmp];
    }
    mlist.push(tmp);
    while (!mlist.empty())
    {
        cout << mlist.top() << '\n';
        mlist.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ACTIVITY.INP", "r"))
    {
        freopen("ACTIVITY.INP", "r", stdin);
        freopen("ACTIVITY.OUT", "w", stdout);
    }
    not_main();
    return 0;
}