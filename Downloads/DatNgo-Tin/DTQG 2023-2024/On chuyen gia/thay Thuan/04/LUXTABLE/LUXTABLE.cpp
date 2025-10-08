#include <bits/stdc++.h>
using namespace std;
#define ___TheAnhCoder___ signed main()
#define endl "\n"

// #define int long long
#define ll long long

#define Pii pair<int, int>
#define Pll pair<long long, long long>
#define fi first
#define se second

#define sz(s) (int)s.size()
#define whole(x) x.begin(), x.end()

#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class X, class Y>
inline bool maximize(X &x, const Y &y)
{
    X e = 1e-9;
    return (x + e < y) ? x = y, 1 : 0;
}
template <class X, class Y>
inline bool minimize(X &x, const Y &y)
{
    X e = 1e-9;
    return (x > e + y) ? x = y, 1 : 0;
}

const int INF = 1e9;
const long long oo = 1e18;

const int mx = 2e5 + 6;
int n, a[mx];

bool cmp(Pii &a, Pii &b)
{
    return a.se > b.se;
}

void Process()
{
    map<int, int> mp[2];
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i];
        mp[(i & 1)][a[i]]++;
    }

    vector<Pii> cnt0(whole(mp[0]));
    vector<Pii> cnt1(whole(mp[1]));
    sort(whole(cnt0), cmp);
    sort(whole(cnt1), cmp);

    int tmp1 = INF, tmp2 = INF;
    for (auto x : cnt0)
    {
        minimize(tmp1, (n / 2) - x.se + mp[1][x.fi]);
    }
    for (auto x : cnt1)
    {
        minimize(tmp2, ((n & 1) ? n / 2 + 1 : n / 2) - x.se + mp[0][x.fi]);
    }
    int ans1 = INF, ans2 = INF;
    for (auto x : cnt1)
    {
        // if (ans1 >= tmp1 + (((n & 1) ? n / 2 + 1 : n / 2) - x.se)) cout << x.fi << ' ' << x.se << endl;
        minimize(ans1, tmp2 + (((n & 1) ? n / 2 + 1 : n / 2) - x.se));
    }
    cout << endl;
    for (auto x : cnt0)
    {
        // if (ans2 >= tmp2 + (n/2) - x.se) cout << x.fi << ' ' << x.se << endl;
        minimize(ans2, tmp1 + (n / 2) - x.se);
    }
    // cerr << tmp1 << ' ' << tmp2 << endl;
    // cerr << ans1 << ' ' << ans2 << endl;
    cout << min(ans1, ans2) << endl;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    int Tests = 1;
    cin >> Tests;
    while (Tests--)
        Process();

    return 0;
}