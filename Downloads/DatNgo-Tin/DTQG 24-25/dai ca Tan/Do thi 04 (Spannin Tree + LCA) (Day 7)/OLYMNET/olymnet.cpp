#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    bool inMST;
    Edge(int a, int b, int c) : u(a), v(b), w(c), inMST(false) {}
};

bool cmpEdge(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

struct DSU
{
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_set(int x)
    {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }
    bool union_set(int x, int y)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx == fy)
            return false;
        if (rank[fx] < rank[fy])
        {
            parent[fx] = fy;
        }
        else
        {
            parent[fy] = fx;
            if (rank[fx] == rank[fy])
                rank[fx]++;
        }
        return true;
    }
};

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end(), cmpEdge);

    DSU dsu1(n);
    long long mst1 = 0;
    vector<int> mstEdgesIndices;
    for (int i = 0; i < m; i++)
    {
        if (dsu1.union_set(edges[i].u, edges[i].v))
        {
            mst1 += edges[i].w;
            mstEdgesIndices.push_back(i);
            edges[i].inMST = true;
            if (mstEdgesIndices.size() == n - 1)
                break;
        }
    }

    long long mst2 = LLONG_MAX;
    for (auto &idx : mstEdgesIndices)
    {
        DSU dsu2(n);
        long long currentCost = 0;
        int edgesUsed = 0;
        for (int i = 0; i < m; i++)
        {
            if (i == idx)
                continue;
            if (dsu2.union_set(edges[i].u, edges[i].v))
            {
                currentCost += edges[i].w;
                edgesUsed++;
                if (edgesUsed == n - 1)
                    break;
            }
        }
        if (edgesUsed == n - 1)
        {
            mst2 = min(mst2, currentCost);
        }
    }

    cout << mst1 << " " << mst2;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("OLYMNET.INP", "r"))
    {
        freopen("OLYMNET.INP", "r", stdin);
        freopen("OLYMNET.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
