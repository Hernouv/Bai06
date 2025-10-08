#include <bits/stdc++.h>
using namespace std;

int x1, y1, x2, y2;
int normVect[2];
int lineEq[3];

int gcd(int a, int b)
{
    while (a and b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return max(a, b);
}

int create_normVect(int x1, int y1, int x2, int y2)
{
    int vx = x1 - x2, vy = y1 - y2;
    vx = -vx;
    swap(vx, vy);
    if (vx < 0 and vy < 0)
        vx = -vx, vy = -vy;
    if (vx == 0 and vy < 0)
        vy = -vy;
    if (vy == 0 and vx < 0)
        vx = -vx;
    int common = gcd(vx, vy);
    vx /= common, vy /= common;
    normVect[0] = vx, normVect[1] = vy;
}

bool check_sqnum()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("CIRCLES.INP", "r", stdin);
    // freopen("CIRCLES.OUT", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;
    create_normVect(x1, y1, x2, y2);
    lineEq[0] = normVect[0], lineEq[1] = normVect[1], lineEq[2] = -normVect[0] * x1 - normVect[1] * y1;
    int dist0 = (lineEq[2] * lineEq[2]) / (lineEq[0] * lineEq[0] + lineEq[1] * lineEq[1]); // dist between O and the line
    int dist1 = sqrt(abs(x1 * x1) + abs(y1 * y1));                                         // dist between O and one end of the line
    int dist2 = sqrt(abs(x2 * x2) + abs(y2 * y2));                                         // dist between O and the other end of the line

    return 0;
}
// -1 3
// x = 3y - 3