#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e4 + 10;

int n, m;
vector<int> g[nmax];
int parent[nmax];
int low[nmax], num[nmax], timer = 0;
bool cycle = false;

vector<int> cycle_vx;

stack<int> vlist;
void dfs(int u)
{
    vlist.push(u);
    low[u] = num[u] = ++timer;
    for (int v : g[u])
    {
        if (v != parent[u])
        {
            if (!parent[v])
            {
                parent[v] = u;
                dfs(v);
                minimize(low[u], low[v]);
            }
            else
                minimize(low[u], num[v]);
        }
    }

    if (low[u] == num[u])
    {
        vector<int> t_cycle;
        int t;
        do
        {
            t = vlist.top();
            t_cycle.push_back(t);
            vlist.pop();
        } while (t != u);
        if (t_cycle.size() > 1)
        {
            cycle = true;
            cycle_vx = t_cycle;
            return;
        }
    }
}

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!g[i].empty())
            sort(g[i].begin(), g[i].end());
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!parent[i])
        {
            parent[i] = -1;
            dfs(i);
            if (cycle)
            {
                cout << "YES\n";
                sort(cycle_vx.begin(), cycle_vx.end());
                for (int vx : cycle_vx)
                    cout << vx << ' ';
                return;
            }
        }
    }

    cout << "NO";
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