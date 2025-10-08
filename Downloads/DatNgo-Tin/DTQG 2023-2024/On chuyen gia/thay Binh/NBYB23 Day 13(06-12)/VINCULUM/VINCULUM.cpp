/**
 *  Created at 08:15, Wednesday December 06, 2023
 *  By ms24 <3
 */
// #pragma GCC optimize("Ofast,02,unroll-loops")
// #pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define task "VINCULUM"
#define double long double
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

const int N = 1e6 + 7;

struct Point
{
    int x, y;

    Point() = default;
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &other)
    {
        return x == other.x && y == other.y;
    }
    friend istream &operator>>(istream &inp, Point &A)
    {
        inp >> A.x >> A.y;
        return inp;
    }
    friend ostream &operator<<(ostream &out, const Point &A)
    {
        out << A.x << ' ' << A.y;
        return out;
    }
};

long long cross(const Point &A, const Point &B, const Point &C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y);
}

int ccw(const Point &A, const Point &B, const Point &C)
{
    long long S = cross(A, B, C);
    if (S < 0)
        return -1;
    if (S == 0)
        return 0;
    return 1;
}

vector<Point> init(vector<Point> p)
{
    for (int i = 1; i < p.size(); ++i)
    {
        if (p[0].y > p[i].y || (p[0].y == p[i].y && p[0].x > p[i].x))
        {
            swap(p[0], p[i]);
        }
    }

    sort(p.begin() + 1, p.end(), [&p](const Point &A, const Point &B)
         {
        int c = ccw(p[0], A, B);
        if (c > 0) return true;
        if (c < 0) return false;
        return A.x < B.x || (A.x == B.x && A.y < B.y); });
    p.resize(unique(all(p)) - p.begin());

    vector<Point> hull;
    hull.push_back(p[0]);

    for (int i = 1; i < p.size(); ++i)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i]) < 0)
        {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    return hull;
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void ttk32()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (Point &x : p)
        cin >> x;

    p = init(p);
    vector<Point> tmp;

    for (const Point &it : p)
    {
        For(i, 0, 3) tmp.pb(Point(it.x + dx[i], it.y + dy[i]));
    }
    p = init(tmp);
    p.pb(p[0]);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < p.size() - 1; ++i)
    {
        Point A = p[i], B = p[i + 1];
        int x = abs(A.x - B.x), y = abs(A.y - B.y);
        if (x < y)
            swap(x, y);
        cnt1 += x - y;
        cnt2 += y;
    }
    // cerr << cnt1 << ' ' << cnt2 << '\n';
    // cout << (double)cnt1 + (double)cnt2 * 1.414;
    cout << fixed << setprecision(3) << (double)cnt1 + (double)cnt2 * 1.414213562;
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