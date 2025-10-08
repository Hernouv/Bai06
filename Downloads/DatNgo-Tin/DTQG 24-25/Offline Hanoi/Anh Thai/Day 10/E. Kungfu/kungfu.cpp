#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fmax 1000007
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)

template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }

int n, a[fmax];
int dp[510][126000];
int total = 0, pnt = 0, checker = 0;
vector<int> u, v;
vector<pii> opera;

void solve()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        total += a[i];
    }
    if (total % 2 != 0)
    {
        cout << -1;
        return;
    }
    pnt = total / 2;
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    FOR(i, 0, n)
    {
        FOR(j, 0, pnt)
        {
            maximize(dp[i + 1][j], dp[i][j]);
            if (j + a[i + 1] <= pnt)
            {
                maximize(dp[i + 1][j + a[i + 1]], dp[i][j] + 1);
            }
        }
    }
    int w = pnt, i = n;
    while (i > 0)
    {
        if (dp[i - 1][w] == dp[i][w])
        {
            u.pb(i);
            i--;
        }
        else
        {
            v.pb(i);
            checker += a[i];
            w = w - a[i];
            i--;
        }
    }
    if (checker != pnt)
    {
        cout << -1;
        return;
    }
    i = u.size() - 1;
    int j = v.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[u[i]] > a[v[j]])
        {
            a[u[i]] -= a[v[j]];
            opera.pb({v[j], u[i]});
            j--;
            v.pop_back();
        }
        else if (a[u[i]] < a[v[j]])
        {
            a[v[j]] -= a[u[i]];
            opera.pb({u[i], v[j]});
            i--;
            u.pop_back();
        }
        else
        {
            a[v[j]] = a[u[i]] = 0;
            opera.pb({u[i], v[j]});
            i--;
            j--;
            u.pop_back();
            v.pop_back();
        }
    }
    cout << opera.size() << '\n';
    for (auto it : opera)
    {
        cout << it.fi << ' ' << it.se << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}