#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int parent[100010];
bool visited[100010];
bool revisited[1000010];
queue<int> scanlist;
bool solved;
int n, m;
int trackback1, trackback2;
queue<int> half1;
stack<int> half2;
vector<int> cycle;

void bfs(int index)
{
    visited[index] = true;
    scanlist.push(index);
    while (!scanlist.empty())
    {
        int pa = scanlist.front();
        scanlist.pop();
        for (auto v : graph[pa])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = pa;
                scanlist.push(v);
            }
            else if (v != parent[pa])
            {
                solved = true;
                trackback1 = pa;
                trackback2 = v;
                return;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen
    cin >> n >> m;
    int s, f;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> f;
        graph[s].push_back(f);
        graph[f].push_back(s);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i] and !solved)
        {
            parent[i] = 0;
            bfs(i);
        }
    }
    if (!solved)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        parent[1] = 0;
        while (trackback1 != 0)
        {
            half1.push(trackback1);
            revisited[trackback1] = true;
            trackback1 = parent[trackback1];
        }
        while (!revisited[trackback2])
        {
            half2.push(trackback2);
            revisited[trackback2] = true;
            trackback2 = parent[trackback2];
        }
        half2.push(trackback2);
        int stop = half2.top();
        while (!half2.empty())
        {
            cycle.push_back(half2.top());
            half2.pop();
        }
        while (half1.front() != stop)
        {
            cycle.push_back(half1.front());
            half1.pop();
        }
        cycle.push_back(stop);
        cout << cycle.size() << '\n';
        for (auto x : cycle)
        {
            cout << x << ' ';
        }
    }
    return 0;
}
