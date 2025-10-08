#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

struct loct
{
    int x, y;
};

loct p1, p2, p3, p4;
ii vect1, vect2;

int find_gcd(int a, int b)
{
    while (a and b)
    {
        if (a < b)
            swap(a, b);
        a %= b;
    }
    return max(a, b);
}

bool three_points_straight()
{
    int t1, t2;
    bool ret1, ret2;

    t1 = (p1.y - p2.y) * (p2.x - p3.x) - (p2.y - p3.y) * (p1.x - p2.x);
    t2 = (p1.y - p2.y) * (p2.x - p4.x) - (p2.y - p4.y) * (p1.x - p2.x);

    ret1 = (t1 == 0 and p1.x <= p3.x and p3.x <= p2.x);
    ret2 = (t2 == 0 and p1.x <= p4.x and p4.x <= p2.x);

    if (ret1 or ret2)
        return true;

    t1 = (p3.y - p4.y) * (p4.x - p1.x) - (p4.y - p1.y) * (p3.x - p4.x);
    t2 = (p3.y - p4.y) * (p4.x - p2.x) - (p4.y - p2.y) * (p3.x - p4.x);

    ret1 = (t1 == 0 and p3.x <= p1.x and p1.x <= p4.x);
    ret2 = (t2 == 0 and p3.x <= p2.x and p2.x <= p4.x);

    if (ret1 or ret2)
        return true;

    return false;
}

bool c_cw(loct A, loct B, loct C)
{
    int t = (A.y - B.y) * (B.x - C.x) - (B.y - C.y) * (A.x - B.x);
    if (t < 0)
        return true;
    return false;
}

void not_main()
{
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    if (p1.x > p2.x)
        swap(p1, p2);
    if (p3.x > p4.x)
        swap(p3, p4);

    if (three_points_straight())
    {
        cout << "YES\n";
        return;
    }

    bool t1 = c_cw(p1, p2, p3), t2 = c_cw(p1, p2, p4);
    bool t3 = c_cw(p3, p4, p1), t4 = c_cw(p3, p4, p2);
    if ((!t1 == t2) and (!t3 == t4))
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("INTERSECT.INP", "r"))
    {
        freopen("INTERSECT.INP", "r", stdin);
        freopen("INTERSECT.OUT", "w", stdout);
    }

    int T;
    cin >> T;
    while (T--)
        not_main();
    return 0;
}