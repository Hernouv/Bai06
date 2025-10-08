#include <bits/stdc++.h>
using namespace std;

long long r[3];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("DIV3.INP", "r", stdin);
    freopen("DIV3.OUT", "w", stdout);
    r[0] = r[1] = r[2] = 0;
    int n, inp;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> inp;
        r[inp % 3]++;
    }
    cout << (r[0] * (r[0] - 1) / 2) + r[1] * r[2];
    return 0;
}