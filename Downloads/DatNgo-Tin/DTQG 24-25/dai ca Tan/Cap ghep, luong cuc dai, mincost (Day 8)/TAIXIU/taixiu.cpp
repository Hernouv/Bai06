#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
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

    void add_edge(int from, int to, ll cap_)
    {
        Edge a = {to, (int)graph[to].size(), cap_};
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
            if (e.cap > 0 and level[e.to] == level[v] + 1)
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

    ll max_flow_func(int s, int t)
    {
        ll flow = 0;
        while (bfs(s, t))
        {
            fill(whole(ptr), 0);
            while (ll pushed = dfs(s, t, LLONG_MAX))
                flow += pushed;
        }
        return flow;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];

    vector<ll> P(N + 1, 0);
    vector<ii> all_rem_games;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i < j)
            {
                if (a[i][j] == 1)
                    P[i] += 3;
                else if (a[i][j] == 0)
                    P[j] += 3;
                else if (a[i][j] == 2)
                    all_rem_games.emplace_back(i, j);
            }
        }
    }
    string res = "";
    for (int T = 1; T <= N; T++)
    {
        ll P_T = P[T];
        int R_T = 0;
        for (int j = 1; j <= N; j++)
        {
            if (j == T)
                continue;
            if (a[T][j] == 2)
                R_T++;
        }
        ll P_T_max = P_T + 3 * (ll)R_T;

        vector<ii> rem_games;
        for (auto &[i, j] : all_rem_games)
        {
            if (i != T and j != T)
            {
                rem_games.emplace_back(i, j);
            }
        }

        int G = rem_games.size();
        int num_teams = N - 1;
        int total_nodes = 1 + G + num_teams + 1;
        int source = 0;
        int sink = total_nodes - 1;

        MaxFlow mf(total_nodes);
        for (int g = 0; g < G; g++)
            mf.add_edge(source, 1 + g, 3);

        unordered_map<int, int> team_nodes;
        int current_node = 1 + G;
        for (int i = 1; i <= N; i++)
        {
            if (i == T)
                continue;
            team_nodes[i] = current_node++;
        }
        for (int g = 0; g < G; g++)
        {
            int i = rem_games[g].fi;
            int j = rem_games[g].se;
            mf.add_edge(1 + g, team_nodes[i], 3);
            mf.add_edge(1 + g, team_nodes[j], 3);
        }
        bool possible = true;
        ll total_capacity = 0;
        for (int i = 1; i <= N; i++)
        {
            if (i == T)
                continue;

            ll cap = P_T_max - P[i];
            if (cap < 0)
            {
                possible = false;
                break;
            }
            mf.add_edge(team_nodes[i], sink, cap);
            total_capacity += cap;
        }
        if (!possible)
        {
            res += '0';
            continue;
        }
        ll total_rem_points = 3LL * G;
        ll flow = mf.max_flow_func(source, sink);
        if (flow >= total_rem_points)
            res += '1';
        else
            res += '0';
    }
    cout << res;
}
