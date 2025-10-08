#include <bits/stdc++.h> //hi
using namespace std;

#define int long long

int n, k;
int A[1000010];
vector<int> dinhke[1000010];
void in()
{
    cin >> n >> k;
    for (int i = 1; i <= 2 * k; i++)
    {
        int x;
        cin >> x;
        A[x] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
}

int res = 0;
int S[1000010];

void dfs(int u, int par)
{
    S[u] += A[u];
    for (int v : dinhke[u])
    {
        if (v != par)
        {
            dfs(v, u);
            S[u] += S[v];
        }
    }
    res += min(2 * k - S[u], S[u]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("xdd.inp","r",stdin);
    // freopen("xdd.out","w",stdout);
    in();

    dfs(1, 0);
    cout << res;
    return 0;
}