#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

struct matrx1
{
    int a[2][2];
} matrix_coeff_base;

struct matrx2
{
    int b[2][1];
} matrix_base;

void initialize()
{
    matrix_coeff_base.a[0][0] = 1;
    matrix_coeff_base.a[0][1] = 2;
    matrix_coeff_base.a[1][0] = 1;
    matrix_coeff_base.a[1][1] = 0;
    matrix_base.b[0][0] = 1;
    matrix_base.b[1][0] = 1;
}

int T;
ll N;

matrx1 pwrmod_mul(matrx1 m1, matrx1 m2)
{
    matrx1 ret;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
        {
            ll tmp = 0;
            for (int k = 0; k <= 1; ++k)
                tmp = (tmp + (m1.a[i][k] % mod) * (m2.a[k][j] % mod) % mod) % mod;
            ret.a[i][j] = tmp;
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

matrx2 res_mul(matrx1 m1, matrx2 m2)
{
    matrx2 ret;

    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 0; ++j)
        {
            ll tmp = 0;
            for (int k = 0; k <= 1; ++k)
                tmp = (tmp + (m1.a[i][k] % mod) * (m2.b[k][j] % mod) % mod) % mod;
            ret.b[i][j] = tmp;
        }

    return ret;
}

void not_main()
{
    initialize();
    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        matrx1 matrix_coeff = pwrmod(matrix_coeff_base, N - 1);
        matrx2 res = res_mul(matrix_coeff, matrix_base);
        cout << res.b[0][0] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("tiles.inp", "r"))
    {
        freopen("tiles.inp", "r", stdin);
        freopen("tiles.out", "w", stdout);
    }
    not_main();
    return 0;
}