#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int main()
{
    float a, b;
    cin >> a >> b;
    cout << "Tong: " << fixed << setprecision(10) << float(a+b) << endl;
    cout << "Hieu: " << fixed << setprecision(10) << float(a-b) << endl;
    cout << "Tich: " << fixed << setprecision(10) << float(a*b) << endl;
    cout << "Thuong " << fixed << setprecision(10) << float(a/b);
    return 0;
}
