#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 5e5 + 10;
vector<int> graph[nmax];
int n, k, w[nmax];
int weightsum[nmax];
vector<ii> wlist;
int cut_no;

void dfs(int par, int u)
{
    weightsum[u] = w[u];
    for (int v : graph[u])
    {
        if (v == par)
            continue;
        dfs(u, v);
        weightsum[u] += weightsum[v];
    }
    wlist.emplace_back(weightsum[u], u);
}

struct comp
{
    bool operator()(const ii &a, const ii &b)
    {
        return (a.se < b.se);
    }
};

priority_queue<ii, vector<ii>, comp> pq;
void dfs_cut(int par, int u, int lim)
{
    int wt_total = weightsum[1];
    pq.emplace(u, weightsum[u]);
    while (!pq.empty())
    {
        ii v = pq.top();
        pq.pop();
        if (v.se > lim)
        {
            for (int vx : graph[v.fi])
            {
                if (vx == par)
                    continue;
                pq.emplace(vx, weightsum[vx]);
            }
        }
        else if (v.fi != 1)
        {
            ++cut_no;
            wt_total -= weightsum[v.fi];
            if (wt_total <= lim)
                return;
        }
    }
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 1);
    sort(wlist.begin(), wlist.end(), greater<ii>());
    int l = weightsum[1] / (k + 1), r = weightsum[1];
    int prev = 0, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (prev == mid)
            break;
        cut_no = 0;
        dfs_cut(0, 1, mid);
        if (cut_no > k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << mid;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TRCUT.INP", "r"))
    {
        freopen("TRCUT.INP", "r", stdin);
        freopen("TRCUT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}