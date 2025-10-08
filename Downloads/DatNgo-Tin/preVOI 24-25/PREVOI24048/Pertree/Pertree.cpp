#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(__) __.begin(), __.end()

const int nmax = 5e3 + 5;
const int mod = 1e9 + 7;

int n;
int val[nmax];
int par[nmax];
vector<int> adj[nmax];
int res[nmax];

void dfs(int u, int orderId)
{
    do
    {
        res[u] = res[u] + val[orderId] % mod;
        for (int v : adj[u])
            dfs(v, orderId + 1);
    } while (next_permutation(whole(adj[u])));
}

vector<vector<bool>> if_ances;
void dfs_ances_list(vector<int> ances_list, int u)
{
    ances_list.push_back(u);
    for (int v : adj[u])
    {
        for (int x : ances_list)
            if_ances[x][v] = true;
        dfs_ances_list(ances_list, v);
    }
}

void sub1()
{
    if_ances.resize(n + 2, vector<bool>(n + 2, false));
    vector<int> ances_list;
    dfs_ances_list(ances_list, 1);
    vector<int> ids;
    for (int i = 1; i <= n; ++i)
        ids.push_back(i);
    do
    {

        bool valid = true;
        for (int i = n - 1; i >= 1; --i)
            for (int j = i - 1; j >= 0; --j)
                if (if_ances[ids[i]][ids[j]])
                {
                    valid = false;
                    break;
                    break;
                }

        if (!valid)
            continue;

        for (int i = 0; i < n; ++i)
            res[ids[i]] = res[ids[i]] + val[i + 1] % mod;
    } while (next_permutation(whole(ids)));

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}

void not_main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    sub1();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}