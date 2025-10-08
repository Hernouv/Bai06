#include <bits/stdc++.h>
using namespace std;

long long arr[100010];
long long diff[100010], diffAccum[100010];
long long fenwickTree[100010];
long long fenwickTree_accumulativeSum[100010];
int n, q;
int rq, u, v;
long long x;

void updatePoint(int pos, int val)
{
    while (pos <= n)
    {
        fenwickTree[pos] += val;
        pos += pos & (-pos);
    }
}

void updatePoint_accum(int pos, int val)
{
    while (pos <= n)
    {
        fenwickTree_accumulativeSum[pos] += val;
        pos += pos & (-pos);
    }
}

void updateRange(int l, int r, long long val)
{
    updatePoint_accum(l, (n - l + 1) * val);
    updatePoint_accum(r + 1, -(n - r) * val);
    updatePoint(l, val);
    updatePoint(r + 1, -val);
}

void construct()
{
    for (int i = 1; i <= n; ++i)
    {
        fenwickTree[i] = 0;
        fenwickTree_accumulativeSum[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        updatePoint(i, diff[i]);
        updatePoint_accum(i, diffAccum[i]);
    }
}

long long getSum_proc(int id)
{
    long long ret = 0;
    while (id > 0)
    {
        ret += fenwickTree[id];
        id -= id & (-id);
    }
    return ret;
}

long long getSum_procAccum(int id)
{
    long long ret = 0;
    while (id > 0)
    {
        ret += fenwickTree_accumulativeSum[id];
        id -= id & (-id);
    }
    return ret;
}

long long getSum(int id)
{
    return getSum_procAccum(id) - getSum_proc(id) * (n - id);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("querysum2.inp", "r", stdin);
    // freopen("querysum2.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    diff[0] = 0;
    for (int i = 1; i <= n; ++i)
        diff[i] = arr[i] - arr[i - 1];
    for (int i = 2; i <= n; ++i)
        arr[i] += arr[i - 1];
    diffAccum[0] = 0;
    for (int i = 1; i <= n; ++i)
        diffAccum[i] = arr[i] - arr[i - 1];
    construct();
    for (int i = 1; i <= q; ++i)
    {
        cin >> rq;
        if (rq == 1)
        {
            cin >> u >> v >> x;
            updateRange(u, v, x);
        }
        else
        {
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << '\n';
        }
    }
    return 0;
}