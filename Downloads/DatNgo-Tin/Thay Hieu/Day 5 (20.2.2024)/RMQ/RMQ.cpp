#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
const int lgmax = __lg(nmax);

int n, m;
int a[nmax];
int sparse_table[lgmax][nmax];

void preprocess()
{
    for (int i = 1; i <= n; ++i)
        sparse_table[0][i] = a[i];
    for (int j = 1; j <= __lg(n); ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            sparse_table[j][i] = min(sparse_table[j - 1][i], sparse_table[j - 1][i + (1 << (j - 1))]);
}

int queryMin(int l, int r)
{
    int t = __lg(r - l + 1);
    return min(sparse_table[t][l], sparse_table[t][r - (1 << t) + 1]);
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    preprocess();

    int l, r;
    for (int i = 1; i <= m; ++i)
    {
        cin >> l >> r;
        cout << queryMin(l, r) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RMQ.INP", "r"))
    {
        freopen("RMQ.INP", "r", stdin);
        freopen("RMQ.OUT", "w", stdout);
    }
    not_main();
}