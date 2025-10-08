#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

const int N = 1e6 + 7;

int n, res = 0;
int a[N], last[N];

int fenwickTree[N];

void update(int x, int val)
{
    while (x < N)
    {
        fenwickTree[x] += val;
        x += (x & (-x));
    }
}

int get(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += fenwickTree[x];
        x -= (x & (-x));
    }
    return ans;
}

int getRange(int l, int r)
{
    if (l > r)
        return 0;
    return get(r) - get(l - 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (last[a[i]])
        {
            res += getRange(last[a[i]] + 1, i - 1) + 1;
            update(last[a[i]], -1);
            update(i, -1);
        }
        else
            last[a[i]] = i;
    }
    cout << res;
    return 0;
}