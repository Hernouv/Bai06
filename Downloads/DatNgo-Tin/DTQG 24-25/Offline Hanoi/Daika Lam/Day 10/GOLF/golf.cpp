#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

const int nmax = 505;

int m, n, hole_cnt = 0;
int h[nmax][nmax], it;
bool hole[nmax][nmax];
ii stpos;

bool visited[nmax][nmax];
queue<ii> proc;

bool check(int val)
{
    memset(visited, false, sizeof visited);
    int cnt = 1;
    proc.push(stpos);
    visited[stpos.fi][stpos.se] = true;
    while (!proc.empty())
    {
        ii V = proc.front();
        proc.pop();
        for (int i = 0; i < 4; ++i)
        {
            int x = V.fi + dx[i];
            int y = V.se + dy[i];
            if (x >= 1 and x <= m and y >= 1 and y <= n and !visited[x][y] and abs(h[x][y] - h[V.fi][V.se]) <= val)
            {
                if (hole[x][y])
                    ++cnt;
                proc.push({x, y});
                visited[x][y] = true;
            }
        }
    }
    if (cnt == hole_cnt)
        return true;
    return false;
}
void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> h[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> hole[i][j];
            if (hole[i][j])
            {
                stpos = {i, j};
                ++hole_cnt;
            }
        }

    int l = 1, r = 1000000000;
    while (l < r)
    {
        ++it;
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("GOLF.INP", "r"))
    {
        freopen("GOLF.INP", "r", stdin);
        freopen("GOLF.OUT", "w", stdout);
    }
    not_main();
    return 0;
}