#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define whole(__) __.begin(), __.end()

const int nmax = 2e5 + 5;
string str[nmax];
int n;

template <int _N>
struct PrefixTrie
{
    int child[_N][26];
    int par[_N][19];
    int depth[_N];
    int time_in[_N], time_out[_N], time_cnt = 0;
    int sz = 0;

    void reset_trie()
    {
        for (int i = 0; i < 26; ++i)
            child[0][i] = 0;
        time_cnt = sz = 0;
        time_in[0] = 0;
    }

    int new_node()
    {
        sz++;
        for (int i = 0; i < 26; ++i)
            child[sz][i] = 0;
        return sz;
    }

    PrefixTrie()
    {
        reset_trie();
    }

    void add(const string &str)
    {
        int p = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (!child[p][str[i] - 'a'])
                child[p][str[i] - 'a'] = new_node();
            par[child[p][str[i] - 'a']][0] = p;
            p = child[p][str[i] - 'a'];
            depth[p] = i + 1;
            for (int j = 1; j < 19; ++j)
                par[p][j] = par[par[p][j - 1]][j - 1];
        }
    }

    int find_str(const string &str)
    {
        int p = 0;
        for (int i = 0; i < str.size(); ++i)
            p = child[p][str[i] - 'a'];
        return p;
    }

    void dfs_info(int p)
    {
        time_in[p] = ++time_cnt;
        for (int i = 0; i < 26; ++i)
            if (child[p][i])
                dfs_info(child[p][i]);
        time_out[p] = time_cnt;
    }

    int lca(int u, int v)
    {
        if (depth[u] > depth[v])
            swap(u, v);
        int k = depth[v] - depth[u];
        for (int j = 0; (1 << j) <= k; ++j)
            if ((k >> j) & 1)
                v = par[v][j];

        if (u == v)
            return u;
        for (int j = __lg(depth[u]); j >= 0; --j)
            if (par[u][j] != par[v][j])
            {
                u = par[u][j];
                v = par[v][j];
            }
        return par[u][0];
    }
};

template <int _N>
struct SuffixTrie
{
    int child[_N][26];
    int depth[_N];
    vector<pii> info_list[_N];
    int sz = 0;

    void reset_trie()
    {
        for (int i = 0; i < 26; ++i)
            child[0][i] = 0;
        sz = 0;
    }

    int new_node()
    {
        sz++;
        for (int i = 0; i < 26; ++i)
            child[sz][i] = 0;
        return sz;
    }

    SuffixTrie()
    {
        reset_trie();
    }

    void add(const string &str)
    {
        int p = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (!child[p][str[i] - 'a'])
                child[p][str[i] - 'a'] = new_node();
            p = child[p][str[i] - 'a'];
            depth[p] = i + 1;
        }
    }

    void add_info(const string &str, const pii &info)
    {
        int p = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            p = child[p][str[i] - 'a'];
            info_list[p].push_back(info);
        }
    }
};

PrefixTrie<nmax> pre;
SuffixTrie<nmax> suf;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> str[i];

    for (int i = 1; i <= n; ++i)
    {
        pre.add(str[i]);
        reverse(whole(str[i]));
        suf.add(str[i]);
    }

    pre.dfs_info(0);
    for (int i = 1; i <= n; ++i)
    {
        reverse(whole(str[i]));
        int p = pre.find_str(str[i]);
        reverse(whole(str[i]));
        suf.add_info(str[i], make_pair(pre.time_in[p], p));
    }

    ll res = 0;
    for (int i = 1; i <= suf.sz; ++i)
    {
        sort(whole(suf.info_list[i]));

        for (int j = 1; j < suf.info_list[i].size(); ++j)
        {
            int p = pre.lca(suf.info_list[i][j - 1].se, suf.info_list[i][j].se);
            int u = lower_bound(whole(suf.info_list[i]), make_pair(pre.time_in[p], 0)) - suf.info_list[i].begin();
            int v = upper_bound(whole(suf.info_list[i]), make_pair(pre.time_out[p], nmax)) - suf.info_list[i].begin();
            res = max(res, (ll)(v - u) * (ll)pre.depth[p] * (ll)suf.depth[i]);
        }
    }
    cout << res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}