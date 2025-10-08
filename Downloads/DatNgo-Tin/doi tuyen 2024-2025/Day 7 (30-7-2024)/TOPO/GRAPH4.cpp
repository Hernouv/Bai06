#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e4 + 10;
typedef pair<int, int> ii;
#define fi first
#define se second

int n, m;
int indeg[nmax], outdeg[nmax];
vector<int> revert_g[nmax];
bool visited[nmax];
int low[nmax], num[nmax], timer = 0;
bool cycle = false;
vector<ii> res;

inline bool customSort(ii &a, ii &b)
{
    return (a.se < b.se);
}

stack<int> scc;
void dfs(int par, int u)
{
    scc.push(u);
    low[u] = num[u] = ++timer;
    for (int v : revert_g[u])
    {
        if (v != par)
        {
            if (!visited[v])
            {
                dfs(u, v);
                minimize(low[u], low[v]);
            }
            else
                minimize(low[u], num[v]);
        }
    }

    if (low[u] == num[u])
    {
        int t, t_cnt = 0;
        do
        {
            t = scc.top();
            t_cnt++;
            scc.pop();
        } while (t != u);
        if (t_cnt > 1)
        {
            cycle = true;
            return;
        }
    }
}

void dfs_proc(int u)
{
    for (int v : revert_g[u])
    {
        dfs_proc(v);
        indeg[u] += indeg[v];
    }
}

void not_main()
{
    cin >> n >> m;
    int u, v;

    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        ++indeg[v];
        ++outdeg[u];
        revert_g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(0, i);
            if (cycle)
            {
                cout << "None";
                return;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!outdeg[i])
            dfs_proc(i);
    }

    for (int i = 1; i <= n; ++i)
        res.emplace_back(i, indeg[i]);
    sort(res.begin(), res.end(), customSort);

    for (ii vx : res)
        cout << vx.fi << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GRAPH.INP", "r"))
    {
        freopen("GRAPH.INP", "r", stdin);
        freopen("GRAPH.OUT", "w", stdout);
    }
    not_main();
    return 0;
}