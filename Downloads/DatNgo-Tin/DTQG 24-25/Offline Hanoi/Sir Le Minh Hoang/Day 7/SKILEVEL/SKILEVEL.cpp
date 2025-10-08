#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const int N = 505;
const int M = 1e6 + 10;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

int n, m, T, sz = 0;
int lab[M], res[M], a[N][N];
vector<int> vec[M];
struct edge
{
    int u, v;
    ll w;
    bool operator<(const edge &o) const
    {
        return w < o.w;
    }
} E[M];

int root(int v)
{
    return lab[v] < 0 ? v : lab[v] = root(lab[v]);
}

void dsu(int u, int v, int w)
{
    u = root(u);
    v = root(v);
    if (u == v)
        return;
    if (lab[u] > lab[v])
        swap(u, v);

    int cur_sz = -(lab[u] + lab[v]);
    if (-lab[u] < T && cur_sz >= T)
    {
        for (int x : vec[u])
            res[x] = w;
    }
    if (-lab[v] < T)
    {
        for (int x : vec[v])
            vec[u].push_back(x);
        if (cur_sz >= T)
            for (int x : vec[v])
                res[x] = w;
    }
    lab[u] += lab[v];
    lab[v] = u;
}

#define num(i, j) ((i - 1) * n + j)
void not_main()
{
    cin >> m >> n >> T;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int id = num(i, j);
            for (int k = 0; k <= 3; ++k)
            {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii >= 1 && ii <= m && jj >= 1 && jj <= n)
                {
                    E[++sz] = {id, num(ii, jj), abs(a[ii][jj] - a[i][j])};
                }
            }
            vec[id].push_back(id);
        }

    memset(lab, -1, sizeof(lab));
    sort(E + 1, E + sz + 1);
    for (int i = 1; i <= sz; ++i)
        dsu(E[i].u, E[i].v, E[i].w);

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            if (x == 1)
                ans += res[num(i, j)];
        }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SKILEVEL.INP", "r"))
    {
        freopen("SKILEVEL.INP", "r", stdin);
        freopen("SKILEVEL.OUT", "w", stdout);
    }
    not_main();
    return 0;
}