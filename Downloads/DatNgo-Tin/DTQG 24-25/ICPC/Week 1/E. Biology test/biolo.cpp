#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, T;
vector<int> graph[nmax];
int inDeg[nmax];
int ances[nmax][18];
int h[nmax];

void dfs(int u)
{
    for (int v : graph[u])
    {
        h[v] = h[u] + 1;
        ances[v][0] = u;
        for (int i = 1; (1 << i) <= n; ++i)
            ances[v][i] = ances[ances[v][i - 1]][i - 1];
        dfs(v);
    }
}

// bool check(int u, int v)
// {
//     if (h[u] >= h[v])
//         return false;
//     int diff = h[v] - h[u];
//     for (int i = 0; (1 << i) <= n; ++i)
//         if (diff & (1 << i))
//             v = ances[v][i];
//     if (u == v)
//         return true;
//     return false;
// }

bool check(int u, int v)
{
    while (v != u and v > 0)
        v = ances[v][0];
    if (u == v)
        return true;
    return false;
}

void not_main()
{
    cin >> n;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        inDeg[tv]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!inDeg[i])
        {
            ances[i][0] = -1;
            h[i] = 1;
            dfs(i);
            break;
        }
    }
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> tu >> tv;
        if (check(tu, tv))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}