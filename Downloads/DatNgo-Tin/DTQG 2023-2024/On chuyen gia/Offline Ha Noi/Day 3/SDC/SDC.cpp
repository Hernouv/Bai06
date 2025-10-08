#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define TASK "SDC"
#define int long long

using namespace std;

void init()
{
    if (fopen(TASK ".inp", "r"))
    {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
}

const int NMAX = 1e5 + 5;
const int INF = 1e18 + 1;

int n, m, a, b, d[NMAX];
bool inqueue[NMAX];
vector<pair<int, int>> adj[NMAX];

bool check(int s)
{
    queue<int> q;
    q.push(s);
    memset(d, 257, sizeof(d));
    inqueue[s] = 1, d[s] = 0;
    int t = n * m;
    while (q.size() && t--)
    {
        int u = q.front();
        q.pop();
        inqueue[u] = 0;
        for (auto e : adj[u])
        {
            int w = e.second;
            int v = e.first;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!inqueue[v])
                {
                    inqueue[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    for (int u = 0; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (d[v.first] > d[u] + v.second)
            {
                return false;
            }
        }
    }
    return true;
}

signed main()
{
    fastio;
    init();
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    for (int i = 1; i <= n; i++)
        adj[0].push_back({i, 0});
    if (!check(0))
    {
        cout << "NO\n";
        return 0;
    }
    int c = a - *min_element(d + 1, d + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        d[i] += c;
        if (d[i] > b || d[i] < a)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}
