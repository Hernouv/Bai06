#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MOD = 998244353;

ll powd[MAXN];

struct Node
{
    ll val;
    int len;
} tree[4 * MAXN];

int n;
string ss;

void pre()
{
    powd[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        powd[i] = (powd[i - 1] * 10) % MOD;
    }
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        if (ss[l - 1] >= '0' && ss[l - 1] <= '9')
        {
            tree[node].val = ss[l - 1] - '0';
        }
        else
        {
            tree[node].val = 0;
        }
        tree[node].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node].len = tree[2 * node].len + tree[2 * node + 1].len;
    tree[node].val = (tree[2 * node].val * powd[tree[2 * node + 1].len] + tree[2 * node + 1].val) % MOD;
}

void update(int node, int l, int r, int pos, char c)
{
    if (l == r)
    {
        if (c >= '0' && c <= '9')
        {
            tree[node].val = c - '0';
        }
        else
        {
            tree[node].val = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * node, l, mid, pos, c);
    else
        update(2 * node + 1, mid + 1, r, pos, c);
    tree[node].val = (tree[2 * node].val * powd[tree[2 * node + 1].len] + tree[2 * node + 1].val) % MOD;
}

pair<ll, int> query(int node, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return {0, 0};
    if (ql <= l && r <= qr)
    {
        return {tree[node].val, tree[node].len};
    }
    int mid = (l + r) / 2;
    pair<ll, int> left = query(2 * node, l, mid, ql, qr);
    pair<ll, int> right = query(2 * node + 1, mid + 1, r, ql, qr);
    if (left.second == 0)
        return right;
    if (right.second == 0)
        return left;
    ll combv = (left.first * powd[right.second] + right.first) % MOD;
    int combl = left.second + right.second;
    return {combv, combl};
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    pre();
    cin >> ss;
    n = ss.size();
    build(1, 1, n);
    set<int> sett;
    for (int i = 1; i <= n; i++)
    {
        if (ss[i - 1] == '+' || ss[i - 1] == '-')
        {
            sett.insert(i);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            int l, r;
            cin >> l >> r;
            auto it_low = sett.lower_bound(l);
            auto it_high = sett.upper_bound(r);
            vector<int> ops;
            for (auto it = it_low; it != it_high; ++it)
            {
                ops.push_back(*it);
            }
            ll total = 0;
            int pos = l;
            int sign = 1;
            if (l <= r && (ss[l - 1] == '+' || ss[l - 1] == '-'))
            {
                sign = (ss[l - 1] == '+') ? 1 : -1;
                pos = l + 1;
            }
            for (auto it : ops)
            {
                if (pos < it)
                {
                    pair<ll, int> res = query(1, 1, n, pos, it - 1);
                    total = (total + sign * res.first) % MOD;
                    if (total < 0)
                        total += MOD;
                }
                if (ss[it - 1] == '+')
                    sign = 1;
                else
                    sign = -1;
                pos = it + 1;
            }
            if (pos <= r)
            {
                pair<ll, int> res = query(1, 1, n, pos, r);
                total = (total + sign * res.first) % MOD;
                if (total < 0)
                    total += MOD;
            }
            cout << total << "\n";
        }
        else if (type == '!')
        {
            int i;
            char c;
            cin >> i >> c;
            bool ch = (ss[i - 1] == '+' || ss[i - 1] == '-');
            ss[i - 1] = c;
            bool chh = (c == '+' || c == '-');
            if (ch && !chh)
            {
                sett.erase(i);
            }
            else if (!ch && chh)
            {
                sett.insert(i);
            }
            if (c >= '0' && c <= '9')
            {
                update(1, 1, n, i, c);
            }
            else
            {
                update(1, 1, n, i, '0');
            }
        }
    }
    return 0;
}