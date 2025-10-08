#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

int n;
vector<Point> hull;
vector<Point> p;

inline bool customSort(const Point &A, const Point &B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}

bool ccw(const Point &A, const Point &B, const Point &C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}

void convexHull(vector<Point> p, int n)
{

    sort(p.begin(), p.end(), customSort);

    hull.push_back(p[0]);

    for (int i = 1; i < n; ++i)
    {
        while (hull.size() >= 2 and ccw(hull[hull.size() - 2], hull.back(), p[i]))
            hull.pop_back();
        hull.push_back(p[i]);
    }

    for (int i = n - 2; i >= 0; --i)
    {
        while (hull.size() >= 2 and ccw(hull[hull.size() - 2], hull.back(), p[i]))
        {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    if (n > 1)
        hull.pop_back();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CONVEX.INP", "r"))
    {
        freopen("CONVEX.INP", "r", stdin);
        freopen("CONVEX.OUT", "w", stdout);
    }
    cin >> n;
    double tx, ty;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tx >> ty;
        p.push_back({tx, ty});
    }
    convexHull(p, n);
    hull.push_back(hull[0]);

    double res = 0.0;
    for (int i = 0; i < hull.size() - 1; ++i)
    {
        double d1 = (hull[i + 1].x - hull[i].x);
        double d2 = (hull[i + 1].y - hull[i].y);
        res += (double)sqrt(d1 * d1 + d2 * d2);
    }
    cout << fixed << setprecision(2) << res;

    return 0;
}