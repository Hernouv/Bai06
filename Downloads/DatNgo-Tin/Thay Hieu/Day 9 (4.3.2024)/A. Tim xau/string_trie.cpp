#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;
struct node
{
    bool isEnd = 0;
    int child[26]{0};
} trie[nmax];

int n, m, cnt = 0;

void add(string s)
{
    int it = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (trie[it].child[t] == 0)
            trie[it].child[t] = ++cnt;
        it = trie[it].child[t];
    }
    trie[it].isEnd = 1;
}

bool find_str(string s)
{
    int it = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (trie[it].child[t] == 0)
            return 0;
        it = trie[it].child[t];
    }
    return trie[it].isEnd;
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
        cout << find_str(inp) << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("str_trie.inp", "r"))
    {
        freopen("str_trie.inp", "r", stdin);
        freopen("str_trie.out", "w", stdout);
    }
    not_main();
    return 0;
}