#include <bits/stdc++.h>
using namespace std;

const int lim = 1000004;

int n, q;
int arr[lim];
int bit[lim];
int last_visit[lim];
int ans[lim];

struct Query
{
    int l, r, idx;
} queries[lim];

bool cmp(Query x, Query y)
{
    return x.r < y.r;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(queries + 1, queries + q + 1, cmp);

    memset(last_visit, -1, sizeof(last_visit));
    int qcnt = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (last_visit[arr[i]] != -1)
            update(last_visit[arr[i]], -1);

        last_visit[arr[i]] = i;
        update(i, 1);

        while (qcnt <= q and queries[qcnt].r == i)
        {
            ans[queries[qcnt].idx] = query(queries[qcnt].r) - query(queries[qcnt].l - 1);
            qcnt++;
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
