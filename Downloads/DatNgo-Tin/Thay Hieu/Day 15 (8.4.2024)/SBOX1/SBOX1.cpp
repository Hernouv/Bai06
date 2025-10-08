#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
long long n, m;
long long fenwickTree[nmax];

void update(int pos, int val)
{
    while (pos <= n)
    {
        fenwickTree[pos] += val;
        pos += (pos & (-pos));
    }
}

long long getVal(int pos)
{
    if (!pos)
        return 0;
    long long ret = 0;
    while (pos >= 1)
    {
        ret += fenwickTree[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}

long long getValRange(int l, int r)
{
    return getVal(r) - getVal(l - 1);
}

void not_main()
{
    cin >> n >> m;
    int rq_type, rq_iter1, rq_iter2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> rq_type >> rq_iter1 >> rq_iter2;
        if (rq_type == 1)
            update(rq_iter1, rq_iter2);
        else if (rq_type == 2)
            cout << getValRange(rq_iter1, rq_iter2) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SBOX1.INP", "r"))
    {
        freopen("SBOX.INP", "r", stdin);
        freopen("SBOX.OUT", "w", stdout);
    }
    not_main();
    return 0;
}