#include <bits/stdc++.h>
using namespace std;

float length(int xa, int xb, int ya, int yb)
{
    return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}

float area(float a, float b, float c)
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    int x[5],y[5];
    for (int i = 1; i <= 4; ++i)
        cin >> x[i] >> y[i];
    float sub[4], main[4], s[5];
    sub[1] = length(x[1],x[4],y[1],y[4]);
    sub[2] = length(x[2],x[4],y[2],y[4]);
    sub[3] = length(x[3],x[4],y[3],y[4]);
    main[1] = length(x[1],x[2],y[1],y[2]);
    main[2] = length(x[2],x[3],y[2],y[3]);
    main[3] = length(x[1],x[3],y[1],y[3]);
    s[1] = area(sub[1], sub[2], main[1]);
    s[2] = area(sub[2], sub[3], main[2]);
    s[3] = area(sub[3], sub[1], main[3]);
    s[4] = area(main[1], main[2], main[3]);
    if (s[1] + s[2] + s[3] - s[4] <= abs(0.01)) cout << "IN";
    else cout << "OUT";
    return 0;
}
