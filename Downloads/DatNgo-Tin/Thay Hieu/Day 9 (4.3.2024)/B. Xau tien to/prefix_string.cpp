#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
struct node
{
    int cnt = 0;
    int child[26]{0};
} trie[nmax];

int n, m, id_assigner = 0;

void add(string s)
{
    int it = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (trie[it].child[t] == 0)
            trie[it].child[t] = ++id_assigner;
        ++trie[it].cnt;
        it = trie[it].child[t];
    }
    ++trie[it].cnt;
}

int cnt_prefix(string s)
{
    int it = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (trie[it].child[t] == 0)
            return 0;
        it = trie[it].child[t];
    }
    return trie[it].cnt;
}

void not_main()
{
    cin >> n;
    string inp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> inp;
        add(inp);
    }

    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> inp;
        cout << cnt_prefix(inp) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ps.inp", "r"))
    {
        freopen("ps.inp", "r", stdin);
        freopen("ps.out", "w", stdout);
    }
    not_main();
    return 0;
}