#include <bits/stdc++.h>
using namespace std;

#define whole_reverse(__) __.cbegin(), __.cend()

vector<vector<int>> child, vx_at_depth;
vector<int> in, out, h;
int timer;

void dfs(const int u)
{
    in[u] = timer++;
    vx_at_depth[h[u]].push_back(in[u]);
    for (const int v : child[u])
    {
        h[v] = h[u] + 1;
        dfs(v);
    }
    out[u] = timer++;
}

int32_t main()
{
    int N;
    cin >> N;
    child = vx_at_depth = vector<vector<int>>(N);
    in = out = h = vector<int>(N);
    for (int i = 1; i < N; ++i)
    {
        int p;
        cin >> p;
        child[p - 1].push_back(i);
    }
    dfs(0);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int u, d;
        cin >> u >> d;
        u -= 1;
        const auto &v = vx_at_depth[d];
        cout << lower_bound(whole_reverse(v), out[u]) - lower_bound(whole_reverse(v), in[u]) << '\n';
    }
    return 0;
}