#include <bits/stdc++.h>
#define MASK(k) (1LL << (k))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
// #define int long long
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whole(a) a.begin(), a.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mirai ""
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int MAX = 1005;
const int MOD = 1e9 + 7;
using namespace std;
int n, m, k, xp, yp, f[MAX][MAX][3], d[MAX][MAX];
int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[] = {-1, 1, -2, 2, 1, -1, 2, -2};
queue<pair<pii, int>> q;
bool isvalid(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}
void process()
{
    cin >> n >> m >> k;
    if (k == 1)
    {
        cin >> xp >> yp;
        For(i, 1, k)
        {
            int x, y;
            cin >> x >> y;
            q.push({{x, y}, 0});
        }
        memset(f, 0x3f, sizeof(f));
        while (!q.empty())
        {
            int x = q.front().fi.fi, y = q.front().fi.se, v = q.front().se;
            q.pop();
            if (v % 2 == 0)
            {
                if (!minimize(f[x][y][2], v))
                    continue;
            }
            else if (!minimize(f[x][y][1], v))
                continue;
            For(i, 0, 7)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (isvalid(newx, newy))
                    q.push({{newx, newy}, v + 1});
            }
        }
        // For(i, 1, n){
        //     For(j, 1, m) cout << i << " " << j << " " << f[i][j][1] << " " << f[i][j][2] << endl;
        // }

        int cnt = 0;
        For(j, 1, 100000)
        {
            int tmp = xp;
            For(i, tmp + 1, n)
            {
                ++cnt;
                if (cnt % 2 == 0)
                {
                    if (f[i][yp][2] <= cnt)
                    {
                        cout << cnt;
                        return;
                    }
                }
                else if (f[i][yp][1] <= cnt)
                {
                    cout << cnt;
                    return;
                }
                xp = i;
            }
            Fod(i, n - 1, 1)
            {
                ++cnt;
                if (cnt % 2 == 0)
                {
                    if (f[i][yp][2] <= cnt)
                    {
                        cout << cnt;
                        return;
                    }
                }
                else if (f[i][yp][1] <= cnt)
                {
                    cout << cnt;
                    return;
                }
                xp = i;
            }
        }
        cout << -1;
    }
    else
    {
        cin >> xp >> yp;
        For(i, 1, k)
        {
            int x, y;
            cin >> x >> y;
            q.push({{x, y}, 0});
        }
        memset(d, 0x3f, sizeof(d));
        while (!q.empty())
        {
            int x = q.front().fi.fi, y = q.front().fi.se, v = q.front().se;
            q.pop();
            if (!minimize(d[x][y], v))
                continue;
            if (d[x][y] == 0)
                d[x][y] = INF;
            For(i, 0, 7)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (isvalid(newx, newy))
                    q.push({{newx, newy}, v + 1});
            }
        }
        // For(i, 1, n){
        //     For(j, 1, m) cout << d[i][j] << " ";
        //     cout << endl;
        // }
        int res = -1, cnt = 0;
        For(j, 1, 100000)
        {
            int tmp = xp;
            For(i, tmp + 1, n)
            {
                ++cnt;
                if (d[i][yp] <= cnt)
                {
                    cout << cnt;
                    return;
                }
                xp = i;
            }
            Fod(i, n - 1, 1)
            {
                ++cnt;
                if (d[i][yp] <= cnt)
                {
                    cout << cnt;
                    return;
                }
                // cout << i << " "<< cnt << " " << f[i][yp] << endl;
                xp = i;
            }
        }
        cout << res;
    }
}
signed main()
{
    fastio if (fopen(mirai ".inp", "r"))
    {
        freopen(mirai ".inp", "r", stdin);
        freopen(mirai ".out", "w", stdout);
    }
    int Test = 1;
    while (Test--)
    {
        process();
    }
    return 0;
}