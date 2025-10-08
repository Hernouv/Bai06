/**
 *  Created at 14:38, Friday November 10, 2023
 *  By ms24 <3
 */
// #pragma GCC optimize("Ofast,02,unroll-loops")
// #pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define task "abjob"
#define ll long long
// #define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e3 + 7;
const int oo = 1e8 + 7;

int n, m, cnt;
bool used[N];
vector<int> adj[N];
struct dat
{
    int u, v, w;

    bool operator<(const dat &other)
    {
        if (u == other.u)
            return v == other.v ? w < other.w : v < other.v;
        return u < other.u;
    }
    friend istream &operator>>(istream &inp, dat &x)
    {
        inp >> x.w >> x.u >> x.v;
        return inp;
    }
    friend ostream &operator<<(ostream &out, dat &x)
    {
        out << x.w << ' ' << x.u << ' ' << x.v;
        return out;
    }
} a[N];

int dist[N], mg[N], mb[N];

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!mg[i])
        {
            q.push(i);
            dist[i] = 0;
        }
        else
            dist[i] = -1;
    }

    bool ans = 0;

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!mb[v])
                ans = 1;
            else if (dist[mb[v]] < 0)
            {
                dist[mb[v]] = dist[u] + 1;
                q.push(mb[v]);
            }
        }
    }

    return ans;
}

bool dfs(int u)
{
    for (int v : adj[u])
    {
        if (!mb[v])
        {
            mg[u] = v;
            mb[v] = u;
            return true;
        }
        else if (dist[mb[v]] == dist[u] + 1 && dfs(mb[v]))
        {
            mg[u] = v;
            mb[v] = u;
            return true;
        }
    }
    return false;
}

bool check(int x)
{
    int cnt = m;
    For(i, 1, n) adj[i].clear();
    For(i, 1, n)
    {
        mg[i] = mb[i] = dist[i] = 0;
        For(j, i + 1, n)
        {
            if (a[j].u >= a[i].v && abs(a[i].w - a[j].w) <= x)
                adj[i].pb(j);
        }
    }
    while (bfs())
        for (int i = 1; i <= n; i++)
            if (!mg[i])
                dfs(i);

    for (int i = 1; i <= n; i++)
        if (mg[i])
            cnt++;
    return cnt >= n;
}

void ttk32()
{
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);

    int ans = -1;
    int l = 0, r = oo;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
    return 0;
}