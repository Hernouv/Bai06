#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
int parent[MAXN];
int c[MAXN];
int t[MAXN];

int num_v[MAXN];
vector<int> visited;

void not_main()
{
    cin >> n >> q;
    parent[1] = 0;
    for (int i = 2; i <= n; ++i)
        cin >> parent[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int v, t_new;
            cin >> v >> t_new;
            t[v] = t_new;
        }
        else if (x == 2)
        {
            int tt, k;
            cin >> tt >> k;
            vector<int> treasures(k);
            for (int i = 0; i < k; ++i)
                cin >> treasures[i];

            int max_tax = 0;
            visited.clear();

            for (int i = 0; i < k; ++i)
            {
                int node = treasures[i];
                while (node != 0)
                {
                    if (t[node] == tt)
                    {
                        if (num_v[node] == 0)
                            visited.push_back(node);
                        num_v[node]++;
                    }
                    node = parent[node];
                }
            }

            for (int node : visited)
            {
                int tax = c[node] * num_v[node];
                if (tax > max_tax)
                    max_tax = tax;
                num_v[node] = 0;
            }

            cout << max_tax << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("treasure.inp", "r"))
    {
        freopen("treasure.inp", "r", stdin);
        freopen("treasure.out", "w", stdout);
    }
    not_main();
    return 0;
}
