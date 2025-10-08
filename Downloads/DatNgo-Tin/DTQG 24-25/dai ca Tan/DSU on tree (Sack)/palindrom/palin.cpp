#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

template <class T>
bool maximize(T &x, T y) { return x < y ? x = y, 1 : 0; }

const int maxn = 5e5 + 17, z = 26;
int n, cntf[maxn], sz[maxn], h[maxn];
vector<int> graph[maxn];
vector<ii> qry[maxn];
string s;
bool big[maxn], cnt[maxn][z], ans[maxn];

void pre_dfs(int v)
{
    sz[v] = 1;
    for (int u : graph[v])
        h[u] = h[v] + 1, pre_dfs(u), sz[v] += sz[u];
}

void add(int v)
{
    cntf[h[v]] -= cnt[h[v]][s[v] - 'a'];
    cnt[h[v]][s[v] - 'a'] ^= 1;
    cntf[h[v]] += cnt[h[v]][s[v] - 'a'];
    for (int u : graph[v])
        if (!big[u])
            add(u);
}

void dfs(int v, bool keep)
{
    int mx = 0, b;
    for (int u : graph[v])
        if (maximize(mx, sz[u]))
            b = u;
    for (int u : graph[v])
        if (u != b)
            dfs(u, 0);
    if (mx)
        big[b] = 1, dfs(b, 1);
    add(v);
    big[b] = 0;
    for (ii q : qry[v])
        ans[q.se] = (cntf[q.fi] <= 1);
    if (!keep)
        add(v);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 1, p; i < n; i++)
    {
        cin >> p;
        graph[p - 1].push_back(i);
    }
    pre_dfs(0);
    cin >> s;
    for (int i = 0, v, h; i < m; i++)
        cin >> v >> h, qry[v - 1].push_back({h - 1, i});
    dfs(0, 0);
    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "Yes" : "No") << '\n';
    return 0;
}