#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vtn 3004
#define fmax 1000007
#define fi first
#define se second
#define sp << " "
#define el << "\n"
#define oo 1e9
// #define int ll
#define pii pair<int, int>
#define pb push_back
#define FOD(i, b, a) for (int i = (int)b; i >= (int)a; i--)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

ll A, B;
ll dp[20][200][1500][2];
vector<int> val;

void solve()
{
    int ans = 0, tmp = 0;
    for (int i = 0; tmp >= 0; ++i)
    {
        tmp = 40 * i + 25 * min((165 - 3 * i) / 2, 100 - 2 * i);
        ans = max(ans, tmp);
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}