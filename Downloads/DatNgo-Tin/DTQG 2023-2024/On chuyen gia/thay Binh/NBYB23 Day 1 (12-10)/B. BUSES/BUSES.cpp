#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[200010];
int parent[200010];
int dist_source[200010];
int ancestor[200010][20];
int go_through_cnt[200010];
queue<int> scanlist;

void bfs(int start)
{
    parent[start] = 0;
    dist_source[start] = 0;
    scanlist.push(start);
    while (!scanlist.empty())
    {
        int v_curr_track = scanlist.front();
        scanlist.pop();
        for (auto v : graph[v_curr_track])
        {
            if (v != parent[v_curr_track])
            {
                parent[v] = v_curr_track;
                dist_source[v] = dist_source[v_curr_track] + 1;
                scanlist.push(v);
            }
        }
    }
}

void ancestorBinary()
{
    for (int i = 1; i <= n; ++i)
        ancestor[i][0] = parent[i];

    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
}

int lca(int a, int b)
{
    if (a == b)
        return a;

    if (a == 1 or b == 1)
        return 1;

    if (dist_source[a] != dist_source[b])
    {
        if (dist_source[a] > dist_source[b])
        {
            int diff = dist_source[a] - dist_source[b];
            for (int i = 0; (1 << i) <= diff; ++i)
                if ((diff >> i) & 1)
                    a = ancestor[a][i];
        }
        else
        {
            int diff = dist_source[b] - dist_source[a];
            for (int i = 0; (1 << i) <= diff; ++i)
                if ((diff >> i) & 1)
                    b = ancestor[b][i];
        }
    }

    if (a == b)
        return a;

    int t = 0;
    while (true)
    {
        while (ancestor[a][t] != ancestor[b][t])
            t++;
        if (t == 0)
            return ancestor[a][0];
        else
        {
            t--;
            a = ancestor[a][t];
            b = ancestor[b][t];
            t = 0;
        }
    }
}

void proc(int start)
{
    for (int v : graph[start])
    {
        if (v == parent[start])
            continue;
        proc(v);
        go_through_cnt[start] += go_through_cnt[v];
    }
}

void process()
{
    cin >> n >> m;

    int s, f;
    for (int i = 1; i < n; ++i)
    {
        cin >> s >> f;
        graph[s].push_back(f);
        graph[f].push_back(s);
    }
    bfs(1);
    ancestorBinary();

    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        go_through_cnt[x]++;
        go_through_cnt[y]++;
        int pa = lca(x, y);
        go_through_cnt[pa]--;
        go_through_cnt[parent[pa]]--;
    }

    proc(1);

    for (int i = 1; i <= n; ++i)
        cout << go_through_cnt[i] << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    process();
    return 0;
}