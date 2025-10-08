#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Line
{
    ll m, c;
    double intersect_x;

    bool operator<(const Line &other) const
    {
        return m < other.m;
    }
};

struct ConvexHullTrick
{
    deque<Line> hull;

    double get_intersect(const Line &a, const Line &b)
    {
        return (double)(b.c - a.c) / (a.m - b.m);
    }

    void add_line(ll m, ll c)
    {
        Line new_line = {m, c, 0};
        while (hull.size() >= 1)
        {
            Line last = hull.back();
            if (last.m == new_line.m)
            {
                if (last.c <= new_line.c)
                    return;
                else
                    hull.pop_back();
            }
            else
            {
                double x = get_intersect(last, new_line);
                if (hull.size() >= 2)
                {
                    Line second_last = hull[hull.size() - 2];
                    double x_prev = second_last.intersect_x;
                    if (x_prev >= x)
                    {
                        hull.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (!hull.empty())
        {
            hull.back().intersect_x = get_intersect(hull.back(), new_line);
        }
        hull.push_back(new_line);
    }

    ll query(ll x)
    {
        while (hull.size() >= 2 && hull[0].m * x + hull[0].c >= hull[1].m * x + hull[1].c)
        {
            hull.pop_front();
        }
        if (hull.empty())
            return INF;
        return hull[0].m * x + hull[0].c;
    }
};

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (auto &x : p)
        cin >> x;

    vector<ll> S(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        S[i] = S[i - 1] + p[i - 1];
    }

    vector<ll> dp_prev(n + 1, INF);
    dp_prev[0] = 0;

    vector<ll> dp_curr(n + 1, INF);

    for (int j = 1; j <= k; ++j)
    {
        ConvexHullTrick cht;
        cht.add_line(0, dp_prev[0] + S[0] * S[0]);
        for (int i = 1; i <= n; ++i)
        {
            if (!cht.hull.empty())
            {
                dp_curr[i] = S[i] * S[i] + cht.query(S[i]);
            }
            cht.add_line(-2 * S[i], dp_prev[i] + S[i] * S[i]);
        }
        dp_prev = dp_curr;
        fill(dp_curr.begin(), dp_curr.end(), INF);
    }

    cout << dp_prev[n];
}
