#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXLOG = 17;
const long long INF = 1LL << 60;

vector<tuple<int, int, long long>> extraEdges;
vector<pair<int, int>> edgeList;
map<pair<int, int>, long long> edgeWeight;

struct Edge
{
    int to;
    long long weight;
};

int n, m;
vector<Edge> tree[MAXN];
int depth[MAXN];
int parent[MAXN][MAXLOG];
long long distToRoot[MAXN];

void dfs(int u, int p)
{
    for (Edge e : tree[u])
    {
        int v = e.to;
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            distToRoot[v] = distToRoot[u] + e.weight;
            parent[v][0] = u;
            for (int i = 1; i < MAXLOG; ++i)
            {
                if (parent[v][i - 1] != -1)
                    parent[v][i] = parent[parent[v][i - 1]][i - 1];
                else
                    parent[v][i] = -1;
            }
            dfs(v, u);
        }
    }
}

int getLCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = MAXLOG - 1; i >= 0; --i)
    {
        if (parent[u][i] != -1 && depth[parent[u][i]] >= depth[v])
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i = MAXLOG - 1; i >= 0; --i)
    {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
            u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}

long long getTreeDistance(int u, int v)
{
    int lca = getLCA(u, v);
    return distToRoot[u] + distToRoot[v] - 2 * distToRoot[lca];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (edgeWeight.count({u, v}))
        {
            edgeWeight[{u, v}] = min(edgeWeight[{u, v}], w);
            edgeWeight[{v, u}] = min(edgeWeight[{v, u}], w);
        }
        else
        {
            edgeWeight[{u, v}] = w;
            edgeWeight[{v, u}] = w;
            edgeList.push_back({u, v});
        }
    }

    vector<int> parentDSU(n + 1);
    for (int i = 1; i <= n; ++i)
        parentDSU[i] = i;

    function<int(int)> findSet = [&](int u)
    {
        if (parentDSU[u] != u)
            parentDSU[u] = findSet(parentDSU[u]);
        return parentDSU[u];
    };

    int treeEdges = 0;
    for (auto &e : edgeList)
    {
        int u = e.first, v = e.second;
        if (findSet(u) != findSet(v))
        {
            parentDSU[findSet(u)] = findSet(v);
            tree[u].push_back({v, edgeWeight[{u, v}]});
            tree[v].push_back({u, edgeWeight[{u, v}]});
            ++treeEdges;
        }
        else
        {
            extraEdges.push_back({u, v, edgeWeight[{u, v}]});
        }
    }

    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    distToRoot[1] = 0;
    dfs(1, -1);

    map<int, int> nodeToIndex;
    vector<int> S;
    for (auto &e : extraEdges)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        if (!nodeToIndex.count(u))
        {
            nodeToIndex[u] = S.size();
            S.push_back(u);
        }
        if (!nodeToIndex.count(v))
        {
            nodeToIndex[v] = S.size();
            S.push_back(v);
        }
    }
    int sSize = S.size();

    vector<vector<long long>> dist_S(sSize, vector<long long>(sSize, INF));
    for (int i = 0; i < sSize; ++i)
        dist_S[i][i] = 0;
    for (int i = 0; i < sSize; ++i)
    {
        for (int j = i + 1; j < sSize; ++j)
        {
            int u = S[i];
            int v = S[j];
            long long treeDist = getTreeDistance(u, v);
            dist_S[i][j] = dist_S[j][i] = treeDist;
        }
    }

    for (auto &e : extraEdges)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        long long w = get<2>(e);
        int idx_u = nodeToIndex[u];
        int idx_v = nodeToIndex[v];
        dist_S[idx_u][idx_v] = dist_S[idx_v][idx_u] = min(dist_S[idx_u][idx_v], w);
    }

    for (int k = 0; k < sSize; ++k)
    {
        for (int i = 0; i < sSize; ++i)
        {
            for (int j = 0; j < sSize; ++j)
            {
                if (dist_S[i][k] + dist_S[k][j] < dist_S[i][j])
                {
                    dist_S[i][j] = dist_S[i][k] + dist_S[k][j];
                }
            }
        }
    }

    vector<vector<long long>> dist_u_s(n + 1, vector<long long>(sSize));
    for (int u = 1; u <= n; ++u)
    {
        for (int idx = 0; idx < sSize; ++idx)
        {
            int s = S[idx];
            dist_u_s[u][idx] = getTreeDistance(u, s);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        long long minDist = getTreeDistance(u, v);
        for (int i = 0; i < sSize; ++i)
        {
            for (int j = 0; j < sSize; ++j)
            {
                long long totalDist = dist_u_s[u][i] + dist_S[i][j] + dist_u_s[v][j];
                if (totalDist < minDist)
                {
                    minDist = totalDist;
                }
            }
        }
        cout << minDist << '\n';
    }

    return 0;
}
