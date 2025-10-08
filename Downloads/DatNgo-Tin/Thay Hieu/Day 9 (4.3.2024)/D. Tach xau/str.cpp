#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
const int mod = 1e9 + 7;

struct node
{
    bool isEnd = 0;
    int child[26];
} trie[nmax];

long long dp[(int)1e5 + 10];
int n, id_assigner = 0;
string x;

void add(string inp)
{
    int it = 0;
    for (char ch : inp)
    {
        int t = ch - 'a';
        if (trie[it].child[t] == 0)
            trie[it].child[t] = ++id_assigner;
        it = trie[it].child[t];
    }
    trie[it].isEnd = 1;
}

int check_str(int l, int r)
{
    int it = 0;
    for (int i = l; i <= r; ++i)
    {
        int t = x[i] - 'a';
        if (trie[it].child[t] == 0)
            return 0;
        it = trie[it].child[t];
    }
    if (trie[it].isEnd)
        return 2;
    return 1;
}

void not_main()
{
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        add(s);
    }
    cin >> x;
    int m = x.length();
    x = ' ' + x;

    dp[0] = 1;
    for (int i = 0; i <= m; ++i)
        for (int j = i + 1; j <= m; ++j)
        {
            int t = check_str(i + 1, j);
            if (t == 2)
            {
                dp[j] += dp[i];
                dp[j] %= mod;
            }
            else if (!t)
                break;
        }
    cout << dp[m] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STR.INP", "r"))
    {
        freopen("STR.INP", "r", stdin);
        freopen("STR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}