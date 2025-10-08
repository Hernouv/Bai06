#include <bits/stdc++.h>

#define rep(i, n) for (i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define INF 1 << 30

using namespace std;

struct edge
{
    int u, v, c;
} in[50005], mst[(50005)];
int matrix[505][505], par[505], rnk[505];
bool vis[505];
vector<int> adj[505];
void make_pair(int x)
{
    par[x] = x;
    rnk[x] = 0;
    adj[x].clear();
}
int find_parent(int x)
{
    if (x != par[x])
        par[x] = find_parent(par[x]);
    return par[x];
}
bool cmp(edge a, edge b)
{
    return a.c < b.c;
}

void link(int a, int b)
{
    if (rnk[a] > rnk[b])
    {
        par[b] = a;
    }
    else
    {
        par[a] = b;
        if (rnk[a] == rnk[b])
            rnk[b]++;
    }
}
void make_union(int a, int b)
{
    link(a, b);
}
int main()
{
    int n, m, i, idx = 0, ct, ans, mx = INF, mst_c = 0, j;
    cin >> n >> m;
    rep(i, m)
    {
        scanf("%d %d %d", &in[idx].u, &in[idx].v, &in[idx].c);
        idx++;
        if (idx < n - 1)
        {
            puts("-1");
            continue;
        }
        mst_c = 0;
        ct = 0;
        sort(in, in + idx, cmp);
        FOR(j, 1, n)
        make_pair(j);
        for (j = 0; j < idx && ct != n - 1; j++)
        {
            int nu = find_parent(in[j].u);
            int nv = find_parent(in[j].v);
            if (nu != nv)
            {
                in[ct++] = in[j];
                make_union(nu, nv);
                mst_c += in[j].c;
            }
        }
        idx = ct;
        if (ct != n - 1)
            printf("-1\n");
        else
        {
            printf("%d\n", mst_c);
        }
    }
}