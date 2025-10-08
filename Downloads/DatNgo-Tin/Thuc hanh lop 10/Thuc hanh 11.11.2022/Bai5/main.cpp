#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    unsigned long h, s;
    unsigned short m;
    cin >> s;
    h = s/3600;
    s = s - h*3600;
    m = s/60;
    s = s - m*60;
    cout << h << " gio : " << m << " phut : " << s << " giay";
    return 0;
}
