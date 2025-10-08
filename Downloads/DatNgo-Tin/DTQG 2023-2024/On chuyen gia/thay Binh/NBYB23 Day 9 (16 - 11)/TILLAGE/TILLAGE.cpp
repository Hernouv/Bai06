#include <bits/stdc++.h>
#define MASK(k) (1LL << (k))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define int long long
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whole(a) a.begin(), a.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mirai ""
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 5005;
const int MOD = 1e9 + 7;
using namespace std;
int n, f[MAX][MAX];
pii a[MAX];
void process()
{
    memset(f, 0, sizeof(f));
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i].fi;
    }
    For(i, 1, n)
    {
        cin >> a[i].se;
        a[i].fi = a[i].fi - a[i].se;
    }
    sort(a + 1, a + n + 1, [](pii &x, pii &y)
         { return x.se > y.se; });
    For(j, 1, n)
    {
        For(i, 1, n)
        {
            if (i >= j)
                maximize(f[i][j], max(f[i - 1][j], f[i - 1][j - 1] + a[i].fi + a[i].se * j));
        }
        // cout << maxk << endl << endl;
        // For(i, 1, n){
        //     For(j, 1, maxk){
        //         cout << i << " " << j << " " << f[i][j] << endl;
        //     }
        // }
        cout << f[n][j] << " ";
    }
    cout << endl;
}
signed main()
{
    fastio if (fopen(mirai ".inp", "r"))
    {
        freopen(mirai ".inp", "r", stdin);
        freopen(mirai ".out", "w", stdout);
    }
    int Test = 1;
    cin >> Test;
    while (Test--)
    {
        process();
    }
    return 0;
}