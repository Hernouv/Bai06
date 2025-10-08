#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    while (x and y)
    {
        if (x > y)
            x %= y;
        else
            y %= x;
    }
    return max(x, y);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    int x, y;
    cin >> x >> y;
    int z = gcd(x, y);
    int i = 1, cnt = 0;
    while (i * i < z)
    {
        if (z % i == 0)
            cnt += 2;
        i++;
    }
    if (i * i == z)
        cnt++;
    cout << cnt;
    return 0;
}