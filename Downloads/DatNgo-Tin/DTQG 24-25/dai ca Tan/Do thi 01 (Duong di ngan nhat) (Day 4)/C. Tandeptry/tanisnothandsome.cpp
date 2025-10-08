#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

typedef struct
{
    int from, to, value, ori;
} ss;

ss edg1[N], edg2[N];
vector<int> edges1[N];
int now_edges1 = 0;
vector<int> edges2[N];
int now_edges2 = 0;

int is_bridge[N] = {0};
long long dis1[N], dis2[N];

void spfa1()
{
    for (int i = 0; i < N; i++)
        dis1[i] = LLONG_MAX / 4;
    int vis[N] = {0};
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    dis1[1] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;

        int Size = edges1[now].size();
        for (int i = 0; i < Size; i++)
        {
            ss e = edg1[edges1[now][i]];
            if (dis1[e.to] > dis1[now] + e.value)
            {
                dis1[e.to] = dis1[now] + e.value;

                if (!vis[e.to])
                {
                    q.push(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }
}

void spfa2()
{
    for (int i = 0; i < N; i++)
        dis2[i] = LLONG_MAX / 4;
    int vis[N] = {0};
    queue<int> q;
    q.push(2);
    vis[2] = 1;
    dis2[2] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;

        int Size = edges2[now].size();
        for (int i = 0; i < Size; i++)
        {
            ss e = edg2[edges2[now][i]];
            if (dis2[e.to] > dis2[now] + e.value)
            {
                dis2[e.to] = dis2[now] + e.value;

                if (!vis[e.to])
                {
                    q.push(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }
}

int dfn[N] = {0}, low[N] = {0}, now_clo = 1;

void tarjan(int x, int pre)
{
    dfn[x] = low[x] = now_clo++;
    int Size = edges2[x].size();

    for (int i = 0; i < Size; i++)
    {
        ss e = edg2[edges2[x][i]];

        if (e.to != pre)
        {
            if (!dfn[e.to])
            {
                tarjan(e.to, x);
                low[x] = min(low[x], low[e.to]);

                if (low[e.to] > dfn[x])
                {
                    is_bridge[e.ori] = 1;
                }
            }
            else
            {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TANDEPTRAI.INP", "r"))
    {
        freopen("TANDEPTRAI.INP", "r", stdin);
        freopen("TANDEPTRAI.OUT", "w", stdout);
    }
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges1[u].push_back(now_edges1);
        edg1[now_edges1++] = (ss){u, v, w, i};
        edges2[v].push_back(now_edges2);
        edg2[now_edges2++] = (ss){v, u, w, i};
    }

    spfa1();
    spfa2();

    long long bestedge = dis1[2];

    for (int i = 0; i < N; i++)
        edges2[i].clear();
    now_edges2 = 0;

    for (int i = 1; i <= n; i++)
    {
        int Size = edges1[i].size();
        for (int j = 0; j < Size; j++)
        {
            int u = i, v = edg1[edges1[i][j]].to, w = edg1[edges1[i][j]].value, ori = edg1[edges1[i][j]].ori;

            if (dis1[u] + dis2[v] + w == bestedge)
            {
                edges2[u].push_back(now_edges2);
                edg2[now_edges2++] = (ss){u, v, 1, ori};
                edges2[v].push_back(now_edges2);
                edg2[now_edges2++] = (ss){v, u, 1, ori};
            }
        }
    }

    tarjan(1, -1);

    int ans[N] = {0};
    for (int i = 1; i <= n; i++)
    {
        int Size = edges1[i].size();
        for (int j = 0; j < Size; j++)
        {
            int u = i, v = edg1[edges1[i][j]].to, w = edg1[edges1[i][j]].value, ori = edg1[edges1[i][j]].ori;

            if (dis1[v] + dis2[u] + w < bestedge)
                ans[ori] = 1;
            else if (is_bridge[ori])
                ans[ori] = -1;
        }
    }

    for (int i = 1; i <= m; i++)
        if (ans[i] == 1)
            cout << "TAN" << '\n';
        else if (ans[i] == -1)
            cout << "TRAI" << '\n';
        else
            cout << "DEP" << '\n';
    return 0;
}
// Anh co ve tu tin voi ve dep trai cua anh =))