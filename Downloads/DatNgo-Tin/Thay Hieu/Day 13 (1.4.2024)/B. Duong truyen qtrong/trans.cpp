#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e4 + 10;

int n, m, k, l;
int parent[nmax];
vector<int> graph[nmax];
int h[nmax];
bool visited[nmax];
bool A[nmax], B[nmax];
int Acnt[nmax], Bcnt[nmax];
int num[nmax], low[nmax], ia = 0;
int res = 0;

void dfs(int par, int u)
{
    parent[u] = par;
    visited[u] = true;
    num[u] = ++ia;
    low[u] = num[u];
    Acnt[u] = A[u], Bcnt[u] = B[u];
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        if (!visited[v])
        {
            h[v] = h[u] + 1;
            dfs(u, v);
            low[u] = min(low[u], low[v]);
            Acnt[u] += Acnt[v];
            Bcnt[u] += Bcnt[v];
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

void not_main()
{
    cin >> n >> m >> k >> l;
    int tmp;
    for (int i = 1; i <= k; ++i)
    {
        cin >> tmp;
        A[tmp] = true;
    }
    for (int i = 1; i <= l; ++i)
    {
        cin >> tmp;
        B[tmp] = true;
    }
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 1);
    for (int i = 1; i <= n; ++i)
    {
        int p = parent[i];
        if (p and low[i] >= num[i])
        {
            if ((!Acnt[i] or Acnt[i] == Acnt[1]) or (!Bcnt[i] or Bcnt[i] == Bcnt[1]))
                ++res;
        }
    }
    cout << res;
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