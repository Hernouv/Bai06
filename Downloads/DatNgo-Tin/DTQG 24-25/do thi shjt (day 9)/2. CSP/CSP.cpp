#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 810;
const int outbound = 2e9;

struct m
{
    int node[2 * nmax][2 * nmax];
};
m matrx, mincost;
m defaultval;

int n, k;
int a[2 * nmax];
int cost[2 * nmax][2 * nmax];
int res = outbound;

void initialize()
{
    for (int i = 1; i < 2 * n; ++i)
    {
        int accum = a[i];
        for (int j = i + 1; j < min(i + n, 2 * n + 1); ++j)
        {
            cost[i][j] = cost[i][j - 1] + accum;
            accum += a[j];
        }
    }
}

m dp_proc(m a, m b)
{
    m ret = defaultval;
    for (int i = 1; i <= 2 * n; ++i)
        for (int j = i; j <= min(i + n - 1, 2 * n); ++j)
        {
            int tmp = a.node[i][i] + b.node[i + 1][j];
            for (int h = i; h < j; ++h)
                minimize(tmp, a.node[i][h] + b.node[h + 1][j]);
            ret.node[i][j] = tmp;
        }
    return ret;
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    initialize();
    for (int i = 1; i <= 2 * n; ++i)
        for (int j = i; j <= min(i + n - 1, 2 * n); ++j)
            matrx.node[i][j] = cost[i][j];
    mincost = matrx;

    --k;
    while (k > 0)
    {
        if (k % 2 == 1)
            mincost = dp_proc(mincost, matrx);
        matrx = dp_proc(matrx, matrx);
        k /= 2;
    }

    for (int i = 1; i <= n; ++i)
        minimize(res, mincost.node[i][i + n - 1]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CSP.INP", "r"))
    {
        freopen("CSP.INP", "r", stdin);
        freopen("CSP.OUT", "w", stdout);
    }
    not_main();
    return 0;
}