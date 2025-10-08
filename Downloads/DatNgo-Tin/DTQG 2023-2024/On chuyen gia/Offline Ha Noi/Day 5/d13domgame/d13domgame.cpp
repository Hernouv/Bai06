#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define RRH(v) v.resize(unique(all(v)) - v.begin())
const int maxN = 2e6 + 7;
const int maxM = 2e3 + 7;
const ll oo = 1e18;
const int block = 708;
const ii mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
vector<int> graph[maxN + 5], tadj[maxN + 5];
int h[maxN + 5], _h[maxN + 5], d[maxN + 5], mark[maxN + 5], a[maxM + 5][maxM + 5];
int vst[maxN + 5], NUM = 0, Time = 0;

int Encode(int i, int j)
{
    return (i - 1) * N + j;
}

bool inside(int x, int y)
{
    return (x > 0 and y > 0 and x <= N and y <= M);
}

bool Match(int i)
{
    if (d[i] == Time)
        return false;
    d[i] = Time;
    for (int j : graph[i])
    {
        if (h[j] == 0 or Match(h[j]))
        {
            h[j] = i;
            _h[i] = j;
            return true;
        }
    }
    return false;
}

void dfs(int u, int par, bool cur)
{
    if (cur)
    {
        if (vst[_h[u]] == Time)
            return;
        vst[_h[u]] = Time;
        dfs(_h[u], u, !cur);
    }
    else
    {
        ++NUM;
        for (int v : tadj[u])
        {
            if (vst[v] == Time or par == v)
                continue;
            vst[v] = Time;
            dfs(v, u, !cur);
        }
    }
}

int color[maxM + 5][maxM + 5];

void solve()
{
    cin >> N >> M;
    int white = 0;
    For(i, 1, N)
    {
        For(j, 1, M)
        {
            char c;
            cin >> c;
            if (c != '.')
                a[i][j] = 2;
        }
    }
    vector<int> black;
    For(i, 1, N)
    {
        For(j, 1, M)
        {
            if (a[i][j] == 2)
                continue;
            if (i & 1)
            {
                if (j & 1)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
            else
            {
                if (j & 1)
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
            if (a[i][j] == 0)
                ++white;
        }
    }
    For(i, 1, N)
    {
        For(j, 1, M)
        {
            if (a[i][j] != 1)
                continue;
            int u = Encode(i, j);
            black.push_back(u);
            for (int t = 0; t <= 3; ++t)
            {
                int x = i + mv[t].fi,
                    y = j + mv[t].se;
                if (!inside(x, y) or a[x][y] != 0)
                    continue;
                int v = Encode(x, y);
                graph[u].push_back(v);
                tadj[v].push_back(u);
            }
        }
    }
    int k = 0;
    for (int i : black)
    {
        ++Time;
        if (Match(i))
            ++k;
    }
    if (k >= 1000)
    {
        cout << 1000000;
        return;
    }
    int ans = k * (k - 1);
    Time = 0;
    for (int i : black)
    {
        ++Time;
        NUM = 0;
        dfs(i, 0, 1);
        ans += (white - NUM);
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}