#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e7 + 10;

struct node
{
    int child[2];
    void reset()
    {
        child[0] = 0;
        child[1] = 0;
    }
} trie[nmax];

int n, ia = 0;
int res = 0;
int a[(int)1e5 + 10];

void add(int num)
{
    int it = 0;
    for (int i = 30; i >= 0; --i)
    {
        int d = (num >> i) & 1;
        if (!trie[it].child[d])
            trie[it].child[d] = ++ia;
        it = trie[it].child[d];
    }
}

int max_xor(int num)
{
    int ret = 0;
    int it = 0;
    for (int i = 30; i >= 0; --i)
    {
        int d = (num >> i) & 1;
        if (trie[it].child[1 - d])
        {
            ret = ret * 2 + 1;
            it = trie[it].child[1 - d];
        }
        else
        {
            ret = ret * 2;
            it = trie[it].child[d];
        }
    }
    return ret;
}

void not_main()
{
    res = 0;
    ia = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        add(a[i]);
    }

    for (int i = 1; i <= n; ++i)
        maximize(res, max_xor(a[i]));

    cout << res << '\n';

    for (int i = 0; i <= ia; ++i)
        trie[i].reset();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("XOR.INP", "r"))
    {
        freopen("XOR.INP", "r", stdin);
        freopen("XOR.OUT", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        not_main();
    return 0;
}