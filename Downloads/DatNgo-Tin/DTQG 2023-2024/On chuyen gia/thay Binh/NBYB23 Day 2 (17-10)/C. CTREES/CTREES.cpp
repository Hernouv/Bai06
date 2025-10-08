#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000010];
int dist[1000010];
bool visited[1000010], visited2[1000010];
queue<int> scanlist;
int n, m;
vector<int> diamTree;
// int firstMax, firstMaxv, diamTree;

int bfs(int start)
{
    dist[start] = 1;
    visited[start] = true;
    scanlist.push(start);
    int par;
    while (!scanlist.empty())
    {
        par = scanlist.front();
        scanlist.pop();
        for (auto v : graph[par])
        {
            if (!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[par] + 1;
                scanlist.push(v);
            }
        }
    }
    dist[par] = 1;
    visited2[par] = true;
    scanlist.push(par);
    while (!scanlist.empty())
    {
        par = scanlist.front();
        scanlist.pop();
        for (auto v : graph[par])
        {
            if (!visited2[v])
            {
                visited2[v] = true;
                dist[v] = dist[par] + 1;
                scanlist.push(v);
            }
        }
    }
    return dist[par];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            diamTree.push_back(bfs(i));

    int res = 0;
    for (auto x : diamTree)
        res += x;
    cout << res;
    return 0;
}