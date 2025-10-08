#include <bits/stdc++.h>
using namespace std;
#define ___TheAnhCoder___ signed main()
#define endl "\n"

#define int long long
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
bool maximize(X &x, const Y &y)
{
    X e = 1e-9;
    return (x + e < y) ? x = y, 1 : 0;
}
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X e = 1e-9;
    return (x > e + y) ? x = y, 1 : 0;
}

const int INF = 1e9;
const long long oo = 1e18;

const int mx = 1e6 + 7;
ll n;
vector<int> a;
ll s[mx], pre[mx], prea[mx];

void Process()
{
    cin >> n;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    For(i, 3, mx)
    {
        For(j, 1, a[i]) a.push_back(i);
        if (sz(a) > mx)
            break;
    }
    For(i, 1, mx)
    {
        s[i] = a[i] * i;
        prea[i] = prea[i - 1] + a[i];
        pre[i] = pre[i - 1] + s[i];
    }
    ll pos = lower_bound(pre + 1, pre + mx + 1, n) - pre;
    // cout << pre[mx];
    // return;
    // cout << pos << endl;

    // For (i, 1, pos + 1) cout << prea[i] << ' '; cout << endl;
    // For (i, 1, pos + 1) cout << s[i] << ' '; cout << endl;
    // For (i, 1, pos + 1) cout << pre[i] << ' '; cout << endl;

    // cout << n << ' ' << pre[pos-1] << endl;
    n -= pre[pos - 1];
    // cout << n << endl;
    ll ans = prea[pos - 1] + (n / pos);
    if (n % pos)
        ans++;
    cout << ans;
}
___TheAnhCoder___
{
    cin.tie(0)->sync_with_stdio(NULL);

#define Nhims ""
    if (fopen(Nhims ".inp", "r"))
    {
        freopen(Nhims ".inp", "r", stdin);
        freopen(Nhims ".out", "w", stdout);
    }

    int Tests = 1;
    while (Tests--)
        Process();

    return 0;
}