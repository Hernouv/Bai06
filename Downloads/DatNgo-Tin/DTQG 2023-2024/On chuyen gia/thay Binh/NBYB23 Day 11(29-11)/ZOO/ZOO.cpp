#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define first first
#define second second

const int N = 1e3 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, ans = 0;
char a[N][N];
bool used[N][N];
queue<ii> q[2];

bool isValid(int x, int y)
{
    return (1 <= x and x <= n and 1 <= y and y <= m and a[x][y] != '*' and !used[x][y]);
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    used[n][m] = 1;
    q[1].push({n, m});
    int op = 1;
    while (q[0].size() or q[1].size())
    {
        ++ans;
        queue<ii> &Q = q[op];
        while (Q.size())
        {
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();

            for (int i = 0; i <= 3; ++i)
            {
                int vx = ux + dx[i], vy = uy + dy[i];
                if (!isValid(vx, vy))
                    continue;
                used[vx][vy] = 1;
                q[(a[vx][vy] == a[n][m])].push({vx, vy});
            }
        }
        op ^= 1;
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}