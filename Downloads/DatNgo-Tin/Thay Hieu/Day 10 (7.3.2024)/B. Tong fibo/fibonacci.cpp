#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll N;

struct matrx1
{
    ll a[3][3];
} matrix_coeff_base;

struct matrx2
{
    ll b[3][1];
} matrix_base;

void initialize()
{
    matrix_base.b[0][0] = 4;
    matrix_base.b[1][0] = 2;
    matrix_base.b[2][0] = 1;

    matrix_coeff_base.a[0][0] = 2;
    matrix_coeff_base.a[0][1] = 0;
    matrix_coeff_base.a[0][2] = -1;
    matrix_coeff_base.a[1][0] = 1;
    matrix_coeff_base.a[1][1] = 0;
    matrix_coeff_base.a[1][2] = 0;
    matrix_coeff_base.a[2][0] = 0;
    matrix_coeff_base.a[2][1] = 1;
    matrix_coeff_base.a[2][2] = 0;
}

matrx1 pwrmod_mul(matrx1 m1, matrx1 m2)
{
    matrx1 ret;
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j <= 2; ++j)
        {
            ll s = 0;
            for (int k = 0; k <= 2; ++k)
            {
                s = (s + (m1.a[i][k]) * (m2.a[k][j]) % mod) % mod;
                if (s < 0)
                    s += mod;
            }
            ret.a[i][j] = s;
        }
    return ret;
}

matrx1 pwrmod(matrx1 base, ll expo)
{
    if (expo == 1)
        return base;
    matrx1 t = pwrmod(base, expo / 2);
    t = pwrmod_mul(t, t);
    if (expo % 2)
        t = pwrmod_mul(t, base);
    return t;
}

matrx2 mul(matrx1 m1, matrx2 m2)
{
    matrx2 ret;
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j <= 0; ++j)
        {
            ll s = 0;
            for (int k = 0; k <= 2; ++k)
            {
                s = (s + (m1.a[i][k]) * (m2.b[k][j]) % mod) % mod;
                if (s < 0)
                    s += mod;
            }
            ret.b[i][j] = s;
        }
    return ret;
}

void not_main()
{
    initialize();
    cin >> N;
    if (N <= 2)
    {
        cout << matrix_base.b[2 - N][0];
        return;
    }
    matrx1 matrix_coeff = pwrmod(matrix_coeff_base, N - 2);
    matrx2 res = mul(matrix_coeff, matrix_base);
    cout << res.b[0][0];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}