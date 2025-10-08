#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ll long long
#define whole(a) a.begin(), a.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

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
int n, q, a[MAX];
map<int, ll> mp[MAX];
pii queries[MAX];
vi nen, g[MAX];
void not_main()
{
    cin >> n >> q;
    For(i, 1, n)
    {
        cin >> a[i];
        nen.pb(a[i]);
    }
    For(i, 1, q)
    {
        cin >> queries[i].fi >> queries[i].se;
        nen.pb(queries[i].fi);
        nen.pb(queries[i].se);
    }
    sort(whole(nen));
    nen.resize(unique(whole(nen)) - nen.begin());
    For(i, 1, n)
    {
        a[i] = lower_bound(whole(nen), a[i]) - nen.begin() + 1;
    }
    For(i, 1, q)
    {
        queries[i].fi = lower_bound(whole(nen), queries[i].fi) - nen.begin() + 1;
        queries[i].se = lower_bound(whole(nen), queries[i].se) - nen.begin() + 1;
    }
    For(i, 1, n)
    {
        g[a[i]].pb(i);
    }
    For(i, 1, q)
    {
        ll ans = 0;
        if (mp[queries[i].fi][queries[i].se])
            continue;
        if (queries[i].fi == queries[i].se)
        {
            if (g[queries[i].fi].size() & 1)
            {
                ans = 1LL * (g[queries[i].fi].size() / 2 + 1) * (g[queries[i].fi].size() / 2);
            }
            else
                ans = 1LL * (g[queries[i].fi].size() / 2) * (g[queries[i].fi].size() / 2);
        }
        else
        {
            if (g[queries[i].fi].size() < g[queries[i].se].size())
                for (int j = 0; j < g[queries[i].fi].size(); j++)
                {
                    int cnt = lower_bound(whole(g[queries[i].se]), g[queries[i].fi][j]) - g[queries[i].se].begin();
                    maximize(ans, 1LL * (j + 1) * (g[queries[i].se].size() - cnt));
                }
            else
            {
                for (int j = 0; j < g[queries[i].se].size(); j++)
                {
                    int cnt = lower_bound(whole(g[queries[i].fi]), g[queries[i].se][j]) - g[queries[i].fi].begin();
                    // cout << g[queries[i].se][j] << " " << g[queries[i].se].size() - j << " " << cnt << endl;
                    maximize(ans, 1LL * (g[queries[i].se].size() - j) * cnt);
                }
            }
        }
        mp[queries[i].fi][queries[i].se] = ans;
    }
    For(i, 1, q)
    {
        cout << mp[queries[i].fi][queries[i].se] << endl;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}