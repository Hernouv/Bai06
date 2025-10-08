#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
using pii = pair<int, int>;

#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)

template <class T>
int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point
{
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const
    {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream &operator<<(ostream &os, P p)
    {
        return os << "(" << p.x << "," << p.y << ")";
    }

    friend istream &operator>>(istream &inp, P &p)
    {
        inp >> p.x >> p.y;
        return inp;
    }
};

typedef Point<ll> P;

bool onSegment(P s, P e, P p)
{
    return p.cross(s, e) == 0 and (s - p).dot(e - p) <= 0;
}

vector<P> convexHull(vector<P> pts)
{
    if (sz(pts) <= 1)
        return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts)
        {
            while (t >= s + 2 and h[t - 2].cross(h[t - 1], p) <= 0)
                t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 and h[0] == h[1])};
}

int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

bool inHull(const vector<P> &l, P p, bool strict = true)
{
    int a = 1, b = sz(l) - 1, r = !strict;
    if (sz(l) < 3)
        return r and onSegment(l[0], l.back(), p);
    if (sideOf(l[0], l[a], l[b]) > 0)
        swap(a, b);
    if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r)
        return false;
    while (abs(a - b) > 1)
    {
        int c = (a + b) / 2;
        (sideOf(l[0], l[c], p) > 0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b], p)) < r;
}

int query(vector<P> &p, vector<P> &hull)
{
    int cnt = 0;
    for (auto &x : p)
        cnt += inHull(hull, x, false);
    return cnt;
}

void not_main()
{
    int n;
    cin >> n;
    vector<P> red, blue;

    REP(i, n)
    {
        P x;
        cin >> x;
        blue.push_back(x);
    }
    REP(i, n)
    {
        P x;
        cin >> x;
        red.push_back(x);
    }

    auto hull_blue = convexHull(blue);
    auto hull_red = convexHull(red);

    cout << query(red, hull_blue) << " " << query(blue, hull_red) << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}