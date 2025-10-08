#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 2e6 + 10;

struct node
{
    int depth = 0;
    int child[26]{0};
} trie[nmax];
int ia = 0;

int n;
int edgeCnt = 0, max_depth = 0;

void add(string s)
{
    int u = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (!trie[u].child[t])
        {
            trie[u].child[t] = ++ia;
            ++edgeCnt;
        }
        u = trie[u].child[t];
    }
}

void not_main()
{
    cin >> n;
    string str;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        maximize(max_depth, (int)str.length());
        add(str);
    }
    cout << 2 * edgeCnt - max_depth + n;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PRINTER.INP", "r"))
    {
        freopen("PRINTER.INP", "r", stdin);
        freopen("PRINTER.OUT", "w", stdout);
    }
    not_main();
    return 0;
}