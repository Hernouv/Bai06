#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define eps double(1e-9)
#define vii vector<int>
#define pii pair<int, int>
#define p2i pair<int, pii>
#define endl '\n'

using namespace std;

const int N = 1e6 + 5;
const int MN = 2e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18 + 7;
const bool Emily = false;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r)
{
    return l + rng() % (r - l + 1);
}

bool minimize(int &a, int b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int n, k, s;

vector<int> adj[N];

int mx[N], my[N];
int d[N];

bool BFS(void)
{
    queue<int> q;
    rep(i, 1, n)
    {
        if (mx[i] == 0)
        {
            q.push(i);
            d[i] = 0;
        }
        else
            d[i] = -1;
    }

    bool ok = false;
    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (my[v] == 0)
                ok = true;
            else if (d[my[v]] < 0)
            {
                d[my[v]] = d[u] + 1;
                q.push(my[v]);
            }
        }
    }
    return ok;
}

bool DFS(int u)
{
    for (int v : adj[u])
    {
        if (my[v] == 0)
        {
            my[v] = u;
            mx[u] = v;
            return true;
        }
        else if (d[my[v]] == d[u] + 1 && DFS(my[v]))
        {
            my[v] = u;
            mx[u] = v;
            return true;
        }
    }
    return false;
}

int pref[MN][MN];
int dp[60][60][60][60];

int sum(int x, int y, int u, int v)
{
    return pref[u][v] - pref[u][x - 1] - pref[y - 1][v] + pref[u - 1][v - 1];
}

int DP(int x, int y, int u, int v)
{
    int &res = dp[x][y][u][v];
    if (res != -1)
        return res;
    res = max(u - x + 1, v - y + 1);

    rep(i, x, u - 1)
    {
        minimize(res, DP(x, y, i, v) + DP(i + 1, y, u, v));
    }
    rep(i, y, v - 1)
    {
        minimize(res, DP(x, y, u, i) + DP(x, i + 1, u, v));
    }
    return res;
}

int dd[MN][MN];
int a[MN][MN];
void solve(void)
{
    cin >> k >> n >> s;

    memset(dp, -1, sizeof dp);
    rep(i, 1, n) rep(j, 1, n) dp[i][j][i][j] = 0;

    rep(i, 1, s)
    {
        int u, v;
        cin >> u >> v;
        dp[u][v][u][v] = 1;
        adj[u].push_back(v);
        a[u][v] = 1;
    }

    rep(i, 1, n) rep(j, 1, n)
    {
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }

    while (BFS())
    {
        rep(i, 1, n) if (mx[i] == 0) DFS(i);
    }

    int res = 0;
    rep(i, 1, n) if (mx[i] != 0)++ res;

    if (k == 1)
        cout << res << endl;
    else
        cout << min(s, DP(1, 1, n, n)) << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);

    if (Emily)
    {
        int t;
        cin >> t;
        while (t--)
            solve();
    }
    else
        solve();

    return 0;
}