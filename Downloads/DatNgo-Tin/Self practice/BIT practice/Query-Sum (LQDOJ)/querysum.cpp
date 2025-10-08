#include <bits/stdc++.h>
using namespace std;

long long arr[100010];
long long fenwickTree[100010];
int n, q;
int rq, p, x, u, v;

long long getSum(int id)
{
    long long ret = 0;
    while (id > 0)
    {
        ret += fenwickTree[id];
        id -= id & (-id);
    }
    return ret;
}

void update(int id, long long val)
{
    while (id <= n)
    {
        fenwickTree[id] += val;
        id += id & (-id);
    }
}

void construct()
{
    for (int i = 1; i <= n; ++i)
        fenwickTree[i] = 0;
    for (int i = 1; i <= n; ++i)
        update(i, arr[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    construct();
    for (int i = 1; i <= q; ++i)
    {
        cin >> rq;
        if (rq == 1)
        {
            cin >> p >> x;
            update(p, x);
        }
        else
        {
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << '\n';
        }
    }
    return 0;
}