#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e5 + 10;
const int outbound = 2e9;

int n, l, r, res = outbound;
int a[nmax];
int accum_L[nmax], accum_R[nmax];
int spTable[18][nmax];

void construct()
{
    for (int i = 1; i <= n + 1; ++i)
        spTable[0][i] = accum_R[i];
    for (int j = 1; (1 << j) <= n + 1; ++j)
        for (int i = 1; i <= n - (1 << j) + 2; ++i)
            spTable[j][i] = min(spTable[j - 1][i], spTable[j - 1][i + (1 << (j - 1))]);
}

int getMin(int L, int R)
{
    int len = __lg(R - L + 1);
    return min(spTable[len][L], spTable[len][R - (1 << len) + 1]);
}

void not_main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        accum_L[i] = a[i];
        accum_L[i] += accum_L[i - 1];
    }
    for (int i = n; i >= 1; --i)
    {
        accum_R[i] = a[i];
        accum_R[i] += accum_R[i + 1];
    }
    construct();
    for (int i = 0; i < n - l; ++i)
        minimize(res, accum_L[i] + getMin(i + l + 1, min(n + 1, i + r + 1)));
    cout << accum_L[n] - res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SUM2.INP", "r"))
    {
        freopen("SUM2.INP", "r", stdin);
        freopen("SUM2.OUT", "w", stdout);
    }
    not_main();
    return 0;
}