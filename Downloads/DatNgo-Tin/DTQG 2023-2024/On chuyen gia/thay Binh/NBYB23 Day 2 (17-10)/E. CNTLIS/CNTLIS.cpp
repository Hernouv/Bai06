#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

using ll = long long;
using bl = bool;
using str = string;
using db = double;

struct qhash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define fi first
#define se second

#define mp(p1, p2) make_pair(p1, p2)
#define f(i, n) for (ll i = 0; i < n; i += 1)
#define fv(i, v) for (typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define fu(i, start, end) for (int i = start; i < end; i += 1)
#define fd(i, start, end) for (int i = start; i >= end; i -= 1)
#define bit(var, pos) ((var >> pos) & 1)
#define pb push_back
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define MOD 998244353
ll loc[1000005];
ll arr[1000005];
vector<ll> shit[1000005];
void solve()
{
    ll n;
    cin >> n;
    f(i, n)
    {
        cin >> arr[i];
    }
    vector<ll> v;
    f(i, n)
    {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        loc[i] = it - v.begin();
        if (it == v.end())
            v.push_back(arr[i]);
        else
            *it = arr[i];
    }

    fd(i, n - 1, 0)
        shit[loc[i]]
            .push_back(i);
    vector<ll> temp;
    temp.reserve(v.size());
    vector<vector<ll>> res;
    ll cnt = 0;
    f(i, v.size()) cnt = max(cnt, ll(shit[i].size()));
    f(i, cnt)
    {
        ll prv = LLONG_MAX;
        bl fail = 0;
        fd(j, v.size() - 1, 0)
        {
            while (shit[j].size() && arr[shit[j].back()] > prv)
                shit[j].pop_back();
            if (!shit[j].size() || (temp.size() && shit[j].back() > temp.back()))
            {
                fail = 1;
                break;
            }
            temp.push_back(shit[j].back());
            prv = arr[shit[j].back()];
            shit[j].pop_back();
        }
        // if (fail) break;
        if (temp.size() == v.size())
        {
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        temp.clear();
    }
    f(i, res.size())
    {
        assert(res[i].size() == v.size());
    }
    cout << res.size() << " " << v.size() << '\n';
    f(i, res.size())
    {
        for (auto &val : res[i])
            cout << val + 1 << " ";
        cout << "\n";
    }
}
int main()
{

    // freopen("shopping.INP", "r" ,stdin); freopen("shopping.OUT", "w", stdout);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    int test = 1;

    // cin >> test;
    for (int i = 0; i < test; i += 1)
    {
        solve();
    }
    return 0;
}