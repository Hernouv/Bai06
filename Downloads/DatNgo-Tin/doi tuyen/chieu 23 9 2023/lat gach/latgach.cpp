#include <bits/stdc++.h>
using namespace std;

const long long mod = 111539786;
struct matrx
{
    long long a[3][3];
};
matrx bs;

matrx mul_matrix(matrx &x, matrx &y)
{
    matrx ret;
    long long s;
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j)
        {
            s = 0;
            for (int k = 1; k <= 2; ++k)
                s = (s + x.a[i][k] * y.a[k][j] % mod) % mod;
            ret.a[i][j] = s;
        }
    return ret;
}

matrx pwrmod(matrx base, long long expo)
{
    if (expo == 1)
        return base;
    matrx temp = pwrmod(base, expo / 2);
    temp = mul_matrix(temp, temp);
    if (expo & 1)
        temp = mul_matrix(temp, base);
    return temp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen
    long long t;
    cin >> t;
    long long n;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        bs.a[1][1] = bs.a[1][2] = bs.a[2][1] = 1;
        bs.a[2][2] = 0;
        matrx cal = pwrmod(bs, n + 1);
        cout << cal.a[1][2] << '\n';
    }
    return 0;
}