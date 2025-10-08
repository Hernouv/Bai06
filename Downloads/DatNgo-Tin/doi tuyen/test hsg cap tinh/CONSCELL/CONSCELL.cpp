#include <bits/stdc++.h>
using namespace std;

int id = 1, id_arr[1002][1002], val[1002][1002], in[1002][1002];
int m, n;
vector<int> graph[1000001];
int res = 0;

set<int> proc;
void dfs_proc(int s)
{
    proc.insert(s);
    for (auto x : graph[s])
        dfs_proc(x);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CONSCELL.INP", "r", stdin);
    freopen("CONSCELL.OUT", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            id_arr[i][j] = id++;

    for (int i = 1; i <= n; ++i)
        val[0][i] = val[m + 1][i] = 0x3f;
    for (int i = 1; i <= m; ++i)
        val[i][0] = val[i][n + 1] = 0x3f;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> val[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int pos = id_arr[i][j];
            if (val[i][j] == val[i + 1][j] + 1)
            {
                graph[id_arr[i + 1][j]].push_back(pos);
                in[i][j]++;
            }
            if (val[i][j] == val[i - 1][j] + 1)
            {
                graph[id_arr[i - 1][j]].push_back(pos);
                in[i][j]++;
            }
            if (val[i][j] == val[i][j + 1] + 1)
            {
                graph[id_arr[i][j + 1]].push_back(pos);
                in[i][j]++;
            }
            if (val[i][j] == val[i][j - 1] + 1)
            {
                graph[id_arr[i][j - 1]].push_back(pos);
                in[i][j]++;
            }
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (!in[i][j])
            {
                proc.clear();
                dfs_proc(id_arr[i][j]);
                int sz = proc.size();
                res = max(res, sz);
            }
    cout << res;
    return 0;
}