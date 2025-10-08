#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

const int N = 1e6 + 7;

int n, m, k;
bool spe[N], used[N];
int root[N], sz[N], cnt[N];
vector<ii> e, adj[N];

int find(int u)
{
    return root[u] ? root[u] = find(root[u]) : u;
}

bool join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        root[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

void dfs(int u, int p)
{
    cnt[u] = spe[u];
    for (ii i : adj[u])
    {
        int v = i.S, id = i.F;
        if (v == p)
            continue;
        dfs(v, u);
        if (cnt[v])
            used[id] = 1;
        cnt[u] += cnt[v];
    }
}

void proc()
{
    cin >> n >> m >> k;
    For(i, 1, n) sz[i] = 1;
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        if (join(u, v))
        {
            adj[u].pb({i, v});
            adj[v].pb({i, u});
        }
    }

    int x;
    For(i, 1, k)
    {
        cin >> x;
        spe[x] = 1;
    }
    dfs(x, -1);
    For(i, 1, m) cout << used[i] << ' ';
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    proc();
    return 0;
}