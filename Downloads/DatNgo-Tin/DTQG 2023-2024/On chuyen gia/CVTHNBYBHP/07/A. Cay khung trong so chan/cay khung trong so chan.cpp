#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define iii pair<ii, int>
#define fi first
#define se second

template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;
const int lgN = 18;

int n, m, W = 0;
int h[N];
ii spT[2][lgN + 1][N];
bool used[N], ans[N];
vector<iii> graph[N];
vector<pair<ii, ii>> sav;

void dfs(int u)
{
    used[u] = 1;
    for (iii i : graph[u])
    {
        int v = i.se, dv = i.fi.fi, id = i.fi.se;
        int x = dv & 1, y = (dv + 1) & 1;
        if (used[v])
        {
            sav.push_back({{u, v}, {dv, id}});
            continue;
        }
        ans[id] = 1;
        W += dv;
        h[v] = h[u] + 1;
        spT[x][0][v] = {id, u};
        spT[y][0][v] = {-1, u};
        for (int j = 1; j <= lgN; ++j)
        {
            spT[x][j][v].fi = max(spT[x][j - 1][v].fi, spT[x][j - 1][spT[x][j - 1][v].se].fi);
            spT[x][j][v].se = spT[x][j - 1][spT[x][j - 1][v].se].se;

            spT[y][j][v].fi = max(spT[y][j - 1][v].fi, spT[y][j - 1][spT[y][j - 1][v].se].fi);
            spT[y][j][v].se = spT[y][j - 1][spT[y][j - 1][v].se].se;
        }
        dfs(v);
    }
}

int lca(int x, int u, int v)
{
    int ans = -1;
    if (h[u] < h[v])
        swap(u, v);
    int delta = h[u] - h[v];
    for (int i = lgN; i >= 0; --i)
    {
        if ((delta >> i) & 1)
        {
            maximize(ans, spT[x][i][u].fi);
            u = spT[x][i][u].se;
        }
    }
    if (u == v)
        return ans;
    for (int i = lgN; i >= 0; --i)
    {
        if (spT[x][i][u].se != spT[x][i][v].se)
        {
            maximize(ans, max(spT[x][i][u].fi, spT[x][i][v].fi));
            u = spT[x][i][u].se;
            v = spT[x][i][v].se;
        }
    }
    maximize(ans, max(spT[x][0][u].fi, spT[x][0][v].fi));
    return ans;
}

void not_main()
{
    memset(spT, -1, sizeof spT);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w %= 2;
        graph[u].push_back({{w, i}, v});
        graph[v].push_back({{w, i}, u});
    }

    dfs(1);
    if (W % 2 == 0)
    {
        cout << "YES\n";
        for (int i = 1; i <= m; ++i)
            if (ans[i])
                cout << i << ' ';
    }
    else
    {
        for (pair<ii, ii> i : sav)
        {
            int u = i.fi.fi, v = i.fi.se, w = i.se.fi, id = i.se.se;
            int idx = lca((w + 1) & 1, u, v);
            if (idx != -1)
            {
                ans[idx] = 0;
                ans[id] = 1;
                cout << "YES\n";
                for (int i = 1; i <= m; ++i)
                    if (ans[i])
                        cout << i << ' ';
                return;
            }
        }
        cout << "NO";
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}