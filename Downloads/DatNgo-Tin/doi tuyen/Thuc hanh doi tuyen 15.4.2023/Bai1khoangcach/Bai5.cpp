#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Bai5.INP","r",stdin);
    freopen("Bai5.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    float l[4];
    for (int i = 0; i < 4; ++i)
        cin >> l[i];
    cout << setprecision(4) << sqrt((l[2] - l[0])*(l[2] - l[0]) + (l[3] - l[1])*(l[3] - l[1]));
    return 0;
}
