#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e6 + 10;

struct node
{
    int child[26]{0};
    vector<int> end_str;
    void add_s(int num)
    {
        end_str.push_back(num);
    }
} trie[nmax];
int ia = 0;

int n;

void add(int id, string s)
{
    int u = 0;
    for (char ch : s)
    {
        int t = ch - 'a';
        if (!trie[u].child[t])
            trie[u].child[t] = ++ia;
        u = trie[u].child[t];
    }
    trie[u].add_s(id);
}

ii st[nmax];
int it = 0;
void dfs(int u, int h)
{
    for (int x : trie[u].end_str)
        st[++it] = {x, h};

    for (int i = 0; i < 26; ++i)
        if (trie[u].child[i])
            dfs(trie[u].child[i], h + 1);

    while (it >= 2 and st[it].se >= h)
    {
        cout << st[it].fi << ' ' << st[it - 1].fi << '\n';
        it -= 2;
    }
}

void not_main()
{
    cin >> n;
    string str;
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> str;
        add(i, str);
    }
    dfs(0, 0);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STR2N.INP", "r"))
    {
        freopen("STR2N.INP", "r", stdin);
        freopen("STR2N.OUT", "w", stdout);
    }
    not_main();
    return 0;
}