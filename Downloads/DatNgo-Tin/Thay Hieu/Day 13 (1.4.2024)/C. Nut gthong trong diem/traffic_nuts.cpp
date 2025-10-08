#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m;
vector<int> graph[nmax];
int parent[nmax];
int low[nmax], num[nmax], ia = 0;
bool isJoint[nmax];
int child_cntInDFSTree[nmax];
vector<int> joints;

void dfs(int par, int u)
{
    num[u] = ++ia;
    low[u] = ia;
    parent[u] = par;
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (!num[v])
        {
            dfs(u, v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

void find_joint()
{
    for (int i = 1; i <= n; ++i)
    {
        int par = parent[i];
        child_cntInDFSTree[par]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        int par = parent[i];
        if (parent[par] and par and low[i] >= num[par])
            isJoint[par] = true;
        else if (!par and child_cntInDFSTree[i] > 1)
            isJoint[i] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (isJoint[i])
            joints.push_back(i);
}

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i])
            dfs(0, i);
    find_joint();
    cout << joints.size() << '\n';
    for (int x : joints)
        cout << x << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("IOI.INP", "r"))
    {
        freopen("IOI.INP", "r", stdin);
        freopen("IOI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}