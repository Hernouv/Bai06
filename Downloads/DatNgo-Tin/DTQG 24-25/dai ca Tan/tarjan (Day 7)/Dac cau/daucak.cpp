#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int to, id;
};

int N, M, Q;
vector<vector<Edge>> adj;
vector<bool> isBridge;
int timer_counter = 0;
vector<int> tin, low;

void findBridges(int v, int parent_edge)
{
    tin[v] = low[v] = ++timer_counter;
    for (auto &edge : adj[v])
    {
        int to = edge.to;
        int id = edge.id;
        if (id == parent_edge)
            continue;
        if (tin[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            findBridges(to, id);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                isBridge[id] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> Q;
    adj.assign(N + 1, vector<Edge>());
    isBridge.assign(M, false);
    vector<pair<int, int>> inputEdges(M);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        inputEdges[i] = {u, v};
        adj[u].push_back(Edge{v, i});
        adj[v].push_back(Edge{u, i});
    }

    tin.assign(N + 1, 0);
    low.assign(N + 1, 0);

    for (int v = 1; v <= N; v++)
    {
        if (!tin[v])
        {
            findBridges(v, -1);
        }
    }

    int numComponents = 0;
    vector<int> component(N + 1, 0);

    function<void(int)> dfs = [&](int v)
    {
        component[v] = numComponents;
        for (auto &edge : adj[v])
        {
            int to = edge.to;
            if (component[to] == 0 && !isBridge[edge.id])
            {
                dfs(to);
            }
        }
    };

    for (int v = 1; v <= N; v++)
    {
        if (component[v] == 0)
        {
            numComponents++;
            dfs(v);
        }
    }

    vector<vector<int>> bridgeTree(numComponents + 1, vector<int>());
    for (int i = 0; i < M; i++)
    {
        if (isBridge[i])
        {
            int u = inputEdges[i].first;
            int v = inputEdges[i].second;
            int cu = component[u];
            int cv = component[v];
            bridgeTree[cu].push_back(cv);
            bridgeTree[cv].push_back(cu);
        }
    }

    vector<int> parent_bt(numComponents + 1, -1);
    vector<int> depth_bt(numComponents + 1, 0);
    vector<int> heavy(numComponents + 1, -1);
    vector<int> head_bt(numComponents + 1, -1);
    vector<int> pos_bt(numComponents + 1, 0);
    vector<int> size_bt(numComponents + 1, 1);

    function<int(int)> dfs_size_bt = [&](int v) -> int
    {
        int max_size = 0;
        for (auto &to : bridgeTree[v])
        {
            if (to != parent_bt[v])
            {
                parent_bt[to] = v;
                depth_bt[to] = depth_bt[v] + 1;
                size_bt[v] += dfs_size_bt(to);
                if (size_bt[to] > max_size)
                {
                    max_size = size_bt[to];
                    heavy[v] = to;
                }
            }
        }
        return size_bt[v];
    };

    dfs_size_bt(component[1]);

    int current_pos = 1;
    function<void(int, int)> dfs_decompose_bt = [&](int v, int h)
    {
        head_bt[v] = h;
        pos_bt[v] = current_pos++;
        if (heavy[v] != -1)
        {
            dfs_decompose_bt(heavy[v], h);
            for (auto &to : bridgeTree[v])
            {
                if (to != parent_bt[v] && to != heavy[v])
                {
                    dfs_decompose_bt(to, to);
                }
            }
        }
    };

    dfs_decompose_bt(component[1], component[1]);

    vector<int> sum_depth(numComponents + 1, 0);
    function<void(int)> dfs_sum_depth = [&](int v)
    {
        for (auto &to : bridgeTree[v])
        {
            if (to != parent_bt[v])
            {
                sum_depth[to] = sum_depth[v] + 1;
                dfs_sum_depth(to);
            }
        }
    };

    dfs_sum_depth(component[1]);

    int LOG = 20;
    vector<vector<int>> up(LOG, vector<int>(numComponents + 1, -1));
    for (int v = 1; v <= numComponents; v++)
        up[0][v] = parent_bt[v];
    for (int k = 1; k < LOG; k++)
    {
        for (int v = 1; v <= numComponents; v++)
        {
            if (up[k - 1][v] != -1)
            {
                up[k][v] = up[k - 1][up[k - 1][v]];
            }
        }
    }

    auto getLCA = [&](int u, int v) -> int
    {
        if (depth_bt[u] < depth_bt[v])
            swap(u, v);
        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[k][u] != -1 && depth_bt[up[k][u]] >= depth_bt[v])
            {
                u = up[k][u];
            }
        }
        if (u == v)
            return u;
        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[k][u] != -1 && up[k][u] != up[k][v])
            {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return parent_bt[u];
    };

    auto getSegments = [&](int u, int v) -> vector<pair<int, int>>
    {
        vector<pair<int, int>> segments;
        while (head_bt[u] != head_bt[v])
        {
            if (depth_bt[head_bt[u]] > depth_bt[head_bt[v]])
            {
                segments.emplace_back(pos_bt[head_bt[u]], pos_bt[u]);
                u = parent_bt[head_bt[u]];
            }
            else
            {
                segments.emplace_back(pos_bt[head_bt[v]], pos_bt[v]);
                v = parent_bt[head_bt[v]];
            }
        }
        if (depth_bt[u] > depth_bt[v])
        {
            segments.emplace_back(pos_bt[v] + 1, pos_bt[u]);
        }
        else
        {
            segments.emplace_back(pos_bt[u] + 1, pos_bt[v]);
        }
        return segments;
    };

    while (Q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ta = component[a];
        int tb = component[b];
        int tc = component[c];
        int td = component[d];

        vector<pair<int, int>> seg_ab = getSegments(ta, tb);
        vector<pair<int, int>> seg_cd = getSegments(tc, td);

        sort(seg_ab.begin(), seg_ab.end());
        sort(seg_cd.begin(), seg_cd.end());

        int count_overlap = 0;
        int i = 0, j = 0;
        while (i < seg_ab.size() && j < seg_cd.size())
        {
            int l1 = seg_ab[i].first;
            int r1 = seg_ab[i].second;
            int l2 = seg_cd[j].first;
            int r2 = seg_cd[j].second;

            if (r1 < l2)
            {
                i++;
            }
            else if (r2 < l1)
            {
                j++;
            }
            else
            {
                int overlap_l = max(l1, l2);
                int overlap_r = min(r1, r2);
                if (overlap_l <= overlap_r)
                {
                    count_overlap += (overlap_r - overlap_l + 1);
                }
                if (r1 < r2)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        int lca_cd = getLCA(tc, td);
        int f_cd = sum_depth[tc] + sum_depth[td] - 2 * sum_depth[lca_cd];

        cout << (f_cd - count_overlap) << "\n";
    }
}
