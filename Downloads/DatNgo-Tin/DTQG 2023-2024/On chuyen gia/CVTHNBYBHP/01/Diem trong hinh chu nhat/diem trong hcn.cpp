#include <bits/stdc++.h>
using namespace std;

#define int long long

struct RECTANGLE
{
    int x1;
    int y1;
    int x2;
    int y2;

    void input(int a, int b, int c, int d)
    {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;

        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
    }
};
RECTANGLE medium;
RECTANGLE prefix[200010], suffix[200010];

int n;
int resx = 10000, resy = 10000;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    int tx1, ty1, tx2, ty2;
    for (int i = 1; i <= n + 1; ++i)
    {
        cin >> tx1 >> ty1 >> tx2 >> ty2;
        medium.input(tx1, ty1, tx2, ty2);
        prefix[i] = medium;
        suffix[i] = medium;
    }

    for (int i = 2; i <= n + 1; ++i)
    {
        prefix[i].x1 = max(prefix[i].x1, prefix[i - 1].x1);
        prefix[i].y1 = max(prefix[i].y1, prefix[i - 1].y1);
        prefix[i].x2 = min(prefix[i].x2, prefix[i - 1].x2);
        prefix[i].y2 = min(prefix[i].y2, prefix[i - 1].y2);
    }

    for (int i = n; i >= 1; --i)
    {
        suffix[i].x1 = max(suffix[i].x1, suffix[i + 1].x1);
        suffix[i].y1 = max(suffix[i].y1, suffix[i + 1].y1);
        suffix[i].x2 = min(suffix[i].x2, suffix[i + 1].x2);
        suffix[i].y2 = min(suffix[i].y2, suffix[i + 1].y2);
    }

    for (int i = 2; i <= n; ++i)
    {
        RECTANGLE intersect = {max(prefix[i - 1].x1, suffix[i + 1].x1),
                               max(prefix[i - 1].y1, suffix[i + 1].y1),
                               min(prefix[i - 1].x2, suffix[i + 1].x2),
                               min(prefix[i - 1].y2, suffix[i + 1].y2)};

        int dist_res = resx * resx + resy * resy;
        int dist_curr = intersect.x1 * intersect.x1 + intersect.y1 * intersect.y1;
        if (dist_res > dist_curr)
        {
            resx = intersect.x1;
            resy = intersect.y1;
        }
        else if (dist_res == dist_curr)
        {
            if (resx > intersect.x1)
            {
                resx = intersect.x1;
                resy = intersect.y1;
            }
        }
    }
    cout << resx << ' ' << resy << "\n\n";
    // for (int i = 1; i <= n + 1; ++i)
    // {
    //     cout << prefix[i].x1 << ' ' << prefix[i].y1 << ' ' << prefix[i].x2 << ' ' << prefix[i].y2 << '\n';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n + 1; ++i)
    // {
    //     cout << suffix[i].x1 << ' ' << suffix[i].y1 << ' ' << suffix[i].x2 << ' ' << suffix[i].y2 << '\n';
    // }
    return 0;
}