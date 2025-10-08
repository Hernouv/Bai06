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
const int MAX = 100005;
const int MOD = 1e9 + 7;
using namespace std;
int n, m, cnt = 0, CC[MAX];
vi g[MAX], tplt[MAX];
int dx[] = {-2, -1, 0, +1, +2};
void dfs(int u)
{
    tplt[cnt].pb(u);
    CC[u] = cnt;
    for (int v : g[u])
    {
        if (CC[v] == 0)
            dfs(v);
    }
}
ll powd(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
ll check(int pos, int cnt, int x)
{
    ll ans = oo;
    for (int i = 0; i < 5; i++)
    {
        if (pos + dx[i] >= 0 && pos + dx[i] < tplt[cnt].size())
        {
            minimize(ans, powd(abs(tplt[cnt][pos + dx[i]] - x), 2));
        }
    }
    return ans;
}
void process()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    For(i, 1, n)
    {
        if (CC[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    For(i, 1, cnt)
    {
        sort(whole(tplt[i]));
    }
    int p1 = CC[1], pn = CC[n];
    ll res = oo;
    if (p1 == pn)
        res = 0;
    for (int x : tplt[p1])
    {
        int pos = lower_bound(whole(tplt[pn]), x) - tplt[pn].begin();
        int dis = check(pos, pn, x);
        minimize(res, dis);
    }
    For(i, 1, cnt)
    {
        if (i == p1 || i == pn)
            continue;
        ll dis1 = oo, disn = oo;
        for (int x : tplt[i])
        {
            int pos = lower_bound(whole(tplt[pn]), x) - tplt[pn].begin();
            int dis = check(pos, pn, x);
            minimize(disn, dis);
        }
        for (int x : tplt[i])
        {
            int pos = lower_bound(whole(tplt[p1]), x) - tplt[p1].begin();
            int dis = check(pos, p1, x);
            minimize(dis1, dis);
        }
        minimize(res, dis1 + disn);
    }
    cout << res << '\n';
    For(i, 1, n)
    {
        g[i].clear();
    }
    For(i, 1, cnt) tplt[i].clear();
    memset(CC, 0, sizeof(CC));
    cnt = 0;
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