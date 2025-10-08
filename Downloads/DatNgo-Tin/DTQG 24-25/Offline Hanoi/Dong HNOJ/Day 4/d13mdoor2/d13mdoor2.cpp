#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 4e4 + 5;
const ll inf = 1e18;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
ll res = 0;
ii st;
vector<vector<int>> c;
vector<vector<ll>> dist;

struct node
{
    ii coord;
    ll pdist;

    bool operator<(const node &other) const
    {
        return (pdist > other.pdist);
    }
};
priority_queue<node> pq;

void dijkstra()
{
    dist[st.fi][st.se] = 0;
    pq.push({st, 0});

    while (!pq.empty())
    {
        ii Vc = pq.top().coord;
        ll Vpd = pq.top().pdist;
        pq.pop();

        if (Vpd > dist[Vc.fi][Vc.se])
            continue;

        if (!c[Vc.fi][Vc.se])
        {
            dist[Vc.fi][Vc.se] = 0;
            res += Vpd;
        }

        for (int i = 0; i < 4; ++i)
        {
            int x = Vc.fi + dx[i];
            int y = Vc.se + dy[i];

            if (x < 1 or x > m or y < 1 or y > n)
                continue;

            if (minimize(dist[x][y], dist[Vc.fi][Vc.se] + c[x][y]))
                pq.push({{x, y}, dist[x][y]});
        }
    }
}

void not_main()
{
    cin >> m >> n;
    c.resize(m + 5, vector<int>(n + 5, 0));
    dist.resize(m + 5, vector<ll>(n + 5, inf));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (!c[i][j])
            {
                st = {i, j};
                break;
                break;
            }

    dijkstra();
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}