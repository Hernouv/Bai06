// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define TASK "lmeo"
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

const int NMAX = 1e3 + 5;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, d;
int d1[NMAX][NMAX], d2[NMAX][NMAX];
bool check[NMAX][NMAX], notrock[NMAX][NMAX];

bool isvalid(pair<int, int> x)
{
    return (x.first >= 0 && x.first < n && x.second >= 0 && x.second < n);
}

signed main()
{
    fastio;
    init();
    cin >> n >> d;
    vector<pair<int, int>> robots, rocks;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '#')
            {
                notrock[i][j] = false;
                rocks.push_back({i, j});
            }
            else
                notrock[i][j] = true;
            if (s[j] == 'S')
                robots.push_back({i, j});
            d1[i][j] = -1;
            d2[i][j] = -1;
            check[i][j] = false;
            int ddd = d1[i][j] + d2[i][j];
        }
    }
    vector<pair<int, int>> __que;
    for (int i = 0; i < rocks.size(); i++)
    {
        __que.push_back(rocks[i]);
        d1[rocks[i].first][rocks[i].second] = 0;
    }
    for (int i = 0; i < __que.size(); i++)
    {
        pair<int, int> now = __que[i];
        for (int j = 0; j < 4; j++)
        {
            pair<int, int> v = {now.first + dx[j], now.second + dy[j]};
            if (!isvalid(v))
                continue;
            if (d1[v.first][v.second] != -1)
                continue;
            int dv = d1[now.first][now.second] + 1;
            d1[v.first][v.second] = dv;
            __que.push_back(v);
        }
    }
    __que.clear();
    for (int i = 0; i < robots.size(); i++)
    {
        __que.push_back(robots[i]);
        d2[robots[i].first][robots[i].second] = 0;
    }
    vector<pair<int, int>> _que[n * n];
    for (int i = 0; i < __que.size(); i++)
    {
        pair<int, int> now = __que[i];
        check[now.first][now.second] = true;
        int dd = d2[now.first][now.second];
        _que[d1[now.first][now.second] - 1].push_back(now);
        if (dd >= d * d1[now.first][now.second])
            continue;
        for (int j = 0; j < 4; j++)
        {
            pair<int, int> v = {now.first + dx[j], now.second + dy[j]};
            if (!isvalid(v))
                continue;
            if (d2[v.first][v.second] != -1)
                continue;
            if (!notrock[v.first][v.second])
                continue;
            int dv = dd + 1;
            if (dv > d * d1[v.first][v.second])
                continue;
            d2[v.first][v.second] = dv;
            __que.push_back(v);
        }
    }
    vector<pair<int, int>> ___que;
    for (int i = n * n - 1; i >= 0; i--)
    {
        swap(__que, ___que);
        ___que.clear();
        for (int j = 0; j < __que.size(); j++)
        {
            pair<int, int> now = __que[j];
            for (int k = 0; k < 4; k++)
            {
                pair<int, int> v = {now.first + dx[k], now.second + dy[k]};
                if (!isvalid(v))
                    continue;
                if (check[v.first][v.second])
                    continue;
                if (!notrock[v.first][v.second])
                    continue;
                check[v.first][v.second] = true;
                ___que.push_back(v);
            }
        }
        for (int j = 0; j < _que[i].size(); j++)
            ___que.push_back(_que[i][j]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (check[i][j])
                res++;
    cout << res;
    return 0;
}