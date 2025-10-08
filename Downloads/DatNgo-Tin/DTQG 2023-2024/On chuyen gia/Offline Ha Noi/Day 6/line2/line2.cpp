#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>

const int outbound = 1e4 + 4;

const int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1};
const int dy[] = {-1, 1, -2, 2, 1, -1, 2, -2};

using namespace std;

int n, n1, m;
vector<ii> k[110][110];
char grid[110][110];
vector<ii> knight_list;

int d[110][110], ff[53][110][110];

bool ck(int x, int y) { return (1 <= x and x <= m and 1 <= y and y <= n and grid[x][y] != '#'); }

void dijkstra(ii start)
{
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    memset(d, 0x3f, sizeof d);

    d[start.first][start.second] = 0;
    pq.emplace(0, start);

    while (pq.size())
    {
        ii u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > d[u.first][u.second])
            continue;

        for (ii v : k[u.first][u.second])
        {
            if (d[v.first][v.second] > dist_u + 1)
            {
                d[v.first][v.second] = dist_u + 1;
                pq.emplace(d[v.first][v.second], v);
            }
        }
    }
}

vector<int> graph[110];
int cod[110][110];

int dist[110], mg[110], mb[110];

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= n1; i++)
    {
        if (!mg[i])
        {
            q.push(i);
            dist[i] = 0;
        }
        else
            dist[i] = -1;
    }

    bool ans = 0;

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (!mb[v])
                ans = 1;
            else if (dist[mb[v]] < 0)
            {
                dist[mb[v]] = dist[u] + 1;
                q.push(mb[v]);
            }
        }
    }

    return ans;
}

bool dfs(int u)
{
    for (int v : graph[u])
    {
        if (!mb[v])
        {
            mg[u] = v;
            mb[v] = u;
            return true;
        }
        else if (dist[mb[v]] == dist[u] + 1 and dfs(mb[v]))
        {
            mg[u] = v;
            mb[v] = u;
            return true;
        }
    }
    return false;
}

bool check(int val)
{

    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n - n1 + 1; y++)
        {
            int cnt = 0;
            for (int z = 0; z < n1; z++)
                graph[z + 1].clear();
            for (int yp = y; yp <= y + n1 - 1; yp++)
            {
                cod[x][yp] = ++cnt;
                for (int z = 0; z < n1; z++)
                    if (ff[z + 1][x][yp] <= val)
                        graph[z + 1].push_back(cod[x][yp]);
            }

            memset(mg, 0, sizeof mg);
            memset(mb, 0, sizeof mb);
            while (bfs())
                for (int i = 1; i <= n1; i++)
                    if (!mg[i])
                        dfs(i);
            int res = 0;
            for (int i = 1; i <= n1; i++)
                if (mg[i])
                    res++;

            if (res == n1)
                return true;
        }
    }

    return false;
}

void binarySearch()
{
    int l = 0, r = outbound, res = outbound + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
                knight_list.emplace_back(i, j);
        }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int z = 0; z < 8; z++)
                if (ck(i + dx[z], j + dy[z]))
                    k[i][j].emplace_back(i + dx[z], j + dy[z]);

    n1 = knight_list.size();
    for (int z = 0; z < n1; z++)
    {
        dijkstra(knight_list[z]);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                ff[z + 1][i][j] = d[i][j];
    }
    binarySearch();
    return 0;
}