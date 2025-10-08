#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

const int N = 1e6 + 5;
const int inf = 1e9 + 5e8;

int n, m;
char x;
vector<char> a[N];
vector<int> dist[N];
deque<iii> q;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, 1, -1, -1, 0, 1};

int BFS01()
{
    while (!q.empty())
    {
        int val = q.front().fi;
        int u = q.front().se.fi;
        int v = q.front().se.se;
        q.pop_front();
        if (u == 1 || v == m)
            return dist[u][v];
        for (int s = 0; s < 8; ++s)
        {
            int x = u + dx[s];
            int y = v + dy[s];
            if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] != '@' && dist[x][y] > dist[u][v] + (a[x][y] == '#'))
            {
                if (a[x][y] == '.')
                    q.push_back(iii(dist[x][y] = dist[u][v] + (a[x][y] == '.'), ii(x, y)));
                else
                    q.push_front(iii(dist[x][y] = dist[u][v] + (a[x][y] == '.'), ii(x, y)));
            }
        }
    }
    return -1;
}

void not_main()
{
    q.clear();
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        dist[i].clear();
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (j == 1)
            {
                a[i].pb('@');
                dist[i].pb(0);
            }
            cin >> x;
            a[i].pb(x);
            dist[i].pb(inf);
        }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i][1] == '.')
        {
            dist[i][1] = 1;
            q.push_back(iii(1, ii(i, 1)));
        }
        else if (a[i][1] == '#')
        {
            dist[i][1] = 0;
            q.push_front(iii(0, ii(i, 1)));
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (a[n][i] == '.')
        {
            dist[n][i] = 1;
            q.push_back(iii(1, ii(n, i)));
        }
        else if (a[n][i] == '#')
        {
            dist[n][i] = 0;
            q.push_front(iii(0, ii(n, i)));
        }
    }
    cout << BFS01() << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (cin >> n >> m)
    {
        if (!n and !m)
            break;
        not_main();
    }
    return 0;
}