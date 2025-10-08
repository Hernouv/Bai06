#include <bits/stdc++.h>
using namespace std;

const int nmax = 5e5 + 10;
int s, d;
int val[nmax];
int parent[nmax];
vector<int> graph[nmax];

void dfs(int st)
{
    for (int v : graph[st])
    {
        val[v] += val[st];
        dfs(v);
    }
}

void proc_type1(int pre, int st, int t_val)
{
    for (int v : graph[st])
        if (v != pre)
            val[v] -= t_val;
    if (st != 1)
        proc_type1(st, parent[st], t_val);
}

void not_main()
{
    cin >> s >> d;
    int p;
    for (int i = 2; i <= s; ++i)
    {
        cin >> p;
        parent[i] = p;
        graph[p].push_back(i);
    }

    int q_type, t_u, k;
    for (int i = 1; i <= d; ++i)
    {
        cin >> q_type >> t_u >> k;
        if (q_type == 2)
            val[t_u] += k;
        else if (q_type == 1)
        {
            proc_type1(0, t_u, k);
            val[1] += k;
        }
    }

    dfs(1);

    for (int i = 1; i <= s; ++i)
        cout << val[i] << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GROWING.INP", "r"))
    {
        freopen("GROWING.INP", "r", stdin);
        freopen("GROWING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
