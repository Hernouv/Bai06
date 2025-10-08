#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;

#define BIT(x, i) (((x) >> (i)) & 1)
#define XOR_OP(x, i) ((x) ^ (1 << (i)))
#define BITCNT(x) __builtin_popcountll(x)

int n, q, rq;
int a[nmax];
int cnt[nmax];
int erastos[nmax];
bool added[nmax];
long long total = 0, delt = 0, m = 0, f[nmax][65];
vector<int> divs[nmax];

void del(int idx)
{
    --m, total = 1LL * m * (m - 1) / 2;
    int sz = divs[idx].size();
    for (int mask = 1; mask < (1 << sz); ++mask)
    {
        if (BITCNT(mask) & 1)
            delt -= --cnt[f[idx][mask]];
        else
            delt += --cnt[f[idx][mask]];
    }
    added[idx] = false;
}

void ins(int idx)
{
    ++m, total = 1LL * m * (m - 1) / 2;
    int sz = divs[idx].size();
    for (int mask = 1; mask < (1 << sz); ++mask)
    {
        if (BITCNT(mask) & 1)
            delt += cnt[f[idx][mask]]++;
        else
            delt -= cnt[f[idx][mask]]++;
    }
    added[idx] = true;
}

void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i < nmax; ++i)
    {
        if (erastos[i])
            continue;
        erastos[i] = i;
        for (long long j = 1LL * i * i; j < nmax; j += i)
            if (!erastos[j])
                erastos[j] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        int prev = -1;
        while (a[i] != 1)
        {
            int tdiv = erastos[a[i]];
            if (tdiv != prev)
                divs[i].push_back(tdiv);
            prev = tdiv;
            a[i] /= tdiv;
        }

        f[i][0] = 1;
        int sz = divs[i].size();
        for (int mask = 1; mask < (1 << sz); ++mask)
        {
            for (int j = 0; j < sz; ++j)
                if (BIT(mask, j))
                {
                    f[i][mask] = f[i][XOR_OP(mask, j)] * divs[i][j];
                    break;
                }
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        cin >> rq;
        if (added[rq])
            del(rq);
        else
            ins(rq);
        cout << total - delt << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("COPRIME.INP", "r"))
    {
        freopen("COPRIME.INP", "r", stdin);
        freopen("COPRIME.OUT", "w", stdout);
    }
    not_main();
    return 0;
}