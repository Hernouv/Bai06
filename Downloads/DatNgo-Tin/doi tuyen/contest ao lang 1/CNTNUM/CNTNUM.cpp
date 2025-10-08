#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;
long long cd, cnt_c, cnt_d, cnt_cd;

long long gcd(long long c, long long d)
{
    while (c and d)
    {
        if (c > d)
            c %= d;
        else
            d %= c;
    }
    return max(c, d);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CNTNUM.INP", "r", stdin);
    freopen("CNTNUM.OUT", "w", stdout);
    cin >> a >> b >> c >> d;
    cd = c * d / gcd(c, d);
    if (a < b)
        swap(a, b);
    cnt_c = a / c - b / c - (b % c ? 1 : 0) + 1;
    cnt_d = a / d - b / d - (b % d ? 1 : 0) + 1;
    cnt_cd = a / cd - b / cd - (b % cd ? 1 : 0) + 1;
    cout << (a - b + 1) - cnt_c - cnt_d + cnt_cd;
    return 0;
}