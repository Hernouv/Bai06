#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

template <typename T>
using vec = vector<T>;

struct Node
{
    u32 x, j, k;
    Node(u32 _x, u32 _j, u32 _k) : x(_x), j(_j), k(_k) {}
    bool operator<(const Node &t) const
    {
        if (x != t.x)
            return x > t.x;
        return k > t.k;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    u32 n, m;
    cin >> n >> m;

    vec<u32> a(n), b(n), c(n);
    for (u32 &i : a)
        cin >> i;
    for (u32 &i : b)
        cin >> i;
    for (u32 &i : c)
        cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    const u32 B = ceil(sqrt(double(m) / double(n))) * 3 + 1, MB = m / B;

    vec<u32> d(MB + 1);

    {
        priority_queue<Node> pq;
        vec<u32> vis(n);
        pq.emplace(b[0] + c[0], 0, 0);
        for (u32 i = 0; i <= MB; i++)
        {
            auto [x, j, k] = pq.top();
            pq.pop();
            if (vis[j] > k)
            {
                --i;
                continue;
            }
            d[i] = x;
            vis[j] = k + 1;
            if (j + 1 < n)
                pq.emplace(b[j + 1] + c[k], j + 1, k);
            if (k + 1 < n)
                pq.emplace(b[j] + c[k + 1], j, k + 1);
        }
    }

    auto f = [&](u32 x) -> u64
    {
        if (x <= d.back())
        {
            return lower_bound(d.begin(), d.end(), x) - d.begin();
        }
        u64 res = 0;
        for (u32 j = 0, k = n; j < n; j++)
        {
            while (k && b[j] + c[k - 1] >= x)
                --k;
            res += k;
        }
        return res;
    };

    auto check = [&](u32 x)
    {
        u64 cnt = 0;
        for (u32 i = 0; i < n; i++)
        {
            if (a[i] > x)
                break;
            cnt += f(x - a[i]);
            if (cnt >= m)
                break;
        }
        return cnt < m;
    };

    u64 l = 0, r = 3e9, mid;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
    return 0;
}