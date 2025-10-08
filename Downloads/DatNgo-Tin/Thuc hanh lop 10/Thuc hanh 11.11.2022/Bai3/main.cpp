#include <bits/stdc++.h>
using namespace std;

#define pi 3.1415926535897932384626433832795
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    float r;
    cin >> r;
    cout << "Chu vi hinh tron: " << fixed << setprecision(10) << float(2*r*pi) << endl;
    cout << "Dien tich hinh tron: " << fixed << setprecision(10) << float(r*r*pi) << endl;
    return 0;
}
