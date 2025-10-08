#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int n, m, Q;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int dir_map[128];

int get_cost(int wind_dir, int move_dir)
{
    if (wind_dir == move_dir)
        return 1;
    else if ((wind_dir + 2) % 4 == move_dir)
        return 3;
    else
        return 2;
}

void dial(int sx, int sy, int tx, int ty)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = INF;

    const int MAX_D = 1800;
    vector<pair<int, int>> buckets[MAX_D + 1];

    dist[sx][sy] = 0;
    buckets[0].emplace_back(sx, sy);

    int idx = 0;
    while (idx <= MAX_D)
    {
        while (!buckets[idx].empty())
        {
            auto u = buckets[idx].back();
            buckets[idx].pop_back();

            int ux = u.first, uy = u.second;
            if (dist[ux][uy] < idx)
                continue;

            if (ux == tx && uy == ty)
            {
                cout << dist[ux][uy] << endl;
                return;
            }

            int wind_dir = dir_map[grid[ux][uy]];

            for (int k = 0; k < 4; ++k)
            {
                int nx = ux + dx[k];
                int ny = uy + dy[k];

                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;

                int move_dir = k;
                int cost = get_cost(wind_dir, move_dir);

                if (dist[nx][ny] > dist[ux][uy] + cost)
                {
                    int nd = dist[ux][uy] + cost;
                    dist[nx][ny] = nd;
                    if (nd <= MAX_D)
                        buckets[nd].emplace_back(nx, ny);
                }
            }
        }
        idx++;
    }
    cout << dist[tx][ty] << endl;
}

void solve()
{
    dir_map['E'] = 0;
    dir_map['N'] = 1;
    dir_map['W'] = 2;
    dir_map['S'] = 3;

    cin >> n >> m >> Q;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            grid[i][j] = s[j - 1];
        }
    }

    while (Q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        dial(x1, y1, x2, y2);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}