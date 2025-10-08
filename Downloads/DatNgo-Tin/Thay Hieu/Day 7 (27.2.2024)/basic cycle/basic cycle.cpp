#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n;
vector<int> graph[nmax];
int parent[nmax];
bool cycle_available;
int st, en;

void print_cycle()
{
    std::cout << "YES" << '\n';
    std::cout << en << ' ';
    while (st != en)
    {
        std::cout << st << ' ';
        st = parent[st];
    }
    std::cout << st;
}

void dfs(int inp)
{
    for (int v : graph[inp])
    {
        if (!parent[v])
        {
            parent[v] = inp;
            dfs(v);
        }
        else if (parent[inp] != v)
        {
            cycle_available = true;
            st = v;
            en = inp;
            return;
        }
    }
}

void not_main()
{
    cin >> n;
    int u, v;
    while (cin >> u >> v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[1] = -1;
    dfs(1);
    if (!cycle_available)
        std::cout << "NO";
    else
        print_cycle();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("cycle.inp", "r"))
    {
        freopen("cycle.inp", "r", stdin);
        freopen("cycle.out", "w", stdout);
    }
    not_main();
    return 0;
}