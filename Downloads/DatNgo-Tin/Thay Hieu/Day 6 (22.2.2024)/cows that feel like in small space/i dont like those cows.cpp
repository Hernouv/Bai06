#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 5e4 + 10;

deque<int> cow_proc;
ii cow[nmax];
int tight[nmax];
int n, d;
int res = 0;

int segTree[4 * nmax];

void SetUp_segTree_maxValInRange(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        segTree[id] = cow[l].se;
        return;
    }
    int mid = (l + r) / 2;
    SetUp_segTree_maxValInRange(id * 2, l, mid);
    SetUp_segTree_maxValInRange(id * 2 + 1, mid + 1, r);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

int getMax_inRange(int L, int R, int id = 1, int l = 1, int r = n)
{
    if (L <= l and r <= R)
        return segTree[id];
    if (r < L or l > R)
        return -1;
    int mid = (l + r) / 2;
    return max(getMax_inRange(L, R, id * 2, l, mid), getMax_inRange(L, R, id * 2 + 1, mid + 1, r));
}

void not_main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> cow[i].fi >> cow[i].se;
    sort(cow + 1, cow + n + 1);
    SetUp_segTree_maxValInRange();
    for (int i = 1; i <= n; ++i)
    {
        while (!cow_proc.empty() and cow[i].fi - cow[cow_proc.front()].fi > d)
            cow_proc.pop_front();
        if (!cow_proc.empty())
            if (getMax_inRange(cow_proc.front(), i) >= 2 * cow[i].se)
                ++tight[i];
        cow_proc.push_back(i);
    }
    cow_proc.clear();
    for (int i = n; i >= 1; --i)
    {
        while (!cow_proc.empty() and cow[cow_proc.front()].fi - cow[i].fi > d)
            cow_proc.pop_front();
        if (!cow_proc.empty())
            if (getMax_inRange(i, cow_proc.front()) >= 2 * cow[i].se)
                ++tight[i];
        cow_proc.push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (tight[i] == 2)
            ++res;
    cout << res << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}