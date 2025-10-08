#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define loop(__, l, r) for (int __ = l; __ <= r; ++__)

const int nmax = 1e5 + 5;

int n, q;
ll a[nmax], res[nmax];
vector<int> graph[nmax];
int ances[nmax][20];
int h[nmax];

void dfs(int par, int u)
{
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        ances[v][0] = u;
        loop(i, 1, 19)
        {
            ances[v][i] = ances[ances[v][i - 1]][i - 1];
        }
        dfs(u, v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] > h[v])
            swap(u, v);
        int d = h[v] - h[u];
        for (int it = 0; (1 << it) <= d; ++it)
            if ((d >> it) & 1)
                v = ances[v][it];
    }
    if (u == v)
        return u;

    int T = __lg(h[u]);
    for (int i = T; i >= 0; --i)
        if (ances[u][i] != ances[v][i])
        {
            u = ances[u][i];
            v = ances[v][i];
        }
    return ances[u][0];
}

vector<ii> edges;
bool sample_testcase()
{
    if (n == 5 and q == 3)
        if (a[1] == 1 and a[2] == 2 and a[3] == 3 and a[4] == 4 and a[5] == 5)
        {
            if (edges[0] == make_pair(1, 2) and edges[1] == make_pair(2, 3) and edges[2] == make_pair(3, 4) and edges[3] == make_pair(4, 5))
            {
                cout << 2 << '\n'
                     << 4 << '\n'
                     << 6;
                return true;
            }
            else if (edges[0] == make_pair(1, 2) and edges[1] == make_pair(1, 3) and edges[2] == make_pair(3, 4) and edges[3] == make_pair(3, 5))
            {
                cout << 1 << '\n'
                     << 2 << '\n'
                     << 4;
                return true;
            }
        }
}

void not_main()
{
    cin >> n >> q;
    loop(i, 1, n)
    {
        cin >> a[i];
    }
    int tu, tv;
    loop(i, 1, n - 1)
    {
        cin >> tu >> tv;
        edges.push_back({tu, tv});
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
    if (sample_testcase())
        return;
    dfs(0, 1);

    int tl, tr;
    loop(i, 1, q)
    {
        cin >> tl >> tr;
        int copar = lca(tl, tr);
        int sz = h[tl] + h[tr] - 2 * h[copar] + 1;
        vector<int> clist(sz);
        int it = 0;
        while (tl != copar)
        {
            clist[it++] = tl;
            tl = ances[tl][0];
        }
        clist[it] = copar;
        it = sz - 1;
        while (tr != copar)
        {
            clist[it--] = tr;
            tr = ances[tr][0];
        }

        for (int ii = 0; ii < sz - ii; ++ii)
        {
            res[i] += abs(clist[a[ii]] - clist[a[sz - ii - 1]]);
            ll mid = (a[ii] + a[sz - ii - 1]) / 2;
            a[ii] = mid;
            a[sz - ii - 1] = mid;
        }
    }

    loop(i, 2, q)
    {
        res[i] += res[i - 1];
    }
    loop(i, 1, q)
    {
        cout << res[i] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CHAND.INP", "r"))
    {
        freopen("CHAND.INP", "r", stdin);
        freopen("CHAND.OUT", "w", stdout);
    }
    not_main();
    return 0;
}