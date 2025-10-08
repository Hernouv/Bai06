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

void updateRange(int l, int r, int val)
{
    update(l, val);
    update(r + 1, -val);
}

long long getVal(int pos)
{
    long long ret = 0;
    while (pos >= 1)
    {
        ret += fenwickTree[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}

void not_main()
{
    cin >> n >> m;
    int rq_type, rq_iter1, rq_iter2, rq_iter3;
    for (int i = 1; i <= m; ++i)
    {
        cin >> rq_type;
        if (rq_type == 1)
        {
            cin >> rq_iter1 >> rq_iter2 >> rq_iter3;
            updateRange(rq_iter1, rq_iter2, rq_iter3);
        }
        else if (rq_type == 2)
        {
            cin >> rq_iter1;
            cout << getVal(rq_iter1) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SBOX2.INP", "r"))
    {
        freopen("SBOX2.INP", "r", stdin);
        freopen("SBOX2.OUT", "w", stdout);
    }
    not_main();
    return 0;
}