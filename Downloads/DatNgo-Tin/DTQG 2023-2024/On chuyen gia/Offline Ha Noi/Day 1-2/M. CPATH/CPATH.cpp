#include <bits/stdc++.h> //hi
using namespace std;

#define int long long

int n, m;
vector<pair<int, int>> dinhke[200010];

void in()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dinhke[u].push_back({w, v});
        dinhke[v].push_back({w, u});
    }
}

pair<int, int> par[200010];
bool visited[200010];
int dis[200010];

void bfs_n()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;

    while (q.empty() == false)
    {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        visited[u] = true;

        for (auto &[w, v] : dinhke[u])
        {
            if (visited[v] == true)
                continue;

            dis[v] = d + 1;
            visited[v] = true;
            q.push({v, d + 1});
        }
    }
}

void bfs_1()
{
    vector<int> q;
    q.push_back(1);
    for (int i = 0; i < dis[1]; i++)
    {
        vector<int> tmp;
        int minn = LLONG_MAX;
        for (int u : q)
        {
            for (auto &[w, v] : dinhke[u])
            {
                if (dis[v] + 1 == dis[u])
                {
                    minn = min(minn, w);
                }
            }
        }
        for (int u : q)
        {
            for (auto &[w, v] : dinhke[u])
            {
                if (dis[v] + 1 == dis[u] && w == minn && !visited[v])
                {
                    par[v].first = u;
                    par[v].second = w;
                    tmp.push_back(v);
                    visited[v] = true;
                }
            }
        }

        q.clear();
        q = tmp;
    }
}

signed main()
{
    in();
    memset(visited, false, sizeof(visited));
    bfs_n();
    memset(visited, false, sizeof(visited));
    bfs_1();

    vector<int> res;
    int end = n;
    while (end != 1)
    {
        res.push_back(par[end].second);
        end = par[end].first;
    }

    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int x : res)
        cout << x << ' ';
    return 0;
}