#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
const int nmax = 1e5 + 10;

int n, lgn;
long long k, h[nmax];
long long sparse_table[20][nmax];

void preprocess()
{
    for (int i = 1; i <= n; ++i)
        sparse_table[0][i] = h[i];
    for (int j = 1; j <= __lg(n); ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            sparse_table[j][i] = max(sparse_table[j - 1][i], sparse_table[j - 1][i + (1 << (j - 1))]);
}

long long queryMax(int l, int r)
{
    int t = __lg(r - l + 1);
    return max(sparse_table[t][l], sparse_table[t][r - (1 << t) + 1]);
}

int binaryLifting_L(int l, int pos)
{
    for (int i = 20; i >= 0; --i)
        if (l - (1 << i) + 1 >= 1)
            if (sparse_table[i][l - (1 << i) + 1] <= (long long)h[pos] + k)
                l -= (1 << i);
    return l;
}

int binaryLifting_R(int r, int pos)
{
    for (int i = 20; i >= 0; --i)
        if (r + (1 << i) - 1 <= n)
            if (sparse_table[i][r] <= (long long)h[pos] + k)
                r += (1 << i);
    return r;
}

void not_main()
{
    cin >> n >> k;
    lgn = __lg(n);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    preprocess();

    for (int i = 1; i <= n; ++i)
    {
        int L = binaryLifting_L(i, i);
        int R = binaryLifting_R(i, i);
        cout << R - L - 1 << ' ';
        // cout << L << ' ' << R << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("coc.inp", "r"))
    {
        freopen("coc.inp", "r", stdin);
        freopen("coc.out", "w", stdout);
    }
    not_main();
    return 0;
}