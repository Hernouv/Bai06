#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 2e5 + 10;
vector<int> graph[nmax];
int subtreeSz[nmax];
int cnt[nmax]{1};
bool del[nmax];
int n, k;
int hmax;
long long ans = 0;

int dfs(int u, int par = -1)
{
    subtreeSz[u] = 1;
    for (int v : graph[u])
    {
        if (v != par and !del[v])
            subtreeSz[u] += dfs(v, u);
    }
    return subtreeSz[u];
}

int getCentroid(int u, int par, int v_cnt)
{
    for (int v : graph[u])
        if (v != par and !del[v] and subtreeSz[v] >= v_cnt)
            return getCentroid(v, u, v_cnt);
    return u;
}

void cntProc(int u, int par, bool filling, int h = 1)
{
    if (h > k)
        return;
    maximize(hmax, h);
    if (filling)
        ++cnt[h];
    else
        ans += cnt[k - h];
    for (int v : graph[u])
        if (v != par and !del[v])
            cntProc(v, u, filling, h + 1);
}

void decompose(int u = 1)
{
    int centroid = getCentroid(u, 0, dfs(u) >> 1);
    del[centroid] = true;
    hmax = 0;
    for (int v : graph[centroid])
        if (!del[v])
        {
            cntProc(v, centroid, false);
            cntProc(v, centroid, true);
        }
    fill(cnt + 1, cnt + hmax + 1, 0);
    for (int v : graph[centroid])
        if (!del[v])
            decompose(v);
}

void not_main()
{
    cin >> n >> k;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    decompose();
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}