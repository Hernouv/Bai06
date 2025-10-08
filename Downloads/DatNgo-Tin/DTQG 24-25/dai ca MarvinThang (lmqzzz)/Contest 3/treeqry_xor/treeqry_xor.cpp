#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
#define fi first
#define se second

const int nmax = 2e5 + 10;

struct Query
{
    bool print;
    int x, y;
    Query() = default;
    Query(bool print, int x, int y) : print(print), x(x), y(y) {}
};

struct Node
{
    set<int> ids;
    int zero;
    int one;

    Node() : zero(-1), one(-1) {}
};

int q, n, t;
int l_node[nmax], r_node[nmax], rxor_val[nmax];

vector<ii> v[nmax];
vector<Query> Q;

vector<Node> trie;

void dfs(int node, int par, int xval)
{
    l_node[node] = ++t;
    rxor_val[node] = xval;
    for (ii p : v[node])
    {
        int nxt = p.fi;
        int w = p.se;
        if (nxt == par)
            continue;
        dfs(nxt, node, xval ^ w);
    }
    r_node[node] = t;
}

void trie_add(int node, int bit, int val, int id)
{
    trie[node].ids.insert(id);
    if (bit < 0)
        return;

    if (val & (1 << bit))
    {
        if (trie[node].one == -1)
        {
            trie[node].one = trie.size();
            trie.emplace_back();
        }
        trie_add(trie[node].one, bit - 1, val, id);
    }
    else
    {
        if (trie[node].zero == -1)
        {
            trie[node].zero = trie.size();
            trie.emplace_back();
        }
        trie_add(trie[node].zero, bit - 1, val, id);
    }
}

int trie_get(int node, int bit, int val, int from, int to)
{
    if (bit < 0)
        return 0;

    if ((val & (1 << bit)) == 0)
    {
        if (trie[node].one == -1 or trie[trie[node].one].ids.lower_bound(from) == trie[trie[node].one].ids.upper_bound(to))
        {
            if (trie[node].zero == -1)
                return 0;
            return trie_get(trie[node].zero, bit - 1, val, from, to);
        }
        else
        {
            return (1 << bit) + trie_get(trie[node].one, bit - 1, val, from, to);
        }
    }
    else
    {
        if (trie[node].zero == -1 or trie[trie[node].zero].ids.lower_bound(from) == trie[trie[node].zero].ids.upper_bound(to))
        {
            if (trie[node].one == -1)
                return 0;
            return trie_get(trie[node].one, bit - 1, val, from, to);
        }
        else
        {
            return (1 << bit) + trie_get(trie[node].zero, bit - 1, val, from, to);
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    n = 1;
    cin >> q;

    trie.emplace_back();

    string s;
    int x, y;
    int a, b;

    for (int i = 0; i < q; ++i)
    {
        cin >> s;

        if (s[0] == 'A')
        {
            cin >> x >> y;
            --x;
            Q.emplace_back(false, n, y);
            v[x].emplace_back(n, y);
            v[n].emplace_back(x, y);
            ++n;
        }
        else
        {
            cin >> a >> b;
            --a;
            --b;
            Q.emplace_back(true, a, b);
        }
    }

    dfs(0, -1, 0);

    trie_add(0, 30, 0, l_node[0]);

    for (Query qq : Q)
    {
        if (!qq.print)
            trie_add(0, 30, rxor_val[qq.x], l_node[qq.x]);
        else
            cout << trie_get(0, 30, rxor_val[qq.x], l_node[qq.y], r_node[qq.y]) << '\n';
    }

    return 0;
}
