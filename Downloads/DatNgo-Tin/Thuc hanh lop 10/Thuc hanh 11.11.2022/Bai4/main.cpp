#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define tab '\t'
#define pi 2*acos(0.0)

void check(float a, float b, float c)
{
    if (a > 0 and b > 0 and c > 0)
    {
        float d1 = (a + b) - c
            , d2 = (b + c) - a
            , d3 = (a + c) - b;

        if (d1 > 0 and d2 > 0 and d3 > 0)
        {
            cout << "Chu vi: " << fixed << setprecision(10) << float(a+b+c) << endl;

            float area, p1 = float((a + b + c)/2);
            area = float(sqrt(p1*(p1 - a)*(p1 - b)*(p1 - c)));
            cout << "Dien tich: " << fixed << setprecision(10) << area << endl;

            float m1 = float(sqrt((2*(a*a+b*b)-c*c)/4))
                , m2 = float(sqrt((2*(b*b+c*c)-a*a)/4))
                , m3 = float(sqrt((2*(a*a+c*c)-b*b)/4));
            cout << "Do dai duong trung tuyen: " << fixed << setprecision(10) << m1 << tab << m2 << tab << m3 << endl;

            float r = float(area/p1);
            cout << "Dien tich hinh tron noi tiep: " << fixed << setprecision(10) << float(r*r*pi) << endl;

            float R = float(a*b*c/4/area);
            cout << "Dien tich hinh tron ngoai tiep: " << fixed << setprecision(10) << float(R*R*pi) << endl;
        }
        else
            cout << "3 canh khong dung";
    }
    else
        cout << "3 canh khong dung";
}


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    float a,b,c;
    cin >> a >> b >> c;
    check(a, b, c);
    return 0;
}
