#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int LM[2][100010];
int n, m, d;
int AffectedByBook[100010];
int down[100010], up[100010];
int parent[100010];

void dfs_successor(int id)
{
    if (AffectedByBook[id])
        down[id] = 0;
    else
        down[id] = -100000;
    LM[0][id] = -100000;
    LM[1][id] = -100000;
    for (auto v : graph[id])
    {
        if (v != parent[id])
        {
            parent[v] = id;
            dfs_successor(v);
            if (down[v] > LM[1][id])
            {
                if (down[v] > LM[0][id])
                {
                    LM[1][id] = LM[0][id];
                    LM[0][id] = down[v];
                }
                else
                    LM[1][id] = down[v];
                down[id] = LM[0][id] + 1;
            }
        }
    }
}

void dfs_predecessor(int id)
{
    int v;
    if (id == 1)
    {
        if (AffectedByBook[1])
            up[1] = 0;
        else
            up[1] = -100000;
    }
    else
    {
        v = parent[id];
        up[id] = up[v] + 1;
        if ((AffectedByBook[id]) and (up[id] < 0))
            up[id] = 0;
        if (LM[0][v] == down[id])
            up[id] = max(up[id], LM[1][v] + 2);
        else
            up[id] = max(up[id], LM[0][v] + 2);
    }
    for (auto x : graph[id])
        if (x != parent[id])
            dfs_predecessor(x);
}

int main()
{
    if (fopen("book.inp", "r"))
    {
        freopen("book.inp", "r", stdin);
        freopen("book.out", "w", stdout);
    }
    int x, y;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i)
        AffectedByBook[i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x;
        AffectedByBook[x] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs_successor(1);
    dfs_predecessor(1);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (down[i] <= d and up[i] <= d)
            ++res;
    cout << res;
    return 0;
}