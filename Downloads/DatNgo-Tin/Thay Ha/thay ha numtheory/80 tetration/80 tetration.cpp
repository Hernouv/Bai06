#include <bits/stdc++.h>

#define ull unsigned long long
using namespace std;

ull euler_totient(ull n) 
{
    ull res = n;
    for (ull i = 2; i * i <= n; i++)
    {
        if (n % i == 0) 
        {
            res = res * (i - 1) / i;
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) res = res * (n - 1) / n;
    return res;
}

ull mpow(ull a, ull n, ull m, ull& f)
{
    if (a == 1 or !n) return 1;
    ull v = 1, x = a, z = m;
    if (x >= z) f++;
    x %= m;
    while (true) 
    {
        if (n & 1) v *= x; // n % 2 
        if (v >= z) f = 1, v %= m;
        n >>= 1; // n /= 2;
        if (!n) break;
        x = x * x;
        if (x >= z) f = 1, x %= m;
    }
    return v;
}

ull tetration(ull a, ull n, ull m, ull& f)
{
    if (a == 1) return 1;
    if (m == 1) return 0;
    if (a == 1 or !n) return 1;
    if (n == 1)
    {
        if (a >= m) f++;
        return a % m + f * m;
    }
    ull z = tetration(a, n - 1, euler_totient(m), f);
    ull r = mpow(a, z, m, f);
    return r + f * m;
}

ull tetration(ull a, ull n, ull m)
{
    ull f = 0;
    return tetration(a, n, m, f) % m;
}

int main() 
{
    //freopen("tetration.inp", "r", stdin);
    //freopen("tetration.out", "w", stdout);
    ull A, B, M;
    while (cin >> A >> B >> M)
        cout << tetration(A, B, M) << endl;
    return 0;
}