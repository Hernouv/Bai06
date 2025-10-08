#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
vector<ii> graph_single[200010];
vector<ii> graph_multi[200010];
int n;
int s, f, cost_single, cost_multi;
int cost_single_list[200010];
int cost_multi_list[200010];
bool sub1 = true;
queue<int> scanlist;
int dist_source[200010];
int parent[200010];
int ancestor[200010][20];
int go_through_cnt[200010];

void bfs(int index)
{
    dist_source[index] = 0;
    parent[index] = 0;
    scanlist.push(index);
    while (!scanlist.empty())
    {
        int curr_id = scanlist.front();
        scanlist.pop();
        for (auto v : graph_single[curr_id])
        {
            if (v.first != parent[curr_id])
            {
                cost_single_list[v.first] = v.second;
                dist_source[v.first] = dist_source[curr_id] + 1;
                parent[v.first] = curr_id;
                scanlist.push(v.first);
            }
        }
        for (auto v : graph_multi[curr_id])
        {
            if (v.first != parent[curr_id])
                cost_multi_list[v.first] = v.second;
        }
    }
}

void set_ancestor()
{
    ancestor[1][0] = 0;
    for (int i = 2; i <= n; ++i)
        ancestor[i][0] = parent[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
}

int lca(int a, int b)
{
    if (dist_source[a] != dist_source[b])
    {
        int diff;
        if (dist_source[a] > dist_source[b])
        {
            diff = dist_source[a] - dist_source[b];
            int i = 0, t = 1;
            while (diff >= t)
            {
                if ((diff / t) % 2)
                    a = ancestor[a][i];
                i++, t *= 2;
            }
        }
        else
        {
            diff = dist_source[b] - dist_source[a];
            int i = 0, t = 1;
            while (diff >= i)
            {
                if ((diff / t) % 2)
                    b = ancestor[b][i];
                i++, t *= 2;
            }
        }
    }

    int i = 0;

    if (a == b)
        return a;

    while (true)
    {
        while (ancestor[a][i] != ancestor[b][i])
            i++;
        if (i == 0)
            return ancestor[a][0];
        else
        {
            i--;
            a = ancestor[a][i];
            b = ancestor[b][i];
            i = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("friend.inp", "r", stdin);
    freopen("friend.out", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> s >> f >> cost_single >> cost_multi;

        graph_single[s].emplace_back(f, cost_single);
        graph_single[f].emplace_back(s, cost_single);
        graph_multi[s].emplace_back(f, cost_multi);
        graph_multi[f].emplace_back(s, cost_multi);
        cost_multi_list[s] = cost_multi;

        if (cost_single != cost_multi)
            sub1 = false;
    }

    if (sub1)
    {
        long long res = 0;
        for (int i = 1; i < n; ++i)
            res += cost_multi_list[i];
        cout << res;
    }
    else
    {
        long long res = 0;
        bfs(1);
        set_ancestor();
        for (int i = 2; i <= n; ++i)
        {
            int pa = lca(i, i - 1);
            int x = i, y = i - 1;
            while (x != pa)
            {
                go_through_cnt[x]++;
                x = parent[x];
            }
            while (y != pa)
            {
                go_through_cnt[y]++;
                y = parent[y];
            }
        }
        for (int i = 2; i <= n; ++i)
            res += min(cost_single_list[i] * go_through_cnt[i], cost_multi_list[i]);
        cout << res;
    }
    return 0;
}