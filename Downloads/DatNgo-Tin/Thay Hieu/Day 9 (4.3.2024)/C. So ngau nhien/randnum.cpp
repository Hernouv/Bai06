#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e7 + 10;
struct node
{
    int cnt = 0;
    int child[2]{0};
} trie[nmax];

int id_assigner = 0;

void add(int num)
{
    int it = 0;
    for (int i = 30; i >= 0; --i)
    {
        int bit = ((num >> i) & 1);
        if (trie[it].child[bit] == 0)
            trie[it].child[bit] = ++id_assigner;
        it = trie[it].child[bit];
        ++trie[it].cnt;
    }
}

int print(int num)
{
    int it = 0, ret = 0;
    for (int i = 30; i >= 0; --i)
    {
        if (trie[it].child[0] == 0 or trie[trie[it].child[0]].cnt < num)
        {
            num -= trie[trie[it].child[0]].cnt;
            it = trie[it].child[1];
            ret = ret * 2 + 1;
        }
        else
        {
            it = trie[it].child[0];
            ret = ret * 2;
        }
    }
    return ret;
}

void not_main()
{
    int n;
    cin >> n;
    int q_type, xk;
    for (int i = 1; i <= n; ++i)
    {
        cin >> q_type >> xk;
        if (q_type == 1)
            add(xk);
        else if (q_type == 2)
            cout << print(xk) << '\n';
        // cout << 1 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    not_main();
    return 0;
}