#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second

const int nmax = 2e5 + 5;

int n, m, s, k;
ll a[nmax];
int visited[nmax];
vector<ill> graph[nmax];

struct edge
{
    int v1, v2;
    ll w;
    bool operator<(const edge &other) const
    {
        return (w > other.w);
    }
};

ll energy_sum = 0;
priority_queue<edge, vector<edge>> pq;
void traverse()
{
    visited[s] = 1;
    energy_sum += a[s];

    for (ill v : graph[s])
        pq.push({s, v.fi, v.se});

    while (!pq.empty())
    {
        edge e = pq.top();
        pq.pop();

        if (!visited[e.v2] and e.w <= energy_sum)
        {
            visited[e.v2] = 1;
            energy_sum += a[e.v2];
            for (ill v : graph[e.v2])
                if (!visited[v.fi])
                    pq.push({e.v2, v.fi, v.se});
        }
    }
}

int ans2 = 0;
queue<int> q;
void traverse2(int num)
{
    int t_ans = 0;
    while (!q.empty())
    {
        int V = q.front();
        q.pop();
        if (visited[V] != num)
            ++t_ans;
        visited[V] = num;

        for (ill v : graph[V])
            if (visited[v.fi] != 1 and visited[v.fi] != num and v.se <= energy_sum)
                q.push(v.fi);
    }
    ans2 = max(ans2, t_ans);
}

void not_main()
{
    cin >> n >> m >> s >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1, tu, tv, tw; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].push_back({tv, (ll)tw});
        graph[tv].push_back({tu, (ll)tw});
    }
    traverse();

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (visited[i] == 1)
            ++ans;

    if (k == 0)
    {
        cout << ans;
        return;
    }

    int it = 2;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 1)
            for (ill v : graph[i])
            {
                if (!visited[v.fi])
                {
                    q.push(v.fi);
                    traverse2(it++);
                }
            }
    }

    cout << ans + ans2;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}