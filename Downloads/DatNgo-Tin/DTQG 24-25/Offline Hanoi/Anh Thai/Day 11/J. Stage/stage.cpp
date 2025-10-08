#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()
#define For(i, a, b) for (int i = a; i <= b; ++i)

const int mx = 2e3 + 5;
const int MOD = 1e9 + 7;

int n, m, h[mx], a[mx], dp[mx][mx];
int pos[mx], ans, tmp[mx][mx];
vector<int> nen;

void add(int &a, const int &b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

struct SMT
{
    int smt[4 * mx];

    void update(int u, int v, int val, int id = 1, int l = 1, int r = n)
    {
        if (v < u)
            return;
        if (v < l or u > r)
            return;
        if (l >= u and r <= v)
        {
            add(smt[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        update(u, v, val, id << 1, l, mid);
        update(u, v, val, id << 1 | 1, mid + 1, r);
        smt[id] = (smt[id << 1] + smt[id << 1 | 1]) % MOD;
    }

    int get(int u, int v, int id = 1, int l = 1, int r = n)
    {
        if (v < u)
            return 0;
        if (v < l or u > r)
            return 0;
        if (l >= u and r <= v)
            return smt[id];
        int mid = (l + r) >> 1;
        int res = 0;
        add(res, get(u, v, id << 1, l, mid));
        add(res, get(u, v, id << 1 | 1, mid + 1, r));
        return res;
    }
} tree[mx];

void cein()
{
    cin >> n >> m;
    For(i, 1, n) cin >> h[i];
    For(i, 1, m) cin >> a[i];
}

namespace AC
{
    void sol()
    {
        For(i, 1, n) nen.push_back(h[i]);
        sort(whole(nen));
        nen.resize(unique(whole(nen)) - nen.begin());

        For(i, 1, n)
        {
            pos[i] = lower_bound(whole(nen), h[i]) - nen.begin() + 1;
            tmp[1][i] = 1;
        }
        For(j, 2, m)
        {
            For(pre, 1, j - 1)
            {
                tree[j - 1].update(pos[pre], pos[pre], tmp[j - 1][pre]);
            }
            For(i, j, n)
            {
                int vt = lower_bound(whole(nen), h[i] + a[j] - a[j - 1]) - nen.begin();
                int val = tree[j - 1].get(1, vt);
                tree[j - 1].update(pos[i], pos[i], tmp[j - 1][i]);
                tmp[j][i] = val;
            }
        }
        For(i, m, n) add(ans, tmp[m][i]);
        cout << ans << endl;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cein();
    AC::sol();
    return 0;
}