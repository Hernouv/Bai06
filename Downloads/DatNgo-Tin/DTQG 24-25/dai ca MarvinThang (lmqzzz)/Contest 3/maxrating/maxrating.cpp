#include <bits/stdc++.h>
using namespace std;

#define int long long
#define whole(__) __.begin(), __.end()

const int nmax = 4e5 + 5;
int n, m, q;
vector<int> rst;
int a[nmax], x[nmax], y[nmax];

vector<int> sz(4 * nmax);
vector<int> sum(4 * nmax);

void update(int pos, int mv, int now = 1, int l = 1, int r = m)
{
    sz[now] += mv;
    sum[now] += mv * rst[pos - 1];
    if (l == r)
        return;

    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(pos, mv, now * 2, l, mid);
    else
        update(pos, mv, now * 2 + 1, mid + 1, r);
}

int query(int tar, int now = 1, int l = 1, int r = m)
{
    if (sum[now] <= tar)
        return -1;
    if (l == r)
        return tar / rst[l - 1] + 1;

    int mid = (l + r) >> 1;
    if (sum[now * 2] > tar)
        return query(tar, now * 2, l, mid);
    else
        return sz[now * 2] + query(tar - sum[now * 2], now * 2 + 1, mid + 1, r);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
            rst.push_back(a[i]);
    }

    for (int i = 1; i <= q; ++i)
    {
        cin >> x[i] >> y[i];
        if (y[i] > 0)
            rst.push_back(y[i]);
    }

    sort(whole(rst));
    rst.erase(unique(whole(rst)), rst.end());

    auto find = [&](int val)
    {
        return lower_bound(whole(rst), val) - rst.begin() + 1;
    };

    int totalSum = 0, cnt = 0;
    m = rst.size();

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= 0)
        {
            totalSum -= a[i];
        }
        else
        {
            a[i] = find(a[i]);
            update(a[i], 1);
            ++cnt;
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        if (a[x[i]] <= 0)
        {
            totalSum += a[x[i]];
        }
        else
        {
            update(a[x[i]], -1);
            --cnt;
        }

        if (y[i] <= 0)
        {
            totalSum -= y[i];
            a[x[i]] = y[i];
        }
        else
        {
            a[x[i]] = find(y[i]);
            update(a[x[i]], 1);
            ++cnt;
        }

        int res = query(totalSum);
        cout << cnt - (res == -1 ? 0 : cnt - res + 1) + 1 << "\n";
    }

    return 0;
}
