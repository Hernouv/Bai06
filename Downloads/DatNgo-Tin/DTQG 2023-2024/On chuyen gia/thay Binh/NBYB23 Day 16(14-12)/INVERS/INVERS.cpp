#include <bits/stdc++.h>
using namespace std;

#define task "DISPLAY"
#define ll long long
#define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e3 + 7;

int n, m, A, B, k, ans = 0;
int a[N][N];

struct BIT
{
    int bit[N][N];

    void update(int x, int y, int val)
    {
        for (int i = x + 1; i < N; i += -i & i)
        {
            for (int j = y + 1; j < N; j += -j & j)
            {
                bit[i][j] += val;
            }
        }
    }

    int get(int x, int y)
    {
        int ans = 0;
        for (int i = x + 1; i > 0; i -= -i & i)
        {
            for (int j = y + 1; j > 0; j -= -j & j)
            {
                ans += bit[i][j];
            }
        }
        return ans;
    }
} bit;

void update(int x1, int y1, int x2, int y2, int val)
{
    bit.update(x1, y1, val);
    bit.update(x1, y2 + 1, -val);
    bit.update(x2 + 1, y1, -val);
    bit.update(x2 + 1, y2 + 1, val);
}

void ttk32()
{
    cin >> n >> m >> A >> B >> k;
    For(i, 1, n)
    {
        For(j, 1, m)
        {
            cin >> a[i][j];
        }
    }
    For(i, 1, n - A + 1)
    {
        For(j, 1, m - B + 1)
        {
            int x = (a[i][j] + bit.get(i, j)) % k;
            if (x % k == 0)
                continue;
            int y = k - x;
            update(i, j, i + A - 1, j + B - 1, y);
            ans += y;
        }
    }
    For(i, 1, n)
    {
        For(j, 1, m)
        {
            if ((a[i][j] + bit.get(i, j)) % k != 0)
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int ntest = 1;
    // cin >> ntest;
    while (ntest--)
        ttk32();
    // cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
    return 0;
}