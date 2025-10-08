#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int to;
    int rev;
    int cap;
};

class MaxFlow
{
public:
    int N;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    MaxFlow(int N) : N(N), graph(N, vector<Edge>()), level(N, -1), ptr(N, 0) {}

    void add_edge(int from, int to, int cap)
    {
        Edge a = {to, (int)graph[to].size(), cap};
        Edge b = {from, (int)(graph[from].size()), 0};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v])
            {
                if (e.cap > 0 && level[e.to] == -1)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                    if (e.to == t)
                        break;
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int t, int pushed)
    {
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < graph[v].size(); cid++)
        {
            Edge &e = graph[v][cid];
            if (e.cap > 0 && level[e.to] == level[v] + 1)
            {
                int tr = dfs(e.to, t, min(pushed, e.cap));
                if (tr > 0)
                {
                    e.cap -= tr;
                    graph[e.to][e.rev].cap += tr;
                    return tr;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t)
    {
        int flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INF))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int m, n, k;
    cin >> m >> n >> k;

    vector<int> a(m);
    for (auto &x : a)
        cin >> x;

    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    vector<vector<bool>> hasGas(m + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        hasGas[x][y] = true;
    }

    int source = 0;
    int sink = m + n + 1;
    int totalNodes = m + n + 2;

    MaxFlow mf(totalNodes);

    for (int i = 1; i <= m; ++i)
    {
        mf.add_edge(source, i, a[i - 1]);
    }

    for (int j = 1; j <= n; ++j)
    {
        mf.add_edge(m + j, sink, b[j - 1]);
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (hasGas[i][j])
            {
                mf.add_edge(i, m + j, INF);
            }
        }
    }

    int minCut = mf.max_flow(source, sink);

    cout << minCut;
}
