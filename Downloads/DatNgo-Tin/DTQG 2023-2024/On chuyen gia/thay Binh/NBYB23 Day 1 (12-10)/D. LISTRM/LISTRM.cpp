#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

struct BIT
{
    int fenwickTree[N];

    void update(int id, int val)
    {
        while (id < N)
        {
            fenwickTree[id] += val;
            id += (id & -id);
        }
    }

    int get(int id)
    {
        int ans = 0;
        while (id > 0)
        {
            ans += fenwickTree[id];
            id -= (id & -id);
        }
        return ans;
    }
} bit;

int n;
int a[N];

int get_pos(int x)
{
    int ans = 0;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (bit.get(mid) >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        bit.update(i, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int pos;
        cin >> pos;
        pos = get_pos(pos);
        cout << a[pos] << ' ';
        bit.update(pos, -1);
    }
    return 0;
}