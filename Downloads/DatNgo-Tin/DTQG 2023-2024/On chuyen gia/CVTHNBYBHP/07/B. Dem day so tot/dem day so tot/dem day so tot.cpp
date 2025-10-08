#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
using pii = pair<int, int>;

#define all(v) v.begin(), v.end()
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define REPD(i, n) for (int i = (n); i >= 1; i--)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

struct MergeSortTree
{
    int _n;
    vector<vector<int>> st;

    MergeSortTree() {}
    MergeSortTree(int _n) : _n(_n), st(_n * 4 + 1, vector<int>()) {}

    void init(int __n)
    {
        _n = __n;
        st.resize(_n * 4 + 1);
    }

    void build(int *x, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            st[id].push_back(x[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(x, id * 2, lx, mid);
        build(x, id * 2 + 1, mid + 1, rx);

        merge(all(st[id * 2]), all(st[id * 2 + 1]), back_inserter(st[id]));
    }

    int query(int u, int v, int k, int id, int lx, int rx)
    {
        if (u > rx or v < lx)
            return 0;
        if (u <= lx and v >= rx)
        {
            int res = upper_bound(all(st[id]), k) - st[id].begin();
            return res;
        }

        int mid = (lx + rx) >> 1;
        return query(u, v, k, id * 2, lx, mid) + query(u, v, k, id * 2 + 1, mid + 1, rx);
    }

    int query(int u, int v, int k)
    {
        return query(u, v, k, 1, 1, _n);
    }
};

const int MAXN = 1e6 + 10;

int n;
int a[MAXN], L[MAXN], R[MAXN];

void not_main()
{
    cin >> n;

    FOR(i, 1, n)
    cin >> a[i];

    stack<int> st;
    REP(i, n)
    {
        while (st.size() and a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            L[i] = 0;
        else
            L[i] = st.top();
        st.push(i);
    }

    while (st.size())
        st.pop();
    REPD(i, n)
    {
        while (st.size() and a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            R[i] = n + 1;
        else
            R[i] = st.top();
        st.push(i);
    }

    MergeSortTree tree(n);
    tree.build(L, 1, 1, n);

    int ans = 0;
    FOR(i, 1, n)
    {
        ans += tree.query(i, R[i] - 1, i);
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}