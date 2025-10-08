/**
 *  Created at 10:37, Friday December 01, 2023
 *  By ms24 <3
 */
// #pragma GCC optimize("Ofast,02,unroll-loops")
// #pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define task "ADDFRAC"
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
// #define cerr if (0) cerr
// #define CTIME

const int N = 1e6 + 7;

struct Tpoint
{
    int x, y;
    Tpoint(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }

    Tpoint operator+(const Tpoint &b)
    {
        return Tpoint(x + b.x, y + b.y);
    }
};

int ccw(Tpoint a, Tpoint b)
{
    return a.x * b.y - a.y * b.x;
}

Tpoint a[N], res[N];
int b[N], top = 0;

ii ok(ii a)
{
    int tmp = __gcd(a.F, a.S);
    return ii(a.F / tmp, a.S / tmp);
}

void ttk32()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        bool ok = 0;
        int tmp1 = 0, tmp2 = 0;
        for (char x : s)
        {
            if (x == '/')
            {
                ok = 1;
                continue;
            }

            if (!ok)
                tmp1 = (tmp1 * 10) + (x - 48);
            else
                tmp2 = (tmp2 * 10) + (x - 48);
        }
        a[i] = Tpoint(tmp2, tmp1);
    }

    top = 0;
    res[n] = a[n];
    b[++top] = n;
    res[0] = Tpoint(0, 0);

    for (int i = n - 1; i >= 1; i--)
    {
        res[i] = a[i];
        while (top > 0 && ccw(res[i], res[b[top]]) >= 0)
        {
            res[i] = res[i] + res[b[top]];
            top--;
        }
        b[++top] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int x = res[i].y, y = res[i].x;
        ii ans = ok({x, y});
        cout << ans.F << '/' << ans.S << '\n';
    }
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
    int t;
    cin >> t;
    while (t--)
        ttk32();
#ifdef CTIME
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}