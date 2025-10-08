#include <bits/stdc++.h>
using namespace std;

float dist(float a, float b, float c, float d)
{
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main()
{
    freopen("Bai7.INP","r",stdin);
    freopen("Bai7.OUT","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    float x[3], y[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    cout << setprecision(4) << "d_AB = " << dist(x[0], y[0], x[1], y[1]) << '\n';
    cout << setprecision(4) << "d_BC = " << dist(x[1], y[1], x[2], y[2]) << '\n';
    cout << setprecision(4) << "d_AC = " << dist(x[2], y[2], x[0], y[0]) << '\n';
    return 0;
}
