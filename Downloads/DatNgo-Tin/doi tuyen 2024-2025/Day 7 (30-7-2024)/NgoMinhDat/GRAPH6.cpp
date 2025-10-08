#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e4 + 10;
typedef pair<int, int> ii;
#define fi first
#define se second

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

int n, m;
vector<int> g[nmax];
int parent[nmax];
int num[nmax], low[nmax], timer = 0;
int bridge_no = 0, joint_no = 0;
vector<int> joints;
vector<ii> bridges, edges;
int child_in_DFSTree[nmax];
bool ifJoint[nmax];

void dfs(int par, int u)
{
    num[u] = low[u] = ++timer;
    for (int v : g[u])
    {
        if (v == par)
            continue;
        if (!num[v])
        {
            parent[v] = u;
            dfs(u, v);
            minimize(low[u], low[v]);
        }
        else
            minimize(low[u], num[v]);
    }
}

void bridgeCnt()
{
    for (int i = 1; i <= n; ++i)
    {
        int pa = parent[i];
        if (pa > 0 and low[i] >= num[i])
        {
            ++bridge_no;
            bridges.emplace_back(pa, i);
        }
    }
}

void jointCnt()
{
    for (int i = 1; i <= n; ++i)
    {
        int pa = parent[i];
        if (pa > 0)
            ++child_in_DFSTree[pa];
    }

    for (int i = 1; i <= n; ++i)
    {
        int pa = parent[i];
        if (pa > 0 and parent[pa] > 0 and low[i] >= num[pa])
            ifJoint[pa] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] == -1 and child_in_DFSTree[i] > 1)
            ifJoint[i] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (ifJoint[i])
        {
            ++joint_no;
            joints.push_back(i);
        }
    sort(joints.begin(), joints.end());
}

void not_main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
        {
            parent[i] = -1;
            dfs(0, i);
        }
    }

    jointCnt();
    bridgeCnt();

    cout << joint_no << ' ' << bridge_no << '\n';
    for (int j : joints)
        cout << j << '\n';
    for (ii edge : bridges)
        cout << edge.fi << ' ' << edge.se << '\n';
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