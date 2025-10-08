#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

const int N = 3e6 + 7;

int n, res = 0;
int a[N];
vector<int> segTree[N << 2];

ostream &operator<<(ostream &out, vector<int> &a)
{
    for (int i : a)
        out << i << ' ';
    return out;
}

int cnt_func(vector<int> &a, vector<int> &b)
{
    int j = 0;
    int ret = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        while (j < b.size() and b[j] < a[i])
            ++j;
        ret += j;
    }
    return ret;
}

void solve(int id = 1, int l = 1, int r = n)
{
    if (l == r)
        segTree[id].push_back(a[l]);
    else
    {
        int mid = (l + r) >> 1;
        int lChild = id * 2, rChild = id * 2 + 1;
        solve(lChild, l, mid);
        solve(rChild, mid + 1, r);
        res += min(cnt_func(segTree[lChild], segTree[rChild]), cnt_func(segTree[rChild], segTree[lChild]));
        segTree[id].resize(segTree[lChild].size() + segTree[rChild].size());
        merge(all(segTree[lChild]), all(segTree[rChild]), segTree[id].begin());
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    n = (1 << n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    solve();
    cout << res;
    return 0;
}