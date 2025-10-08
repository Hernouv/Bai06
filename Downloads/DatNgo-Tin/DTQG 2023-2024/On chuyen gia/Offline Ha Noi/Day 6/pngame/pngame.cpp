#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long

#define all(v) v.begin(), v.end()
#define create_unique(vec) \
    sort(all(vec));        \
    vec.resize(unique(all(vec)) - vec.begin());
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)
#define REPD(i, n) for (int i = (n); i >= 1; i--)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

#define endl '\n'
#define db(val) "[" #val " = " << (val) << "] "
#ifdef LOCAL_DEBUG
#define clog cerr
#else
#define clog \
    if (0)   \
    cerr
#endif

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

using pii = pair<int, int>;

const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

const int MAXN = 100 + 10;
const int MAXPOS = 1e4 + 10;
const int inf = 1e14 + 10;

struct Ngua
{
    int id, x, y;

    friend bool operator<(Ngua a, Ngua b)
    {
        if (a.x == b.x)
            a.y < b.y;
        return a.x < b.x;
    }
};

int n, m;

char tab[MAXN][MAXN];

vector<Ngua> knights;
int dist[60][MAXN][MAXN];

void calc_dist()
{
    FOR(id, 0, 51)
    FOR(i, 0, MAXN - 1)
    FOR(j, 0, MAXN - 1) dist[id][i][j] = inf;

    using T = pair<ll, Ngua>; // <dist, node>
    priority_queue<T, vector<T>, greater<T>> pq;

    for (auto &e : knights)
    {
        dist[e.id][e.x][e.y] = 0;
        pq.push({0LL, e});
    }

    while (!pq.empty())
    {
        const auto [d, p] = pq.top();
        auto [id, x, y] = p;
        pq.pop();
        if (d != dist[id][x][y])
        {
            continue;
        }

        FOR(i, 0, 7)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (u <= 0 || v <= 0 || u > n || v > m)
                continue;
            if (tab[u][v] == '#')
                continue;

            if (dist[id][u][v] > dist[id][x][y] + 1)
            {
                dist[id][u][v] = dist[id][x][y] + 1;
                pq.push({dist[id][u][v], Ngua{id, u, v}});
            }
        }
    }
}

unordered_map<int, vector<int>> g;
unordered_map<int, bool> used;
unordered_map<int, int> mt;

bool match(int u)
{
    if (used[u])
        return 0;
    used[u] = 1;

    for (int v : g[u])
        if (mt[v] == 0 || match(mt[v]))
        {
            mt[v] = u;
            return 1;
        }

    return 0;
}

int conv(int x, int y)
{
    return (x - 1) * m + y;
}

void solve()
{
    cin >> n >> m;

    int so_ngua = 0;
    REP(i, n)
    REP(j, m)
    {
        cin >> tab[i][j];
        if (tab[i][j] == 'M')
        {
            so_ngua++;
            knights.push_back({so_ngua, i, j});
        }
    }

    calc_dist();

    auto check_ngang = [&](int e, int x, int y)
    {
        FOR(i0, y, y + so_ngua - 1)
        if (tab[x][i0] == '#')
            return false;

        g.clear();
        mt.clear();

        int cnt = 0;

        FOR(h, 0, so_ngua - 1)
        FOR(i0, y, y + so_ngua - 1)
        {
            int id = knights[h].id;
            int posk = conv(knights[h].x, knights[h].y);

            if (dist[id][x][i0] <= e)
            {
                g[posk].push_back(conv(x, i0));
            }
        }

        for (auto &[i, v] : g)
        {
            used.clear();
            if (match(i))
                cnt++;
        }

        return cnt >= so_ngua;
    };

    int ans = inf;
    FOR(x, 1, n)
    REP(y, m)
    {
        if (y + so_ngua - 1 <= m)
        {
            int lo = 0, hi = 500;
            int cur = inf;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (check_ngang(mid, x, y))
                {
                    cur = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }

            ckmin(ans, cur);
        }
    }

    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}