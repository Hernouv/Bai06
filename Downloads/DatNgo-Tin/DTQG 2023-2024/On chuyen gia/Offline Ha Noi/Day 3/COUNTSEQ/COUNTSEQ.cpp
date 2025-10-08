#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

ll binpow(ll a, ll n, ll m = MOD)
{
    a %= m;
    ll res = 1;

    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n /= 2;
    }
    return res;
}

vector<int> factor(int x)
{
    vector<int> div;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i > 1)
                div.push_back(i);
            if (i * i != x)
                div.push_back(x / i);
        }
    }

    return div;
}

map<int, int> mp;

int magic(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (n == 3)
        return 3;

    if (mp.count(n))
        return mp[n];

    auto S = factor(n);
    int res = binpow(2, n - 1);
    for (int d : S)
    {
        res = (res - magic(n / d)) % MOD;
        res = (res + MOD) % MOD;
    }

    return mp[n] = res;
}

void solve()
{
    int n;
    cin >> n;

    cout << magic(n) << '\n';
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("COUNTSEQ.INP", "r"))
    {
        freopen("COUNTSEQ.INP", "r", stdin);
        freopen("COUNTSEQ.OUT", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}