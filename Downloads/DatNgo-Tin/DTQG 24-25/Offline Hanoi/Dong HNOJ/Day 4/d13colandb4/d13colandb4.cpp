#include <bits/stdc++.h>

using namespace std;

#define MASK(i) (1 << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1)

#define ll long long
#define ii pair<int, int>

const int N = 1e4 + 10;
const int sN = 105;
const int FULL = (1 << 10) + 15;
const int oo = 0x3f3f3f3f;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ROF(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)

#define nl '\n'

int n, m, q, cnt0 = 0, cnt1 = 0;
int a[sN][sN], b[N], island[20], id[sN][sN];
int sz[N], dp[FULL][N], sum[FULL], res[N];
vector<int> adj[N];

bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return 1;
    }
    return 0;
}

bool check(int nx, int ny)
{
    return nx >= 1 && nx <= m && ny >= 1 && ny <= n;
}

void bfs(int x0, int y0, int idx)
{
    queue<ii> q;
    q.push({x0, y0});
    sz[idx] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        FOR(i, 0, 3)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && !id[nx][ny] && a[nx][ny] == 1)
            {
                q.push({nx, ny});
                id[nx][ny] = idx;
                sz[idx]++;
            }
        }
    }
}

void solve()
{
    cin >> m >> n >> q;
    FOR(i, 1, m)
    {
        string s;
        cin >> s;
        FOR(j, 0, n - 1)
        a[i][j + 1] = s[j] - '0';
    }

    FOR(i, 1, m)
    FOR(j, 1, n)
    {
        if (!id[i][j])
        {
            id[i][j] = ++cnt0;
            if (a[i][j] == 1)
            {
                island[cnt1++] = cnt0;
                bfs(i, j, cnt0);
            }
        }
        b[id[i][j]] = 1 - a[i][j];
    }

    FOR(x, 1, m)
    FOR(y, 1, n)
    FOR(i, 0, 3)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && id[x][y] != id[nx][ny])
            adj[id[x][y]].push_back(id[nx][ny]);
    }

    memset(res, 0x3f, sizeof(res));
    FOR(mask, 1, MASK(cnt1) - 1)
    FOR(i, 0, cnt1 - 1)
    if (BIT(mask, i))
        sum[mask] += sz[island[i]];

    FOR(mask, 1, MASK(cnt1) - 1)
    FOR(i, 1, cnt0)
    dp[mask][i] = oo;

    FOR(i, 0, cnt1 - 1)
    dp[MASK(i)][island[i]] = 0;

    FOR(mask, 1, MASK(cnt1) - 1)
    {
        for (int _mask = (mask - 1) & mask; _mask; _mask = (_mask - 1) & mask)
        {
            FOR(i, 1, cnt0)
            minimize(dp[mask][i], dp[_mask][i] + dp[mask - _mask][i] - b[i]);
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        FOR(i, 1, cnt0)
        if (dp[mask][i] != oo)
        {
            pq.push({dp[mask][i], i});
            minimize(res[sum[mask]], dp[mask][i]);
        }
        while (!pq.empty())
        {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist > dp[mask][u])
                continue;
            for (int v : adj[u])
                if (minimize(dp[mask][v], dp[mask][u] + b[v]))
                    pq.push({dp[mask][v], v});
        }
    }
    ROF(i, m * n, 0)
    res[i] = min(res[i], res[i + 1]);

    FOR(i, 1, q)
    {
        int x;
        cin >> x;
        cout << (res[x] == oo ? -1 : res[x]) << ' ';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}