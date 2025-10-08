#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
bool visited[100010], visited2[100010];
int dist[100010];
int n;
queue<int> scanlist;

int bfs(int id)
{
    visited[id] = true;
    scanlist.push(id);
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
                scanlist.push(v);
            }
        }
    }
    dist[par] = 0;
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
    if (fopen("PT07Z.INP", "r"))
    {
        freopen("PT07Z.INP", "r", stdin);
        freopen("PT07Z.OUT", "w", stdout);
    }
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << bfs(1);
}