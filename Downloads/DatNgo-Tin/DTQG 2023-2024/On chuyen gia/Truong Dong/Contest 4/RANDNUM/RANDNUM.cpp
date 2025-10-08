#include <bits/stdc++.h>
using namespace std;

int n, val[300010], res[300010], cnt = 0;
pair<int, int> queries[300010];
vector<int> compress;
int segTree[1500010];

int query(int id, int l, int r, int L, int R)
{
    if (r < L or R < l)
        return 0;
    if (L <= l and r <= R)
        return segTree[id];
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, L, R) + query(id * 2 + 1, mid + 1, r, L, R);
}

void update(int id, int l, int r, int L, int R, int val)
{
    if (r < L or R < l)
        return;
    if (L <= l and r <= R)
    {
        segTree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, L, R, val);
    update(id * 2 + 1, mid + 1, r, L, R, val);
    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
        if (queries[i].first == 1)
            compress.push_back(queries[i].second);
    }

    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for (int i = 1; i <= n; ++i)
    {
        if (queries[i].first == 1)
        {
            int t = lower_bound(compress.begin(), compress.end(), queries[i].second) - compress.begin() + 1;
            val[t] = queries[i].second;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (queries[i].first == 1)
        {
            int t = lower_bound(compress.begin(), compress.end(), queries[i].second) - compress.begin() + 1;
            update(1, 1, n, t, t, 1);
        }
        else
        {
            int pos = queries[i].second;
            int l = 1, r = n, ans;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (query(1, 1, n, 1, mid) >= pos)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            res[++cnt] = ans;
        }
    }

    for (int i = 1; i <= cnt; ++i)
    {
        cout << val[res[i]] << '\n';
    }
    return 0;
}