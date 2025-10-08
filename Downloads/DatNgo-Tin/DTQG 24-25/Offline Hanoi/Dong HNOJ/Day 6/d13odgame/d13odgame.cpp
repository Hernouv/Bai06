#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

struct UnionFind
{
    vector<int> parent;
    vector<int> rank_;
    vector<int> parity;
    UnionFind(int n) : parent(n), rank_(n, 0), parity(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    ii find_set(int x)
    {
        if (parent[x] == x)
        {
            return {x, 0};
        }
        ii res = find_set(parent[x]);
        parent[x] = res.fi;
        parity[x] ^= res.se;
        return {parent[x], parity[x]};
    }

    bool union_set(int x, int y, int val)
    {
        ii fx = find_set(x);
        ii fy = find_set(y);
        if (fx.fi == fy.fi)
        {
            if ((fx.se ^ fy.se) != val)
                return false;
            return true;
        }

        if (rank_[fx.fi] < rank_[fy.fi])
        {
            parent[fx.fi] = fy.fi;
            parity[fx.fi] = fx.se ^ fy.se ^ val;
        }
        else
        {
            parent[fy.fi] = fx.fi;
            parity[fy.fi] = fx.se ^ fy.se ^ val;
            if (rank_[fx.fi] == rank_[fy.fi])
                rank_[fx.fi]++;
        }
        return true;
    }
};

struct Query
{
    int l;
    int r;
    int c;
};

void not_main()
{
    long long N;
    int K;
    cin >> N >> K;
    vector<Query> queries(K);
    vector<long long> y_list;
    y_list.push_back(0);
    for (int i = 0; i < K; i++)
    {
        long long l, r;
        string s;
        cin >> l >> r >> s;
        queries[i].l = l;
        queries[i].r = r;
        if (s == "even")
            queries[i].c = 0;
        else
            queries[i].c = 1;
        y_list.push_back(l - 1);
        y_list.push_back(r);
    }

    sort(whole(y_list));
    y_list.resize(unique(whole(y_list)) - y_list.begin());

    unordered_map<long long, int> y_map;
    int idx = 0;
    for (auto y : y_list)
        y_map[y] = idx++;

    UnionFind uf(idx);

    int last = 0;
    for (int i = 0; i < K; i++)
    {
        long long l = queries[i].l;
        long long r = queries[i].r;
        int c = queries[i].c;
        long long y1 = l - 1;
        long long y2 = r;
        int id1 = y_map[y1];
        int id2 = y_map[y2];
        bool ok = uf.union_set(id1, id2, c);
        if (!ok)
        {
            last = i;
            break;
        }
        last = i + 1;
    }
    cout << last;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
