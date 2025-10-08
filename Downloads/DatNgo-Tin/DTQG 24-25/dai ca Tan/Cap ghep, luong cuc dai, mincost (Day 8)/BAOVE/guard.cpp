#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(_name) _name.begin(), _name.end()

struct Edge
{
    int to;
    int rev;
    ll cap;
};

class MaxFlow
{
public:
    int N;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    MaxFlow(int N_) : N(N_), graph(N, vector<Edge>()), level(N, -1), ptr(N, 0) {}

    void add_edge(int from, int to, ll cap)
    {
        Edge a = {to, (int)graph[to].size(), cap};
        Edge b = {from, (int)(graph[from].size()), 0};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    bool bfs(int s, int t)
    {
        fill(whole(level), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &e : graph[v])
            {
                if (e.cap > 0 and level[e.to] == -1)
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

    ll dfs(int v, int t, ll pushed)
    {
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < graph[v].size(); cid++)
        {
            Edge &e = graph[v][cid];
            if (e.cap > 0 && level[e.to] == level[v] + 1)
            {
                ll tr = dfs(e.to, t, min(pushed, e.cap));
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

    ll max_flow(int s, int t)
    {
        ll flow = 0;
        while (bfs(s, t))
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, t, 1e18))
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
    int N;
    cin >> N;
    MaxFlow mf(N);
    string line;

    while (cin)
    {
        int u, v;
        ll s;
        if (!(cin >> u >> v >> s))
            break;

        int from = u - 1;
        int to = v - 1;
        mf.add_edge(from, to, s);
    }
    int source = N - 1;
    int sink = 0;
    ll result = mf.max_flow(source, sink);
    cout << result;
}
