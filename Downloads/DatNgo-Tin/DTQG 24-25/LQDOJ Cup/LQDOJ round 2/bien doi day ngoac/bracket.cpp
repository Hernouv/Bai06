#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define gqt "bracket"

const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 4005;
const int MOD = 1e9 + 7;

using namespace std;
int n;
ll f[2][105];
string base;
void add(ll &a, ll b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

struct subtask4
{
    string s;
    ll dp[2][MAX][3];
    void sol()
    {
        s = base;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        For(i, 0, n - 1)
        {
            int cur = i & 1, nxt = !cur;
            For(j, 0, i)
            {
                if (s[i + 1] != ')')
                {
                    add(dp[nxt][j + 1][0], dp[cur][j][0]);
                    if (j > 0)
                    {
                        add(dp[nxt][j - 1][1], dp[cur][j][0]);
                        add(dp[nxt][j - 1][1], dp[cur][j][1]);
                    }
                    add(dp[nxt][j + 1][2], dp[cur][j][1]);
                    add(dp[nxt][j + 1][2], dp[cur][j][2]);
                }
                if (s[i + 1] != '(')
                {
                    if (j > 0)
                        add(dp[nxt][j - 1][0], dp[cur][j][0]);
                    add(dp[nxt][j + 1][1], dp[cur][j][0]);
                    add(dp[nxt][j + 1][1], dp[cur][j][1]);
                    if (j > 0)
                    {
                        add(dp[nxt][j - 1][2], dp[cur][j][1]);
                        add(dp[nxt][j - 1][2], dp[cur][j][2]);
                    }
                }
            }
            For(j, 0, i) For(tmp, 0, 2) dp[cur][j][tmp] = 0;
        }
        ll res = dp[n & 1][0][1];
        add(res, dp[n & 1][0][2]);
        cout << res;
    }
} sub4;
int cntx = 0;
void process()
{
    cin >> n >> base;
    if (n % 2 == 1)
    {
        cout << 0;
        return;
    }
    base = " " + base;
    sub4.sol();
}

signed main()
{
    fastio if (fopen(gqt ".inp", "r"))
    {
        freopen(gqt ".inp", "r", stdin);
        freopen(gqt ".out", "w", stdout);
    }
    int Test = 1;
    while (Test--)
    {
        process();
    }
    return 0;
}