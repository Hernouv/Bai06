#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int n, m;
bool visited[100010];
int ia = 0, id[100010], low_id[100010];
stack<int> list_v;

void tarjan(int idx)
{
    id[idx] = low_id[idx] = ++ia;
    list_v.push(idx);
    for (auto v : graph[idx])
    {
        if (!visited[v])
        {
            if (!id[v])
            {
                tarjan(v);
                low_id[idx] = min(low_id[idx], low_id[v]);
            }
            else
                low_id[idx] = min(low_id[idx], id[v]);
        }
    }
    if (id[idx] == low_id[idx])
    {
        int t;
        do
        {
            t = list_v.top();
            visited[t] = true;
            cout << t << ' ';
            list_v.pop();
        } while (t != idx);
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            tarjan(i);
    }
    return 0;
}