#include <bits/stdc++.h>
using namespace std;

float length(int a, int b, int c, int d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
    freopen("bai30.INP","r",stdin);
    freopen("bai30.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    float s1, s2, s3;
    s1 = length(x1, y1, x2, y2);
    s2 = length(x2, y2, x3, y3);
    s3 = length(x3, y3, x1, y1);
    if ((s1 + s2 > s3) and (s1 + s3 > s2) and (s2 + s3 > s1))
    {
        float p = (s1 + s2 + s3)/2;
        cout << setprecision(3) << sqrt(p*(p-s1)*(p-s2)*(p-s3));
    }
    else
        cout << "NONE";
    return 0;
}
