#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> graph[MAXN], graphT[MAXN], hadvis;
bool visited[MAXN];
int comp[MAXN], out[MAXN];

void dfs1(int u)
{
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); ++i)
    {
        if (!visited[graph[u][i]])
        {
            dfs1(graph[u][i]);
        }
    }
    hadvis.push_back(u);
}

void dfs2(int u, int c)
{
    visited[u] = false;
    comp[u] = c;
    for (int i = 0; i < graphT[u].size(); ++i)
    {
        if (visited[graphT[u][i]])
        {
            dfs2(graphT[u][i], c);
        }
    }
}

void not_main()
{
}

int main()
{
    cin.tie()->sync_with_stdio(false);
    if (fopen("CENCITY.INP", "r"))
    {
        freopen("CENCITY.INP", "r", stdin);
        freopen("CENCITY.OUT", "w", stdout);
    }

    int t, i, N, v, j, cntltm, M, u, cnt1, cnt2;
    cin >> N >> M;
    for (i = 1; i <= N; ++i)
    {
        visited[i] = false;
        graph[i].clear();
        graphT[i].clear();
        out[i] = 0;
    }

    for (i = 1; i <= M; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graphT[v].push_back(u);
    }

    for (i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    cntltm = 0;
    for (i = hadvis.size() - 1; i >= 0; --i)
    {
        if (visited[hadvis[i]])
        {
            dfs2(hadvis[i], cntltm++);
        }
    }

    for (i = 1; i <= N; ++i)
    {
        for (j = 0; j < graph[i].size(); ++j)
        {
            if (comp[i] != comp[graph[i][j]])
            {
                out[comp[i]] = 1;
            }
        }
    }

    cnt1 = 0;
    for (i = 0; i < cntltm; ++i)
    {
        if (out[i] == 0)
        {
            ++cnt1;
        }
    }
    if (cnt1 > 1)
    {
        cout << 0;
    }

    else
    {
        cnt2 = 0;
        for (i = 1; i <= N; ++i)
        {
            if (out[comp[i]] == 0)
            {
                ++cnt2;
            }
        }
        cout << cnt2 << '\n';
        for (i = 1; i <= N; ++i)
        {
            if (out[comp[i]] == 0)
            {
                cout << i << ' ';
            }
        }
    }
    return 0;
}
