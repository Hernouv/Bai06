#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
vector<int> graph[nmax];
int n;

int last_out;
int parent[nmax];
int h[nmax];
queue<int> scan;

void bfs(int u)
{
    scan.push(u);
    while (!scan.empty())
    {
        int curr_v = scan.front();
        last_out = curr_v;
        scan.pop();
        for (int v : graph[curr_v])
        {
            if (v != parent[curr_v])
            {
                parent[v] = curr_v;
                h[v] = h[u] + 1;
                scan.push(v);
            }
        }
    }

    fill(h + 1, h + n + 1, 0);
    fill(parent + 1, parent + n + 1, 0);
    scan.push(last_out);
    while (!scan.empty())
    {
        int curr_v = scan.front();
        last_out = curr_v;
        scan.pop();
        for (int v : graph[curr_v])
        {
            if (v != parent[curr_v])
            {
                parent[v] = curr_v;
                h[v] = h[curr_v] + 1;
                scan.push(v);
            }
        }
    }
}

void not_main()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    cout << h[last_out];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}