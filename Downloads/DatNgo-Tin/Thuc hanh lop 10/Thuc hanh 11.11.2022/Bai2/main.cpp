#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    float a, b;
    cin >> a >> b;
    cout << "Chu vi: " << fixed << setprecision(10) << float((a+b)*2) << endl;
    cout << "Dien tich: " << fixed << setprecision(10) << float(a*b);
    return 0;
}
