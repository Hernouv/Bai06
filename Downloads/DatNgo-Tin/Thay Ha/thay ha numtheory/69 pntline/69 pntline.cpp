#include <bits/stdc++.h>
using namespace std;

long long ExtendedEuclidAlgo(long long a, long long b, long long& x, long long& y)
{
    if (b == 0) 
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {

        long long x1, y1;
        long long gcd = ExtendedEuclidAlgo(b, a % b, x1, y1);
        x = y1;
        y = x1 - floor(a / b) * y1;
        return gcd;
    }
}


long long linearCongruence(long long A, long long B, long long N)
{
    long long res = -INT_MAX;
    A %= N;
    B %= N;

    long long u = 0, v = 0;
    long long d = ExtendedEuclidAlgo(A, N, u, v);

    long long x0 = (u * (B / d)) % N;
    if (x0 < 0)
        x0 += N;

    for (long long i = 0; i <= d - 1; i++)
        if (abs(res) > abs((x0 + i * (N / d)) % N))
            res = (x0 + i * (N / d)) % N;

    return res;
}

int main()
{
    freopen("pntline.inp", "r", stdin);
    freopen("pntline.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    long long A = 15;
    long long B = 9;
    long long N = 18;

    long long a, b, c;
    cin >> a >> b >> c;
    if (!a and !b)
    {
        if (!c) cout << 1 << ' ' << 1;
        else cout << -1;
    }
    else if (!a)
    {
        if (c % b) cout << -1;
        else cout << 1 << ' ' << (-c) / b;
    }
    else if (!b)
    {
        if (c % a) cout << -1;
        else cout << (-c) / a << ' ' << 1;
    }
    else if (abs(a) == abs(b) and abs(a) == abs(c))
    {
        cout << (!a or !c ? 0 : (-a) / c) << ' ' << 0;
    }
    else
    {
        long long r = abs(c % a);
        long long t = b * c;
        if (t > 0) r = abs(a) - r;
        long long y = linearCongruence(abs(b), r, abs(a));
        long long x = (c + b * y) / (-a);
        if (a * x + b * y != -c) cout << -1;
        else cout << x << ' ' << y;
    }
    return 0;
}
// 37x - 81y + 1074 = 0;
//x = (1074 - 81y) / -37
//1074 mod 37 = 81y mod 37 => y = 16
// 37x - 81*16 + 1074 = 0