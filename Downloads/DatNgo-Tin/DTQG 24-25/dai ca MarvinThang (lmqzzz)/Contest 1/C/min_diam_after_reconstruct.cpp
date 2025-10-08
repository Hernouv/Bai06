#include <bits/stdc++.h>
using namespace std;

#define MAX 300000

const int inf = 1000000000;

int n;
vector<int> adj[MAX];
int qHead, qTail;
int q[MAX];
int par[MAX];
int dist[MAX];

int h[MAX][3];
int hNodes[MAX][3];
int down_diam[MAX];
int bestDown_diam[MAX][2];
int down_diamNodes[MAX][2];
int diam_res[MAX];
int path_res[MAX];

void bfs(int start, int excludeNode)
{
    for (int i = 0; i < n; ++i)
    {
        par[i] = -1;
        dist[i] = inf;
    }

    if (excludeNode >= 0)
        dist[excludeNode] = -inf;

    qHead = qTail = 0;

    dist[start] = 0;
    q[qTail++] = start;
    while (qHead != qTail)
    {
        int x = q[qHead++];
        for (int it : adj[x])
        {
            if (dist[it] <= dist[x] + 1)
                continue;
            par[it] = x;
            dist[it] = dist[x] + 1;
            q[qTail++] = it;
        }
    }
}

int half_diam(int A, int excludeNode)
{
    bfs(A, excludeNode);
    int B = q[qHead - 1];
    bfs(B, excludeNode);
    int C = q[qHead - 1];
    int D = C;
    for (int i = 0; i < dist[C] / 2; ++i)
        D = par[D];
    return D;
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0, -1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            h[i][j] = 0;
            hNodes[i][j] = -1;
        }
        for (int j = 0; j < 2; ++j)
        {
            bestDown_diam[i][j] = 0;
            down_diamNodes[i][j] = -1;
        }
        down_diam[i] = 0;
        path_res[i] = 0;
        diam_res[i] = 0;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int x = q[i];

        for (int it : adj[x])
        {
            if (it == par[x])
                continue;

            int V = h[it][0] + 1;
            for (int j = 2; j >= 0; --j)
                if (V > h[x][j])
                {
                    if (j + 1 < 3)
                    {
                        h[x][j + 1] = h[x][j];
                        hNodes[x][j + 1] = hNodes[x][j];
                    }
                    h[x][j] = V;
                    hNodes[x][j] = it;
                }
                else
                    break;

            int D = down_diam[it];
            for (int j = 1; j >= 0; --j)
                if (D > bestDown_diam[x][j])
                {
                    if (j + 1 < 2)
                    {
                        bestDown_diam[x][j + 1] = bestDown_diam[x][j];
                        down_diamNodes[x][j + 1] = down_diamNodes[x][j];
                    }
                    bestDown_diam[x][j] = D;
                    down_diamNodes[x][j] = it;
                }
                else
                    break;
        }
        down_diam[x] = bestDown_diam[x][0];
        down_diam[x] = max(down_diam[x], h[x][0] + h[x][1]);
    }

    int res = inf, resNode;
    for (int i = 0; i < n; ++i)
    {
        int x = q[i];
        int y = par[x];

        if (y == -1)
        {
            path_res[x] = -inf;
            diam_res[x] = -inf;
            continue;
        }

        path_res[x] = max(path_res[x], 1 + path_res[y]);

        if (hNodes[y][0] == x)
            path_res[x] = max(path_res[x], h[y][1]);
        else
            path_res[x] = max(path_res[x], h[y][0]);

        diam_res[x] = max(diam_res[x], diam_res[y]);

        if (hNodes[y][0] == x)
        {
            diam_res[x] = max(diam_res[x], (1 + path_res[y]) + h[y][1]);
            diam_res[x] = max(diam_res[x], h[y][1] + h[y][2]);
        }
        else if (hNodes[y][1] == x)
        {
            diam_res[x] = max(diam_res[x], (1 + path_res[y]) + h[y][0]);
            diam_res[x] = max(diam_res[x], h[y][0] + h[y][2]);
        }
        else
        {
            diam_res[x] = max(diam_res[x], (1 + path_res[y]) + h[y][0]);
            diam_res[x] = max(diam_res[x], h[y][0] + h[y][1]);
        }

        if (down_diamNodes[y][0] == x)
            diam_res[x] = max(diam_res[x], bestDown_diam[y][1]);
        else
            diam_res[x] = max(diam_res[x], bestDown_diam[y][0]);

        int new_diam = max(down_diam[x], diam_res[x]);
        new_diam = max(new_diam, 1 + (down_diam[x] + 1) / 2 + (diam_res[x] + 1) / 2);

        if (new_diam < res)
        {
            res = new_diam;
            resNode = x;
        }
    }

    int A = resNode, B = par[resNode];
    cout << res << '\n';
    cout << A + 1 << ' ' << B + 1 << '\n';
    cout << half_diam(A, B) + 1 << ' ' << half_diam(B, A) + 1;

    return 0;
}
