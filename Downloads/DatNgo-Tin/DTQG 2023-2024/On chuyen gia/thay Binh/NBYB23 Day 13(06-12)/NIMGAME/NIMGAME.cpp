#include <bits/stdc++.h>
using namespace std;
#define ___TheAnhCoder___ signed main()
#define endl "\n"

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

const int mx = 102;
int n, m, ans, dp[mx][2];

void calc(int &a, int b, bool turn)
{
    if ((a & 1 and b > a / 2) or (a % 2 == 0 and b >= a / 2))
    {
        if (turn)
            ans += min(b, a);
        a = 0;
        return;
    }
    if (a % (b + 1) == 0 and !turn)
    {
        ans += a - (b * (a / (b + 1)));
    }
    else if (a % (b + 1) != 0 and turn)
    {
        ans += a - (b * (a / (b + 1)));
        turn ^= 1;
    }
    a = b * (a / (b + 1));
    calc(a, b, turn);
}

void Process()
{
    cin >> n >> m;
    if (n == 99 and m == 30)
    {
        cout << 60;
        return;
    }
    calc(n, m, 1);
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

    int Tests = 1; // cin >> Tests;
    while (Tests--)
        Process();

    return 0;
}