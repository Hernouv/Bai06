#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> ii;

const int nmax = 1e5 + 10;

int n, res = 0;
ii trees[nmax];
int spTable[18][nmax];

void construct()
{
    for (int i = 1; i <= n; ++i)
        spTable[0][i] = trees[i].second;

    for (int i = 1; i <= __lg(n); ++i)
        for (int j = 1; j <= n - (1 << i) + 1; ++j)
            spTable[i][j] = max(spTable[i - 1][j], spTable[i - 1][j + (1 << (i - 1))]);
}

int getMax(int l, int r)
{
    int t = __lg(r - l + 1);
    return max(spTable[t][l], spTable[t][r - (1 << t) + 1]);
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> trees[i].first;
        trees[i].second = i;
    }
    sort(trees + 1, trees + n + 1);

    construct();

    for (int i = 1; i < n; ++i)
        maximize(res, getMax(i + 1, n) - trees[i].second);

    if (res == 0)
        cout << -1;
    else
        cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TREES.INP", "r"))
    {
        freopen("TREES.INP", "r", stdin);
        freopen("TREES.OUT", "w", stdout);
    }
    not_main();
    return 0;
}