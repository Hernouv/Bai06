#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
#define fi first
#define se second

struct node
{
    ll x, y, r;
};
vector<node> s, s2;
vector<ii> sr;

inline bool cond(const node &a, const node &b)
{
    if (a.x == b.x)
        return (a.y < b.y);
    return (a.x < b.x);
}

inline bool condr1(const node &a, const node &b)
{
    return (a.r > b.r);
}

inline bool condr2(const ii &a, const ii &b)
{
    return (a.se > b.se);
}

int n;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int par, int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (!visited[v])
            dfs(u, v);
    }
}

void sub12()
{
    sort(s.begin() + 1, s.begin() + n + 1, condr1);

    graph.resize(n + 5, vector<int>());
    visited.resize(n + 5, false);

    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            ll dx = (s[i].x - s[j].x), dy = (s[i].y - s[j].y);
            int td = dx * dx + dy * dy;
            if (s[i].r * s[i].r >= td)
                graph[i].push_back(j);
            if (s[j].r * s[j].r >= td)
                graph[j].push_back(i);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++cnt;
            dfs(-1, i);
        }
    }

    cout << cnt;
    return;
}

void spread(int u)
{
    ll R = s[u].r;
    int v = u - 1;
    while (v)
    {
        if (visited[v])
            break;
        ll dx = s[u].x - s[v].x, dy = s[u].y - s[v].y;
        ll td = dx * dx + dy * dy;
        if (R * R >= td)
        {
            visited[v] = true;
            R = max(R, td + s[v].r);
        }
        else
            break;
        --v;
    }

    R = s[u].r;
    v = u + 1;
    while (v <= n)
    {
        if (visited[v])
            break;
        ll dx = s[u].x - s[v].x, dy = s[u].y - s[v].y;
        ll td = dx * dx + dy * dy;
        if (R * R >= td)
        {
            visited[v] = true;
            R = max(R, td + s[v].r);
        }
        else
            break;
        ++v;
    }
}

void sub3()
{
    sort(s.begin() + 1, s.begin() + n + 1, cond);
    sr.resize(n + 5);
    for (int i = 1; i <= n; ++i)
        sr[i] = {i, s[i].r};
    sort(sr.begin() + 1, sr.begin() + n + 1, condr2);

    visited.resize(n + 5, false);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[sr[i].fi])
        {
            ++cnt;
            spread(sr[i].fi);
        }
    }
    cout << cnt;
    return;
}

void not_main()
{
    cin >> n;
    s.resize(n + 5);

    for (int i = 1; i <= n; ++i)
    {
        auto &[tx, ty, tr] = s[i];
        cin >> tx >> ty >> tr;
    }

    if (n <= 1000)
    {
        sub12();
        return;
    }

    s2 = s;
    for (int i = 2; i <= n; ++i)
    {
        s2[i].x -= s[1].x;
        s2[i].y -= s[1].y;
    }

    bool s3 = true;
    for (int i = 2; i < n; ++i)
    {
        ll t1 = 1LL * s2[i].x * s2[i + 1].y;
        ll t2 = 1LL * s2[i].y * s2[i + 1].x;
        if (t1 != t2)
        {
            s3 = false;
            break;
        }
    }
    if (s3)
    {
        sub3();
        return;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("WIFI.INP", "r"))
    {
        freopen("WIFI.INP", "r", stdin);
        freopen("WIFI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}