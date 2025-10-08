#include <bits/stdc++.h>
#define int long long

const int nmax = 1e5 + 5;

using namespace std;

struct point
{
    int x, y;
} A[nmax];

int n;
vector<point> hull;

int cross(point a, point b, point c) { return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y); }
int ccw(point a, point b, point c)
{
    int s = cross(a, b, c);
    if (s < 0)
        return -1;
    if (s == 0)
        return 0;
    return 1;
}

void make_convex()
{
    hull.push_back(A[0]);
    for (int i = 1; i <= n + 1; i++)
    {
        while (hull.size() >= 2 and ccw(hull[hull.size() - 2], hull[hull.size() - 1], A[i]) > 0)
            hull.pop_back();
        hull.push_back(A[i]);
    }
}

int bs(int i)
{
    int l = 0, r = hull.size() - 1, res = hull.size();

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (hull[mid].x >= A[i].x)
        {
            r = mid - 1;
            res = mid;
        }
        else
            l = mid + 1;
    }

    return res;
}

int cal(int i, int j)
{
    point M = hull[j - 1], N = hull[j];
    int a = M.y - N.y,
        b = N.x - M.x,
        c = M.x * N.y - M.y * N.x;

    int res = ((-1) * c - a * i) / (b);

    return res;
}

void not_main()
{
    cin >> n;
    A[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        A[i].x = i;
        cin >> A[i].y;
        A[i].y *= 100000;
    }
    A[n + 1] = {n + 1, 0};

    make_convex();

    for (int i = 1; i <= n; i++)
    {
        int j = bs(i);
        int res = cal(i, j);
        cout << res << '\n';
    }
}

int32_t main()
{

    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}