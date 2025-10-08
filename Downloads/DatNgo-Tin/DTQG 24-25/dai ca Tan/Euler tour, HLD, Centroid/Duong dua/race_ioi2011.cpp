#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 5;
const int inf = 1e6 + 5;

struct Node
{
    int x, y;
};

int n, k, e_cnt, tot, cent, ans;
int nxt[nmax << 1], to[nmax << 1], w[nmax << 1], head[nmax], vis[nmax];
int dis[nmax], siz[nmax], mx[nmax], dep[nmax];
int ba[inf], A[nmax];
vector<Node> Q;

void add(int x, int y, int z)
{
    to[++e_cnt] = y;
    nxt[e_cnt] = head[x];
    w[e_cnt] = z;
    head[x] = e_cnt;
}

void get_cent(int u, int fa)
{
    siz[u] = 1;
    mx[u] = 0;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (fa == v || vis[v])
            continue;
        get_cent(v, u);
        siz[u] += siz[v];
        mx[u] = max(mx[u], siz[v]);
    }
    mx[u] = max(mx[u], tot - siz[u]);
    if (mx[cent] > mx[u])
        cent = u;
}

inline int Min(int x, int y)
{
    return (x < y ? x : y);
}

void get_dis(int u, int fa)
{
    Q.push_back(Node{dis[u], dep[u]});
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v] || v == fa)
            continue;
        dis[v] = dis[u] + w[i];
        dep[v] = dep[u] + 1;
        get_dis(v, u);
    }
}

void init()
{
    ans = inf;
    for (int i = 0; i <= k; i++)
        ba[i] = inf;
}

void calc(int x)
{
    dis[x] = 0;
    dep[x] = 0;
    ba[0] = 0;
    A[++A[0]] = 0;
    for (int i = head[x]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v])
            continue;
        dep[v] = 1;
        dis[v] = w[i];
        get_dis(v, x);
        for (auto To : Q)
        {
            int tmp = k - To.x;
            if (0 <= tmp && tmp <= k)
                ans = Min(ans, ba[tmp] + To.y);
        }
        for (auto To : Q)
        {
            if (To.x > k)
                continue;
            if (ba[To.x] == inf)
                A[++A[0]] = To.x;
            ba[To.x] = Min(ba[To.x], To.y);
        }
        Q.clear();
    }
    for (int i = 0; i <= A[0]; i++)
    {
        ba[A[i]] = inf;
    }
    A[0] = 0;
}

void solve(int x)
{
    calc(x);
    vis[x] = 1;
    for (int i = head[x], y; i; i = nxt[i])
    {
        y = to[i];
        if (vis[y])
            continue;
        mx[cent = 0] = inf;
        tot = siz[y];
        get_cent(y, x);
        solve(cent);
    }
}

void work()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    init();
    for (int i = 1, x, y, z; i < n; i++)
    {
        cin >> x >> y >> z;
        x++, y++;
        add(x, y, z);
        add(y, x, z);
    }
    mx[cent = 0] = inf;
    tot = n;
    get_cent(1, 0);
    solve(cent);
    cout << (ans == inf ? -1 : ans) << "\n";
}

int main()
{
    work();
    return 0;
}
