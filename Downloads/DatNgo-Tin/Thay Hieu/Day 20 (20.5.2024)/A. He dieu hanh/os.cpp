#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int m, n;
struct os_config
{
    // int id;
    int a, b;
};
struct os_config OS[nmax];
vector<int> ablist;
map<int, int> N_th;
int N, res;

void Nth_proc()
{
    ablist.resize(unique(ablist.begin(), ablist.end()) - ablist.begin());
    ablist.push_back(-1);
    sort(ablist.begin(), ablist.end());
    for (int i = 1; i < ablist.size(); ++i)
        N_th[ablist[i]] = i;
    N = ablist.size() - 1;

    for (int i = 1; i <= n; ++i)
    {
        int t1 = OS[i].a, t2 = OS[i].b;
        OS[i].a = N_th[t1];
        OS[i].b = N_th[t2];
    }
}

bool segTree[8 * nmax], lazyTree[8 * nmax];

void lazy(int id)
{
    if (!lazyTree[id])
        return;

    bool t = lazyTree[id];
    lazyTree[id] = 0;

    segTree[id * 2] = t;
    lazyTree[id * 2] = t;
    segTree[id * 2 + 1] = t;
    lazyTree[id * 2 + 1] = t;
}

void update(int L, int R, int id = 1, int l = 1, int r = N)
{
    if (r < L or R < l)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] = 1;
        lazyTree[id] = 1;
        return;
    }
    lazy(id);
    int mid = (l + r) / 2;
    update(L, R, id * 2, l, mid);
    update(L, R, id * 2 + 1, mid + 1, r);
    segTree[id] = (segTree[id * 2] or segTree[id * 2 + 1] ? 1 : 0);
}

bool interrupt(int L, int R, int id = 1, int l = 1, int r = N)
{
    if (r < L or R < l)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];

    lazy(id);
    int mid = (l + r) / 2;
    return (interrupt(L, R, id * 2, l, mid) or interrupt(L, R, id * 2 + 1, mid + 1, r) ? 1 : 0);
}

void not_main()
{
    cin >> m >> n;

    int t_a, t_b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t_a >> t_b;
        ablist.push_back(t_a);
        ablist.push_back(t_b);
        OS[n - i + 1] = {t_a, t_b};
    }

    Nth_proc();

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << OS[i].a << ' ' << OS[i].b << '\n';
    // }

    for (int i = 1; i <= n; ++i)
    {
        if (!interrupt(OS[i].a, OS[i].b))

            ++res;
        update(OS[i].a, OS[i].b);
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("os.inp", "r"))
    {
        freopen("os.inp", "r", stdin);
        freopen("os.out", "w", stdout);
    }
    not_main();
    return 0;
}