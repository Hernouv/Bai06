#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n;
long long c[MAXN + 1];
vector<int> adj[MAXN + 1];

int parent[MAXN + 1][20];
int depthArr[MAXN + 1];

int dsuParent[MAXN + 1], dsuSize[MAXN + 1];
int diamA[MAXN + 1], diamB[MAXN + 1];
long long bestDiameter[MAXN + 1];

void dfsLCA(int u, int p, int d)
{
    parent[u][0] = p;
    depthArr[u] = d;
    for (auto &nx : adj[u])
    {
        if (nx == p)
            continue;
        dfsLCA(nx, u, d + 1);
    }
}

void buildLCA()
{
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            else
                parent[i][j] = -1;
        }
    }
}

int LCA(int u, int v)
{
    if (depthArr[u] < depthArr[v])
        swap(u, v);
    int diff = depthArr[u] - depthArr[v];
    for (int i = 0; i < 20; i++)
    {
        if (diff & (1 << i))
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

inline long long dist(int u, int v)
{
    int l = LCA(u, v);
    return (long long)depthArr[u] + depthArr[v] - 2 * depthArr[l];
}

int fnd(int x)
{
    return (dsuParent[x] == x) ? x : dsuParent[x] = fnd(dsuParent[x]);
}

void unite(int a, int b)
{
    a = fnd(a);
    b = fnd(b);
    if (a == b)
        return;

    if (dsuSize[a] < dsuSize[b])
        swap(a, b);

    dsuParent[b] = a;
    dsuSize[a] += dsuSize[b];

    int A1 = diamA[a], A2 = diamB[a];
    int B1 = diamA[b], B2 = diamB[b];

    long long candidates[6];
    candidates[0] = bestDiameter[a];
    candidates[1] = bestDiameter[b];

    candidates[2] = dist(A1, B1);
    candidates[3] = dist(A1, B2);
    candidates[4] = dist(A2, B1);
    candidates[5] = dist(A2, B2);

    long long newDiam = candidates[0];
    int end1 = diamA[a], end2 = diamB[a];

    vector<pair<long long, pair<int, int>>> candList;
    candList.push_back({bestDiameter[a], {A1, A2}});
    candList.push_back({bestDiameter[b], {B1, B2}});
    candList.push_back({dist(A1, B1), {A1, B1}});
    candList.push_back({dist(A1, B2), {A1, B2}});
    candList.push_back({dist(A2, B1), {A2, B1}});
    candList.push_back({dist(A2, B2), {A2, B2}});

    long long maxD = -1;
    int e1 = -1, e2 = -1;
    for (auto &X : candList)
    {
        if (X.first > maxD)
        {
            maxD = X.first;
            e1 = X.second.first;
            e2 = X.second.second;
        }
    }

    diamA[a] = e1;
    diamB[a] = e2;
    bestDiameter[a] = maxD;
}

bool active[MAXN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocess LCA
    for (int i = 1; i <= n; i++)
        parent[i][0] = -1;
    dfsLCA(1, -1, 0);
    buildLCA();

    vector<pair<long long, int>> nodes;
    for (int i = 1; i <= n; i++)
    {
        nodes.push_back({c[i], i});
    }
    sort(nodes.begin(), nodes.end(), greater<pair<long long, int>>());

    for (int i = 1; i <= n; i++)
    {
        dsuParent[i] = i;
        dsuSize[i] = 1;
        diamA[i] = i;
        diamB[i] = i;
        bestDiameter[i] = 0;
        active[i] = false;
    }

    long long ans = 0;

    unordered_map<int, bool> isActive;
    for (auto &nd : nodes)
    {
        long long w = nd.first;
        int u = nd.second;
        active[u] = true;

        for (auto &nx : adj[u])
        {
            if (active[nx])
            {
                unite(u, nx);
            }
        }

        int root = fnd(u);
        long long curDiam = bestDiameter[root];
        long long val = curDiam * w;
        if (val > ans)
            ans = val;
    }

    cout << ans << "\n";
    return 0;
}
