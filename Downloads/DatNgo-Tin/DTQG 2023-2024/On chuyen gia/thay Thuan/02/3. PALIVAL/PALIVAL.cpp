#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long

#define all(v) v.begin(), v.end()
#define create_unique(vec) \
    sort(all(vec));        \
    vec.resize(unique(all(vec)) - vec.begin());
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define REPD(i, n) for (int i = (n); i--;)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

#define endl '\n'
#define db(val) "[" #val " = " << (val) << "] "
#ifdef LOCAL_DEBUG
#define clog cerr
#else
#define clog \
    if (0)   \
    cerr
#endif

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

struct HashedString
{
    static const ll M = 1e9 + 9;
    static const ll B = 9973;

    static vector<ll> pows;
    vector<ll> p_hash;

    HashedString() {}
    HashedString(const string &s) : p_hash(s.size() + 1)
    {
        while (pows.size() < s.size())
        {
            pows.push_back((pows.back() * B) % M);
        }

        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    void rehash(const string &s)
    {
        p_hash.resize(s.size() + 1);

        while (pows.size() < s.size())
        {
            pows.push_back((pows.back() * B) % M);
        }

        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    // [l, r]
    ll get_hash(int l, int r)
    {
        ll raw_val = (p_hash[r] - (p_hash[l - 1] * pows[r - l + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<ll> HashedString::pows = {1};

int n;
string s, t;

int rpos(int i) { return n - i + 1; }

void solve()
{
    cin >> s;
    t = s;
    reverse(all(t));

    n = s.size();
    HashedString hs1, hs2;
    hs1.rehash(s);
    hs2.rehash(t);

    auto check_odd = [&](int i, int len)
    {
        if (i + len - 1 > n || i - len + 1 < 1)
            return false;

        int j = rpos(i), jlen = j + len - 1;

        return hs1.get_hash(i, i + len - 1) == hs2.get_hash(j, jlen);
    };

    auto check_even = [&](int i, int len)
    {
        if (i + 1 > n || i + len > n || i - len + 1 < 1)
            return false;

        int j = rpos(i), jlen = j + len - 1;
        if (j > jlen)
            swap(j, jlen);

        return hs1.get_hash(i + 1, i + len) == hs2.get_hash(j, jlen);
    };

    int ans = 0;
    REP(i, n)
    {
        int ans_odd = 0;
        int ans_even = 0;

        // le
        int lo = 1, hi = n;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (check_odd(i, mid))
            {
                lo = mid + 1;
                ans_odd = mid;
            }
            else
                hi = mid - 1;
        }

        // chan
        if (i + 1 <= n && s[i - 1] == s[i])
        {
            lo = 1, hi = n;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;

                if (check_even(i, mid))
                {
                    lo = mid + 1;
                    ans_even = mid;
                }
                else
                    hi = mid - 1;
            }
        }

        ans += ans_odd + ans_even;
    }

    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}